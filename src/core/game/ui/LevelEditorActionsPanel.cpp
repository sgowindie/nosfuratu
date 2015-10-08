//
//  LevelEditorActionsPanel.cpp
//  nosfuratu
//
//  Created by Stephen Gowen on 10/2/15.
//  Copyright © 2015 Gowen Game Dev. All rights reserved.
//

#include "LevelEditorActionsPanel.h"
#include "Rectangle.h"
#include "GameConstants.h"
#include "OverlapTester.h"

LevelEditorActionsPanel::LevelEditorActionsPanel(float x, float y, float width, float height) : PhysicalEntity(x, y, width, height), m_isOpen(false), m_isShowEntityBoundsRequested(false)
{
    m_toggleBoundsButton = std::unique_ptr<Rectangle>(new Rectangle(width * 0.09908256880734f, height * 0.87070254110613f, width * 0.68990825688073f, height * 0.08968609865471f));
    m_resetButton = std::unique_ptr<Rectangle>(new Rectangle(width * 0.09908256880734f, height * 0.38714499252616, width * 0.68990825688073f, height * 0.08968609865471f));
    m_testButton = std::unique_ptr<Rectangle>(new Rectangle(width * 0.09908256880734f, height * 0.26233183856502f, width * 0.68990825688073f, height * 0.08968609865471f));
    m_loadButton = std::unique_ptr<Rectangle>(new Rectangle(width * 0.09908256880734f, height * 0.1390134529148f, width * 0.68990825688073f, height * 0.08968609865471f));
    m_saveButton = std::unique_ptr<Rectangle>(new Rectangle(width * 0.09908256880734f, height * 0.01718983557549f, width * 0.68990825688073f, height * 0.08968609865471f));
    m_openButton = std::unique_ptr<Rectangle>(new Rectangle(width * 0, height * 0.49081920903955f, 1, 1));
    m_closeButton = std::unique_ptr<Rectangle>(new Rectangle(width * 0.83305227655987f, height * 0.49081920903955f, 1, 1));
}

int LevelEditorActionsPanel::handleTouch(TouchEvent& te, Vector2D& touchPoint)
{
    if (m_isOpen)
    {
        switch (te.getTouchType())
        {
            case UP:
            case DRAGGED:
                return LEVEL_EDITOR_ACTIONS_PANEL_RC_UNHANDLED;
            case DOWN:
                if (OverlapTester::isPointInRectangle(touchPoint, *m_toggleBoundsButton))
                {
                    m_isShowEntityBoundsRequested = !m_isShowEntityBoundsRequested;
                    
                    return LEVEL_EDITOR_ACTIONS_PANEL_RC_HANDLED;
                }
                else if (OverlapTester::isPointInRectangle(touchPoint, *m_resetButton))
                {
                    return LEVEL_EDITOR_ACTIONS_PANEL_RC_RESET;
                }
                else if (OverlapTester::isPointInRectangle(touchPoint, *m_testButton))
                {
                    return LEVEL_EDITOR_ACTIONS_PANEL_RC_TEST;
                }
                else if (OverlapTester::isPointInRectangle(touchPoint, *m_loadButton))
                {
                    return LEVEL_EDITOR_ACTIONS_PANEL_RC_LOAD;
                }
                else if (OverlapTester::isPointInRectangle(touchPoint, *m_saveButton))
                {
                    return LEVEL_EDITOR_ACTIONS_PANEL_RC_SAVE;
                }
                else if (OverlapTester::isPointInRectangle(touchPoint, *m_closeButton))
                {
                    m_position->setX(-3.76608187134503f / 2 + 0.94736842105263f);
                    
                    m_isOpen = false;
                    
                    return LEVEL_EDITOR_ACTIONS_PANEL_RC_HANDLED;
                }
        }
    }
    else
    {
        switch (te.getTouchType())
        {
            case UP:
            case DRAGGED:
                return LEVEL_EDITOR_ACTIONS_PANEL_RC_UNHANDLED;
            case DOWN:
                if (OverlapTester::isPointInRectangle(touchPoint, *m_openButton))
                {
                    m_position->setX(getWidth() / 2);
                    
                    m_isOpen = true;
                    
                    return LEVEL_EDITOR_ACTIONS_PANEL_RC_HANDLED;
                }
        }
    }
    
    return LEVEL_EDITOR_ACTIONS_PANEL_RC_UNHANDLED;
}

bool LevelEditorActionsPanel::isShowEntityBoundsRequested()
{
    return m_isShowEntityBoundsRequested;
}