//
//  OpenGLPointTransScreenGpuProgramWrapper.cpp
//  nosfuratu
//
//  Created by Stephen Gowen on 7/28/16.
//  Copyright (c) 2017 Noctis Games. All rights reserved.
//

#include "OpenGLPointTransScreenGpuProgramWrapper.h"

#include "OpenGLPointTransitionProgram.h"
#include "OpenGLManager.h"
#include "GpuTextureWrapper.h"
#include "Vector2D.h"
#include "FrameworkConstants.h"
#include "GameConstants.h"

OpenGLPointTransScreenGpuProgramWrapper::OpenGLPointTransScreenGpuProgramWrapper() : PointTransitionGpuProgramWrapper(), m_program(new OpenGLPointTransitionProgram(POINT_TRANS_SCREEN_VERTEX_SHADER, POINT_TRANS_SCREEN_FRAGMENT_SHADER))
{
    // Empty
}

OpenGLPointTransScreenGpuProgramWrapper::~OpenGLPointTransScreenGpuProgramWrapper()
{
    delete m_program;
}

void OpenGLPointTransScreenGpuProgramWrapper::bind()
{
    OGLManager->useScreenBlending();
    
    glActiveTexture(GL_TEXTURE1);
    glBindTexture(GL_TEXTURE_2D, m_to->texture);
    
    m_program->bind();
    
    glUniform1f(m_program->u_center_x_unit_location, m_center->getX());
    glUniform1f(m_program->u_center_y_unit_location, m_center->getY());
    glUniform1f(m_program->u_progress_location, m_fProgress);
}

void OpenGLPointTransScreenGpuProgramWrapper::unbind()
{
    glActiveTexture(GL_TEXTURE1);
    glBindTexture(GL_TEXTURE_2D, 0);
    
    m_program->unbind();
}
