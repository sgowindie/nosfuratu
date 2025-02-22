//
//  TrashCan.cpp
//  nosfuratu
//
//  Created by Stephen Gowen on 10/5/15.
//  Copyright (c) 2017 Noctis Games. All rights reserved.
//

#include "pch.h"

#include "TrashCan.h"

#include "Vector2D.h"

TrashCan::TrashCan(float x, float y, float width, float height) : PhysicalEntity(x, y, width, height), m_isHighlighted(false)
{
    updateBounds();
}

void TrashCan::update(Vector2D& cameraPosition)
{
    m_position.setX(cameraPosition.getX() + ZOOMED_OUT_CAM_WIDTH / 2);
    
    updateBounds();
}

void TrashCan::setHighlighted(bool isHighlighted)
{
    m_isHighlighted = isHighlighted;
}

bool TrashCan::isHighlighted()
{
    return m_isHighlighted;
}

RTTI_IMPL(TrashCan, PhysicalEntity);
