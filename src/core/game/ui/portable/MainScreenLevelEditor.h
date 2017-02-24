//
//  MainScreenLevelEditor.h
//  nosfuratu
//
//  Created by Stephen Gowen on 2/10/16.
//  Copyright (c) 2016 Noctis Games. All rights reserved.
//

#ifndef __nosfuratu__MainScreenLevelEditor__
#define __nosfuratu__MainScreenLevelEditor__

#include "MainScreen.h"

#include "LevelEditorActionsPanel.h"
#include "LevelEditorEntitiesPanel.h"
#include "TrashCan.h"
#include "LevelSelectorPanel.h"
#include "OffsetPanel.h"
#include "ConfirmResetPanel.h"
#include "ConfirmExitPanel.h"
#include "RendererType.h"
#include "MainScreenState.h"
#include "RTTI.h"

#include <memory>

class MainScreenLevelEditor : public MainScreenState
{
    RTTI_DECL;
    
public:
    static MainScreenLevelEditor* getInstance();
    
    virtual void enter(MainScreen* ms);
    
    virtual void execute(MainScreen* ms);
    
    virtual void exit(MainScreen* ms);
    
    virtual void initRenderer(MainScreen* ms);
    
    const char* save();
    
    void load(const char* json, MainScreen* ms);
    
    Game& getGame();
    
    LevelEditorActionsPanel* getLevelEditorActionsPanel();
    
    LevelEditorEntitiesPanel* getLevelEditorEntitiesPanel();
    
    TrashCan* getTrashCan();
    
    LevelSelectorPanel* getLevelSelectorPanel();

	OffsetPanel* getOffsetPanel();

	ConfirmResetPanel* getConfirmResetPanel();

	ConfirmExitPanel* getConfirmExitPanel();

	void setMessage(char *message);

	char* getMessage();
    
private:
    std::unique_ptr<Game> m_game;
    std::unique_ptr<LevelEditorActionsPanel> m_levelEditorActionsPanel;
    std::unique_ptr<LevelEditorEntitiesPanel> m_levelEditorEntitiesPanel;
    std::unique_ptr<TrashCan> m_trashCan;
    std::unique_ptr<LevelSelectorPanel> m_levelSelectorPanel;
    std::unique_ptr<OffsetPanel> m_offsetPanel;
    std::unique_ptr<ConfirmResetPanel> m_confirmResetPanel;
    std::unique_ptr<ConfirmExitPanel> m_confirmExitPanel;
    std::vector<GridLockedPhysicalEntity*> m_gameEntities;
    PhysicalEntity* m_lastAddedEntity;
    GridLockedPhysicalEntity* m_draggingEntity;
    GridLockedPhysicalEntity* m_attachToEntity;
	char* m_message;
	float m_fMessageTime;
    float m_fDraggingEntityOriginalY;
    int m_iWorld;
    int m_iLevel;
	int m_iLastOffset;
    bool m_isVerticalChangeAllowed;
    bool m_allowPlaceOn;
    bool m_allowPlaceUnder;
    
    void handleInput(MainScreen* ms);
    
    void resetEntities(bool clearLastAddedEntity);
    
    void loadIfNecessary(MainScreen* ms);
    
    bool isLevelValid(MainScreen* ms);
    
    // ctor, copy ctor, and assignment should be private in a Singleton
    MainScreenLevelEditor();
    MainScreenLevelEditor(const MainScreenLevelEditor&);
    MainScreenLevelEditor& operator=(const MainScreenLevelEditor&);
};

#endif /* defined(__nosfuratu__MainScreenLevelEditor__) */