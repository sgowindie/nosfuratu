//
//  OpenGLGeometryGpuProgramWrapper.cpp
//  noctisgames-framework
//
//  Created by Stephen Gowen on 8/27/15.
//  Copyright (c) 2016 Noctis Games. All rights reserved.
//

#include "OpenGLGeometryGpuProgramWrapper.h"
#include "OpenGLManager.h"
#include "macros.h"

extern "C"
{
#include "asset_utils.h"
}

OpenGLGeometryGpuProgramWrapper::OpenGLGeometryGpuProgramWrapper()
{
    m_program = ColorProgram::build(build_program_from_assets("color_shader.vsh", "color_shader.fsh"));
    m_isLoaded = true;
}

void OpenGLGeometryGpuProgramWrapper::bind()
{
    glUseProgram(m_program.program);
    
    glUniformMatrix4fv(m_program.u_mvp_matrix_location, 1, GL_FALSE, (GLfloat*)OGLESManager->m_viewProjectionMatrix);
    
    glGenBuffers(1, &OGLESManager->gb_vbo_object);
    glBindBuffer(GL_ARRAY_BUFFER, OGLESManager->gb_vbo_object);
    glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * OGLESManager->m_colorVertices.size(), &OGLESManager->m_colorVertices[0], GL_STATIC_DRAW);
    
    glVertexAttribPointer(m_program.a_position_location, 3, GL_FLOAT, GL_FALSE, sizeof(GLfloat) * 7, BUFFER_OFFSET(0));
    glVertexAttribPointer(m_program.a_color_location, 4, GL_FLOAT, GL_FALSE, sizeof(GLfloat) * 7, BUFFER_OFFSET(3 * sizeof(GL_FLOAT)));
    
    glEnableVertexAttribArray(m_program.a_position_location);
    glEnableVertexAttribArray(m_program.a_color_location);
}

void OpenGLGeometryGpuProgramWrapper::unbind()
{
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    
    glDeleteBuffers(1, &OGLESManager->gb_vbo_object);
    
    glUseProgram(0);
}

void OpenGLGeometryGpuProgramWrapper::cleanUp()
{
    glDeleteProgram(m_program.program);
}