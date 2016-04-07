//
//  BatPanel.h
//  nosfuratu
//
//  Created by Stephen Gowen on 4/4/16.
//  Copyright (c) 2016 Noctis Games. All rights reserved.
//

#ifndef __nosfuratu__BatPanel__
#define __nosfuratu__BatPanel__

#include "PhysicalEntity.h"
#include "GameConstants.h"
#include "TouchEvent.h"
#include "Vector2D.h"
#include "Rectangle.h"
#include "Color.h"

class Game;

typedef enum
{
    BatPanelType_None,
    BatPanelType_Jump,
    BatPanelType_DoubleJump,
    BatPanelType_Burrow
} BatPanelType;

class BatInstruction : public PhysicalEntity
{
public:
    BatInstruction(float x, float y, float width, float height);
    
    virtual void update(float deltaTime);
    
    void setGame(Game* game);
    
    void show(BatPanelType type);
    
    bool isShowing();
    
    bool isRequestingClose();
    
    BatPanelType getBatPanelType();
    
    Color& getColor();
    
private:
    Game* m_game;
    BatPanelType m_type;
    Color m_color;
    bool m_isShowing;
    bool m_isRequestingClose;
};

class BatPanel : public PhysicalEntity
{
public:
    BatPanel(float x = CAM_WIDTH / 2, float y = CAM_HEIGHT - 1.125f / 2 - 0.8f, float width = 4.5f, float height = 1.125f);
    
    virtual void update(float deltaTime);
    
    void setGame(Game* game);
    
    void open(BatPanelType type);
    
    bool isOpen();
    
    bool isOpening();
    
    BatInstruction& getBatInstruction();
    
    Color& getColor();
    
private:
    std::unique_ptr<BatInstruction> m_batInstruction;
    BatPanelType m_type;
    Color m_color;
    bool m_isOpen;
    bool m_isOpening;
};

#endif /* defined(__nosfuratu__BatPanel__) */