//
//  OpenGLGameScreen.cpp
//  nosfuratu
//
//  Created by Stephen Gowen on 2/22/14.
//  Copyright (c) 2016 Noctis Games. All rights reserved.
//

#include "OpenGLGameScreen.h"

OpenGLGameScreen::OpenGLGameScreen(bool isLowMemoryDevice, bool isUsingDesktopTextureSet) : GameScreen(), m_isLowMemoryDevice(isLowMemoryDevice), m_isUsingDesktopTextureSet(isUsingDesktopTextureSet)
{
    // Empty
}

void OpenGLGameScreen::init(int screenWidth, int screenHeight)
{
    OGLESManager->init(screenWidth, screenHeight, MAX_BATCH_SIZE, NUM_FRAMEBUFFERS);
    
    Assets::getInstance()->setUsingCompressedTextureSet(m_isLowMemoryDevice);
    Assets::getInstance()->setUsingDesktopTextureSet(m_isUsingDesktopTextureSet);
    
    if (!m_renderer)
    {
        m_renderer = std::unique_ptr<OpenGLRenderer>(new OpenGLRenderer());
    }
    
    m_stateMachine->getCurrentState()->enter(this);
}