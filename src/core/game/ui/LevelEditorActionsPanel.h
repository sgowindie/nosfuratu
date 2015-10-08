//
//  LevelEditorActionsPanel.h
//  nosfuratu
//
//  Created by Stephen Gowen on 10/2/15.
//  Copyright © 2015 Gowen Game Dev. All rights reserved.
//

#ifndef __nosfuratu__LevelEditorActionsPanel__
#define __nosfuratu__LevelEditorActionsPanel__

#include "PhysicalEntity.h"
#include "GameConstants.h"
#include "TouchEvent.h"
#include "Vector2D.h"
#include "Rectangle.h"

#define LEVEL_EDITOR_ACTIONS_PANEL_RC_UNHANDLED -1
#define LEVEL_EDITOR_ACTIONS_PANEL_RC_HANDLED 0
#define LEVEL_EDITOR_ACTIONS_PANEL_RC_RESET 1
#define LEVEL_EDITOR_ACTIONS_PANEL_RC_TEST 2
#define LEVEL_EDITOR_ACTIONS_PANEL_RC_LOAD 3
#define LEVEL_EDITOR_ACTIONS_PANEL_RC_SAVE 4

class LevelEditorActionsPanel : public PhysicalEntity
{
public:
    LevelEditorActionsPanel(float x = -3.76608187134503f / 2 + 0.94736842105263f, float y = CAM_HEIGHT / 2, float width = 3.76608187134503f, float height = CAM_HEIGHT);
    
    int handleTouch(TouchEvent& te, Vector2D& touchPoint);
    
    bool isShowEntityBoundsRequested();
    
private:
    std::unique_ptr<Rectangle> m_toggleBoundsButton;
    std::unique_ptr<Rectangle> m_resetButton;
    std::unique_ptr<Rectangle> m_testButton;
    std::unique_ptr<Rectangle> m_loadButton;
    std::unique_ptr<Rectangle> m_saveButton;
    std::unique_ptr<Rectangle> m_openButton;
    std::unique_ptr<Rectangle> m_closeButton;
    bool m_isOpen;
    bool m_isShowEntityBoundsRequested;
};

#endif /* defined(__nosfuratu__LevelEditorActionsPanel__) */