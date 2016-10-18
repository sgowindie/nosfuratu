//
//  IOSOpenGLGameScreen.cpp
//  nosfuratu
//
//  Created by Stephen Gowen on 7/22/15.
//  Copyright (c) 2016 Noctis Games. All rights reserved.
//

#include "IOSOpenGLGameScreen.h"

IOSOpenGLGameScreen::IOSOpenGLGameScreen(int screenWidth, int screenHeight, int pointsWidth, int pointsHeight, bool isLowMemoryDevice) : OpenGLGameScreen(isLowMemoryDevice)
{
    m_iPointsWidth = pointsWidth;
    m_iPointsHeight = pointsHeight;
    
    init(screenWidth, screenHeight);
}

void IOSOpenGLGameScreen::touchToWorld(TouchEvent &touchEvent)
{
    m_touchPoint->set((touchEvent.getX() / (float) m_iPointsWidth) * CAM_WIDTH, (1 - touchEvent.getY() / (float) m_iPointsHeight) * CAM_HEIGHT);
}