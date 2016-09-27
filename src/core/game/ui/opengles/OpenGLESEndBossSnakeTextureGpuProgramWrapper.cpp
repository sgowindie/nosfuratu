//
//  OpenGLESEndBossSnakeTextureGpuProgramWrapper.cpp
//  nosfuratu
//
//  Created by Stephen Gowen on 9/26/16.
//  Copyright (c) 2016 Noctis Games. All rights reserved.
//

#include "OpenGLESEndBossSnakeTextureGpuProgramWrapper.h"
#include "OpenGLESManager.h"
#include "macros.h"

extern "C"
{
#include "asset_utils.h"
}

OpenGLESEndBossSnakeTextureGpuProgramWrapper::OpenGLESEndBossSnakeTextureGpuProgramWrapper()
{
    m_program = TextureProgram::build(build_program_from_assets("texture_shader.vsh", "end_boss_snake_texture_shader.fsh"));
    m_isLoaded = true;
}

void OpenGLESEndBossSnakeTextureGpuProgramWrapper::bind()
{
    glUseProgram(m_program.program);
    
    glUniformMatrix4fv(m_program.u_mvp_matrix_location, 1, GL_FALSE, (GLfloat*)OGLESManager->m_viewProjectionMatrix);
    glUniform1i(m_program.u_texture_unit_location, 0);
    
    glGenBuffers(1, &OGLESManager->sb_vbo_object);
    glBindBuffer(GL_ARRAY_BUFFER, OGLESManager->sb_vbo_object);
    glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * OGLESManager->m_textureVertices.size(), &OGLESManager->m_textureVertices[0], GL_STATIC_DRAW);
    
    glVertexAttribPointer(m_program.a_position_location, 3, GL_FLOAT, GL_FALSE, sizeof(GLfloat) * 9, BUFFER_OFFSET(0));
    glVertexAttribPointer(m_program.a_color_location, 4, GL_FLOAT, GL_FALSE, sizeof(GLfloat) * 9, BUFFER_OFFSET(3 * sizeof(GL_FLOAT)));
    glVertexAttribPointer(m_program.a_texture_coordinates_location, 2, GL_FLOAT, GL_FALSE, sizeof(GLfloat) * 9, BUFFER_OFFSET(7 * sizeof(GL_FLOAT)));
    
    glEnableVertexAttribArray(m_program.a_position_location);
    glEnableVertexAttribArray(m_program.a_color_location);
    glEnableVertexAttribArray(m_program.a_texture_coordinates_location);
}

void OpenGLESEndBossSnakeTextureGpuProgramWrapper::unbind()
{
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    
    glDeleteBuffers(1, &OGLESManager->sb_vbo_object);
    
    glUseProgram(0);
}

void OpenGLESEndBossSnakeTextureGpuProgramWrapper::cleanUp()
{
    glDeleteProgram(m_program.program);
}