//
//  ConfirmResetPanel.h
//  nosfuratu
//
//  Created by Stephen Gowen on 3/31/16.
//  Copyright (c) 2016 Noctis Games. All rights reserved.
//

#ifndef __nosfuratu__ConfirmResetPanel__
#define __nosfuratu__ConfirmResetPanel__

#include "PhysicalEntity.h"
#include "GameConstants.h"
#include "TouchEvent.h"
#include "Vector2D.h"
#include "Rectangle.h"

#define CONFIRM_RESET_PANEL_RC_UNHANDLED 0
#define CONFIRM_RESET_PANEL_RC_CANCEL 1
#define CONFIRM_RESET_PANEL_RC_RESET 2

class ConfirmResetPanel : public PhysicalEntity
{
public:
    ConfirmResetPanel(float x = CAM_WIDTH / 2, float y = CAM_HEIGHT / 2, float width = CAM_WIDTH / 3, float height = CAM_HEIGHT / 3);
    
    void open();
    
    void close();
    
    int handleTouch(TouchEvent& te, Vector2D& touchPoint);
    
    bool isOpen();
    
private:
    std::unique_ptr<Rectangle> m_cancelButton;
    std::unique_ptr<Rectangle> m_resetButton;
    bool m_isOpen;
};

#endif /* defined(__nosfuratu__ConfirmResetPanel__) */