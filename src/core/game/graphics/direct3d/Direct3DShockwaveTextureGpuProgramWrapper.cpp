//
//  Direct3DShockwaveTextureGpuProgramWrapper.cpp
//  nosfuratu
//
//  Created by Stephen Gowen on 12/29/15.
//  Copyright (c) 2017 Noctis Games. All rights reserved.
//

#include "pch.h"

#include "Direct3DShockwaveTextureGpuProgramWrapper.h"

#include "Direct3DTextureProgram.h"
#include "Direct3DManager.h"
#include "GpuTextureWrapper.h"
#include "Vector2D.h"
#include "GameConstants.h"

Direct3DShockwaveTextureGpuProgramWrapper::Direct3DShockwaveTextureGpuProgramWrapper() : ShockwaveTextureGpuProgramWrapper(),
m_program(new Direct3DTextureProgram(SHOCKWAVE_VERTEX_SHADER, SHOCKWAVE_FRAGMENT_SHADER))
{
	m_program->createConstantBuffer(&m_centerXConstantBuffer);
	m_program->createConstantBuffer(&m_centerYConstantBuffer);
	m_program->createConstantBuffer(&m_timeElapsedConstantBuffer);
	m_program->createConstantBuffer(&m_isTransformingConstantBuffer);
}

Direct3DShockwaveTextureGpuProgramWrapper::~Direct3DShockwaveTextureGpuProgramWrapper()
{
    m_centerXConstantBuffer.Reset();
    m_centerYConstantBuffer.Reset();
    m_timeElapsedConstantBuffer.Reset();
    m_isTransformingConstantBuffer.Reset();
    
    delete m_program;
}

void Direct3DShockwaveTextureGpuProgramWrapper::bind()
{
    D3DManager->useScreenBlending();
    
	m_program->bindShaders();
    
    m_program->bindNormalSamplerState();

    ID3D11DeviceContext* d3dContext = Direct3DManager::getD3dContext();
    
	d3dContext->VSSetConstantBuffers(1, 1, m_centerXConstantBuffer.GetAddressOf());
	d3dContext->VSSetConstantBuffers(2, 1, m_centerYConstantBuffer.GetAddressOf());
	d3dContext->PSSetConstantBuffers(0, 1, m_timeElapsedConstantBuffer.GetAddressOf());
	d3dContext->PSSetConstantBuffers(1, 1, m_isTransformingConstantBuffer.GetAddressOf());

    m_program->bindMatrix();

	// send center and time elapsed to video memory
	float centerX = m_center->getX();
	float centerY = m_center->getY();
	int isTransforming = m_isTransforming ? 1 : 0;
	d3dContext->UpdateSubresource(m_centerXConstantBuffer.Get(), 0, 0, &centerX, 0, 0);
	d3dContext->UpdateSubresource(m_centerYConstantBuffer.Get(), 0, 0, &centerY, 0, 0);
	d3dContext->UpdateSubresource(m_timeElapsedConstantBuffer.Get(), 0, 0, &m_fTimeElapsed, 0, 0);
	d3dContext->UpdateSubresource(m_isTransformingConstantBuffer.Get(), 0, 0, &isTransforming, 0, 0);

	m_program->mapVertices();
}

void Direct3DShockwaveTextureGpuProgramWrapper::unbind()
{
	// Empty
}
