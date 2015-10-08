//
//  GameScreenStates.h
//  nosfuratu
//
//  Created by Stephen Gowen on 9/29/15.
//  Copyright © 2015 Gowen Game Dev. All rights reserved.
//

#ifndef __nosfuratu__GameScreenStates__
#define __nosfuratu__GameScreenStates__

#include "State.h"
#include "BackButton.h"
#include "LevelEditorActionsPanel.h"
#include "LevelEditorEntitiesPanel.h"
#include "TrashCan.h"

#include <memory>

class GameScreen;

class GamePlay : public State<GameScreen>
{
public:
    static GamePlay* getInstance();
    
    virtual void enter(GameScreen* gs);
    
    virtual void execute(GameScreen* gs);
    
    virtual void exit(GameScreen* gs);
    
    void setSourceGame(Game* game);
    
private:
    std::unique_ptr<Game> m_game;
    Game* m_sourceGame;
    std::unique_ptr<BackButton> m_backButton;
    
    bool handleTouchInput(GameScreen* gs);
    
    // ctor, copy ctor, and assignment should be private in a Singleton
    GamePlay();
    GamePlay(const GamePlay&);
    GamePlay& operator=(const GamePlay&);
};

class LevelEditor : public State<GameScreen>
{
public:
    static LevelEditor* getInstance();
    
    virtual void enter(GameScreen* gs);
    
    virtual void execute(GameScreen* gs);
    
    virtual void exit(GameScreen* gs);
    
    Game& getGame();
    
private:
    std::unique_ptr<Game> m_game;
    std::unique_ptr<LevelEditorActionsPanel> m_levelEditorActionsPanel;
    std::unique_ptr<LevelEditorEntitiesPanel> m_levelEditorEntitiesPanel;
    std::unique_ptr<TrashCan> m_trashCan;
    std::vector<PhysicalEntity*> m_gameEntities;
    PhysicalEntity* m_lastAddedEntity;
    PhysicalEntity* m_draggingEntity;
    PhysicalEntity* m_attachToEntity;
    float m_fDraggingEntityOriginalY;
    bool m_isVerticalChangeAllowed;
    bool m_useYCorrection;
    bool m_allowAttachment;
    bool m_allowPlaceOn;
    
    void handleTouchInput(GameScreen* gs);
    
    void resetEntities(bool clearLastAddedEntity);
    
    // ctor, copy ctor, and assignment should be private in a Singleton
    LevelEditor();
    LevelEditor(const LevelEditor&);
    LevelEditor& operator=(const LevelEditor&);
};

#endif /* defined(__nosfuratu__GameScreenStates__) */