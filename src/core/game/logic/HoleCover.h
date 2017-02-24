//
//  HoleCover.h
//  nosfuratu
//
//  Created by Stephen Gowen on 10/20/15.
//  Copyright (c) 2016 Noctis Games. All rights reserved.
//

#ifndef __nosfuratu__HoleCover__
#define __nosfuratu__HoleCover__

#include "PhysicalEntity.h"
#include "RTTI.h"

typedef enum
{
    HoleCoverType_GrassTileLeft,
    HoleCoverType_GrassTileCenter,
    HoleCoverType_GrassTileRight,
    HoleCoverType_Grass,
    HoleCoverType_Cave
} HoleCoverType;

class HoleCover : public PhysicalEntity
{
    RTTI_DECL;
    
public:
    HoleCover(float x, float y, float width, float height, HoleCoverType type);
    
    virtual void update(float deltaTime);
    
    void triggerHit();
    
    HoleCoverType getType();
    
    bool isBreaking();
    
private:
    HoleCoverType m_type;
    bool m_isBreaking;
};

#endif /* defined(__nosfuratu__HoleCover__) */