//
//  Direct3DFrameBufferObfuscationGpuProgramWrapper.cpp
//  nosfuratu
//
//  Created by Stephen Gowen on 9/17/16.
//  Copyright (c) 2017 Noctis Games. All rights reserved.
//

#include "pch.h"

#include "Direct3DFrameBufferObfuscationGpuProgramWrapper.h"

#include "Direct3DTextureProgram.h"
#include "Direct3DManager.h"
#include "GpuTextureWrapper.h"
#include "FrameworkConstants.h"
#include "GameConstants.h"

Direct3DFrameBufferObfuscationGpuProgramWrapper::Direct3DFrameBufferObfuscationGpuProgramWrapper() : GpuProgramWrapper(),
m_program(new Direct3DTextureProgram(FRAMEBUFFER_TO_SCREEN_VERTEX_SHADER, OBFUSCATION_FRAGMENT_SHADER))
{
    // Empty
}

Direct3DFrameBufferObfuscationGpuProgramWrapper::~Direct3DFrameBufferObfuscationGpuProgramWrapper()
{
    delete m_program;
}

void Direct3DFrameBufferObfuscationGpuProgramWrapper::bind()
{
    D3DManager->useNormalBlending();
    
    m_program->bindShaders();
    
    m_program->bindNormalSamplerState();
    
    m_program->mapVertices();
}

void Direct3DFrameBufferObfuscationGpuProgramWrapper::unbind()
{
	// Empty
}
