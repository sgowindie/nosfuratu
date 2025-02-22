//
//  Midground.cpp
//  nosfuratu
//
//  Created by Stephen Gowen on 2/8/16.
//  Copyright (c) 2017 Noctis Games. All rights reserved.
//

#include "pch.h"

#include "Midground.h"

#include "EntityUtils.h"

Midground* Midground::create(int gridX, int gridY, int type)
{
    MidgroundType mt = (MidgroundType)type;
    switch (mt)
    {
        case MidgroundType_TreeOne:
            return new Midground(gridX, 96, 62, 54, mt);
        case MidgroundType_TreeTwo:
            return new Midground(gridX, 96, 70, 50, mt);
        case MidgroundType_TreeThree:
            return new Midground(gridX, 96, 18, 16, mt);
        case MidgroundType_DeepCaveColumnSmall:
            return new Midground(gridX, 0, 6, 18, mt);
        case MidgroundType_DeepCaveColumnMedium:
            return new Midground(gridX, 0, 8, 52, mt);
        case MidgroundType_DeepCaveColumnBig:
            return new Midground(gridX, 0, 16, 52, mt);
        case MidgroundType_Plant:
            return new Midground(gridX, 96, 19, 20, mt);
        case MidgroundType_Metal_Tower_Section:
            return new Midground(gridX, gridY, 8, 12, mt);
        case MidgroundType_Billboard_Count_Hiss:
            return new Midground(gridX, gridY, 48, 28, mt);
        case MidgroundType_Billboard_Slag_Town:
            return new Midground(gridX, gridY, 48, 28, mt);
        case MidgroundType_Billboard_Jon_Wanted:
            return new Midground(gridX, gridY, 48, 28, mt);
        case MidgroundType_Hill:
            return new Midground(gridX, 96, 86, 11, mt);
        case MidgroundType_Train_Car:
            return new Midground(gridX, 96, 98, 24, mt);
        case MidgroundType_Short_Stump:
            return new Midground(gridX, 96, 12, 8, mt);
        case MidgroundType_Tall_Stump:
            return new Midground(gridX, 96, 8, 12, mt);
        case MidgroundType_Thin_Tall_Tree:
            return new Midground(gridX, 96, 12, 32, mt);
        case MidgroundType_Thin_Short_Tree:
            return new Midground(gridX, 96, 16, 20, mt);
        case MidgroundType_Stone_Square:
            return new Midground(gridX, gridY, 24, 24, mt);
        case MidgroundType_Stone_Diamond:
            return new Midground(gridX, gridY, 24, 24, mt);
        case MidgroundType_Wall:
            return new Midground(gridX, gridY, 16, 16, mt);
        case MidgroundType_Roof:
            return new Midground(gridX, gridY, 16, 4, mt);
        case MidgroundType_DiagonalChain:
            return new Midground(gridX, 0, 8, 52, mt);
        case MidgroundType_StraightChain:
            return new Midground(gridX, 0, 3, 52, mt);
    }
    
    assert(false);
}

Midground::Midground(int gridX, int gridY, int gridWidth, int gridHeight, MidgroundType type) : GridLockedPhysicalEntity(gridX, gridY, gridWidth, gridHeight), m_type(type)
{
    updateBounds();
}

MidgroundType Midground::getType()
{
    return m_type;
}

RTTI_IMPL(Midground, GridLockedPhysicalEntity);
