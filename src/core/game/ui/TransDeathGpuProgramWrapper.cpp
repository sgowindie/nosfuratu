//
//  TransDeathGpuProgramWrapper.cpp
//  nosfuratu
//
//  Created by Stephen Gowen on 1/27/16.
//  Copyright © 2016 Gowen Game Dev. All rights reserved.
//

#include "TransDeathGpuProgramWrapper.h"

TransDeathGpuProgramWrapper::TransDeathGpuProgramWrapper(bool isTransIn) : m_grayMap(nullptr), m_fTimeElapsed(0), m_isTransIn(false)
{
    // Empty
}

void TransDeathGpuProgramWrapper::configure(TextureWrapper* grayMap, float timeElapsed)
{
    m_grayMap = grayMap;
    m_fTimeElapsed = timeElapsed;
}