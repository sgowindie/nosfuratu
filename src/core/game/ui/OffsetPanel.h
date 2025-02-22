//
//  OffsetPanel.h
//  nosfuratu
//
//  Created by Stephen Gowen on 3/31/16.
//  Copyright (c) 2017 Noctis Games. All rights reserved.
//

#ifndef __nosfuratu__OffsetPanel__
#define __nosfuratu__OffsetPanel__

#include "PhysicalEntity.h"

#include "GameConstants.h"

#include "RTTI.h"

class ScreenEvent;
class Vector2D;
class NGRect;

#define OFFSET_PANEL_RC_UNHANDLED -1
#define OFFSET_PANEL_RC_HANDLED 0
#define OFFSET_PANEL_RC_CONFIRM 1

class OffsetPanel : public PhysicalEntity
{
    RTTI_DECL;
    
public:
    OffsetPanel(float x = CAM_WIDTH / 2, float y = CAM_HEIGHT / 2, float width = CAM_WIDTH / 3, float height = CAM_HEIGHT / 3);
    
    virtual ~OffsetPanel();
    
    void open();
    
    void close();
    
    int handleTouch(ScreenEvent& te, Vector2D& touchPoint);
    
    Vector2D& getLeftTextPosition();
    
    Vector2D& getRightTextPosition();
    
    float getTextSize();
    
    int getOffset();
    
    bool isOpen();
    
private:
    NGRect* m_offsetLeftButton;
    NGRect* m_offsetRightButton;
    NGRect* m_confirmButton;
    Vector2D* m_leftTextPosition;
    Vector2D* m_rightTextPosition;
    int m_iOffset;
    bool m_isOpen;
};

#endif /* defined(__nosfuratu__OffsetPanel__) */
