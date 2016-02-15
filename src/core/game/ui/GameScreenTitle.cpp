//
//  GameScreenTitle.cpp
//  nosfuratu
//
//  Created by Stephen Gowen on 2/10/16.
//  Copyright © 2016 Gowen Game Dev. All rights reserved.
//

#include "GameScreenTitle.h"
#include "State.h"
#include "GameScreen.h"
#include "EntityUtils.h"
#include "Vector2D.h"
#include "Game.h"
#include "GameScreenTransitions.h"

/// Title Screen ///

Title * Title::getInstance()
{
    static Title *instance = new Title();
    
    return instance;
}

void Title::enter(GameScreen* gs)
{
    gs->m_stateMachine->setPreviousState(nullptr);
    gs->m_renderer->init(RENDERER_TYPE_MENU);
}

void Title::execute(GameScreen* gs)
{
    if (gs->m_isRequestingRender)
    {
        gs->m_renderer->beginFrame();
        
        gs->m_renderer->renderTitleScreen();
        
        if (m_isRequestingNextState || m_isRequestingLevelEditor)
        {
            gs->m_renderer->renderLoadingTextOnTitleScreen();
        }
        
        gs->m_renderer->renderTitleScreenUi(*m_levelEditorButton);
        
        gs->m_renderer->renderToScreen();
        
        gs->m_renderer->endFrame();
    }
    else
    {
        if (m_isRequestingNextState)
        {
            gs->m_stateMachine->changeState(TitleToWorldMap::getInstance());
        }
        else if (m_isRequestingLevelEditor)
        {
            gs->m_stateMachine->changeState(TitleToLevelEditor::getInstance());
        }
        
        gs->processTouchEvents();
        
        for (std::vector<TouchEvent>::iterator i = gs->m_touchEvents.begin(); i != gs->m_touchEvents.end(); i++)
        {
            gs->touchToWorld((*i));
            
            switch (i->getTouchType())
            {
                case DOWN:
                    continue;
                case DRAGGED:
                    continue;
                case UP:
                    if (OverlapTester::isPointInRectangle(*gs->m_touchPoint, m_levelEditorButton->getBounds()))
                    {
                        m_isRequestingLevelEditor = true;
                    }
                    else if (gs->m_touchPoint->getY() < (CAM_HEIGHT * 2 / 3))
                    {
                        m_isRequestingNextState = true;
                    }
                    
                    return;
            }
        }
    }
}

void Title::exit(GameScreen* gs)
{
    m_isRequestingNextState = false;
    m_isRequestingLevelEditor = false;
}

LevelEditorButton& Title::getLevelEditorButton()
{
    return *m_levelEditorButton;
}

Title::Title() : m_isRequestingNextState(false), m_isRequestingLevelEditor(false)
{
    m_levelEditorButton = std::unique_ptr<LevelEditorButton>(new LevelEditorButton());
}