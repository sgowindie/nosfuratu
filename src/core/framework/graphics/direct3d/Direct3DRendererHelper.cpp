//
//  Direct3DRendererHelper.cpp
//  noctisgames-framework
//
//  Created by Stephen Gowen on 1/15/17.
//  Copyright (c) 2017 Noctis Games. All rights reserved.
//

#include "pch.h"

#include "Direct3DRendererHelper.h"

#include "GpuTextureWrapper.h"
#include "Direct3DManager.h"

Direct3DRendererHelper::Direct3DRendererHelper() : IRendererHelper(), m_iFramebufferIndex(0), m_isBoundToScreen(false)
{
	Direct3DManager::create();
}

Direct3DRendererHelper::~Direct3DRendererHelper()
{
	Direct3DManager::destroy();
}

void Direct3DRendererHelper::createDeviceDependentResources(int maxBatchSize)
{
	D3DManager->createDeviceDependentResources(maxBatchSize);
}

void Direct3DRendererHelper::createWindowSizeDependentResources(int renderWidth, int renderHeight, int numFramebuffers)
{
	D3DManager->createWindowSizeDependentResources(renderWidth, renderHeight, numFramebuffers);
}

void Direct3DRendererHelper::releaseDeviceDependentResources()
{
	D3DManager->releaseDeviceDependentResources();
}

void Direct3DRendererHelper::beginFrame()
{
    // Empty
}

void Direct3DRendererHelper::endFrame()
{
    // Empty
}

GpuTextureWrapper* Direct3DRendererHelper::getFramebuffer(int index)
{
    return D3DManager->getFramebuffers().at(index);
}

void Direct3DRendererHelper::updateMatrix(float left, float right, float bottom, float top)
{
    D3DManager->updateMatrix(left, right, bottom, top);
}

void Direct3DRendererHelper::bindToOffscreenFramebuffer(int index)
{
	ID3D11DeviceContext* d3dContext = Direct3DManager::getD3dContext();

	d3dContext->OMSetRenderTargets(1, &D3DManager->getOffscreenRenderTargetViews().at(index), nullptr);
    
	m_iFramebufferIndex = index;
    m_isBoundToScreen = false;
}

void Direct3DRendererHelper::clearFramebufferWithColor(float r, float g, float b, float a)
{
    float color[] = { r, g, b, a };

    ID3D11RenderTargetView * targets[1] = {};
    if (m_isBoundToScreen)
    {
		ID3D11RenderTargetView* d3dRenderTargetView = Direct3DManager::getD3dRenderTargetView();
        targets[0] = d3dRenderTargetView;
    }
    else
    {
        targets[0] = D3DManager->getOffscreenRenderTargetViews().at(m_iFramebufferIndex);
    }
    
	ID3D11DeviceContext* d3dContext = Direct3DManager::getD3dContext();

	d3dContext->ClearRenderTargetView(targets[0], color);
}

void Direct3DRendererHelper::bindToScreenFramebuffer()
{
	ID3D11DeviceContext* d3dContext = Direct3DManager::getD3dContext();

	ID3D11RenderTargetView* d3dRenderTargetView = Direct3DManager::getD3dRenderTargetView();

    ID3D11RenderTargetView *const targets[1] = { d3dRenderTargetView };
	d3dContext->OMSetRenderTargets(1, targets, nullptr);
    
    m_isBoundToScreen = true;
}

void Direct3DRendererHelper::destroyTexture(GpuTextureWrapper& textureWrapper)
{
    if (textureWrapper.texture)
    {
        textureWrapper.texture->Release();
    }
}
