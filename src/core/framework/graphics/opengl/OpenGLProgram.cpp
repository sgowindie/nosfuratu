//
//  OpenGLProgram.cpp
//  noctisgames-framework
//
//  Created by Stephen Gowen on 3/2/17.
//  Copyright (c) 2017 Noctis Games. All rights reserved.
//

#include "OpenGLProgram.h"

#include "OpenGLManager.h"
#include "AssetDataHandler.h"
#include "FileData.h"
#include "StringUtil.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>

OpenGLProgram::OpenGLProgram(const char* vertexShaderName, const char* fragmentShaderName)
{
    assert(vertexShaderName != NULL);
    assert(fragmentShaderName != NULL);
    
    char* vertexShaderFileName;
    {
        size_t len = strlen(vertexShaderName);
        
        vertexShaderFileName = new char[len + 5];
        
        strcpy(vertexShaderFileName, vertexShaderName);
        vertexShaderFileName[len] = '.';
        vertexShaderFileName[len + 1] = 'n';
        vertexShaderFileName[len + 2] = 'g';
        vertexShaderFileName[len + 3] = 's';
        vertexShaderFileName[len + 4] = '\0';
    }
    
    char* fragmentShaderFileName;
    {
        size_t len = strlen(fragmentShaderName);
        
        fragmentShaderFileName = new char[len + 5];
        
        strcpy(fragmentShaderFileName, fragmentShaderName);
        fragmentShaderFileName[len] = '.';
        fragmentShaderFileName[len + 1] = 'n';
        fragmentShaderFileName[len + 2] = 'g';
        fragmentShaderFileName[len + 3] = 's';
        fragmentShaderFileName[len + 4] = '\0';
    }
    
    const FileData vertex_shader_source = AssetDataHandler::getAssetDataHandler()->getAssetData(vertexShaderFileName);
    const FileData fragment_shader_source = AssetDataHandler::getAssetDataHandler()->getAssetData(fragmentShaderFileName);
    
    unsigned char* vertex_shader_source_output = (unsigned char*) malloc(vertex_shader_source.data_length);
    StringUtil::encryptDecrypt((unsigned char*)vertex_shader_source.data, vertex_shader_source_output, vertex_shader_source.data_length);
    
    unsigned char* fragment_shader_source_output = (unsigned char*) malloc(fragment_shader_source.data_length);
    StringUtil::encryptDecrypt((unsigned char*)fragment_shader_source.data, fragment_shader_source_output, fragment_shader_source.data_length);
    
    m_programObjectId = buildProgram(vertex_shader_source_output, (GLint)vertex_shader_source.data_length, fragment_shader_source_output, (GLint)fragment_shader_source.data_length);
    
    AssetDataHandler::getAssetDataHandler()->releaseAssetData(&vertex_shader_source);
    AssetDataHandler::getAssetDataHandler()->releaseAssetData(&fragment_shader_source);
    
    free((void *)vertex_shader_source_output);
    free((void *)fragment_shader_source_output);
}

OpenGLProgram::~OpenGLProgram()
{
    glDeleteProgram(m_programObjectId);
}

void OpenGLProgram::bind()
{
    glUseProgram(m_programObjectId);
}

void OpenGLProgram::unbind()
{
    glUseProgram(0);
}

GLuint OpenGLProgram::getProgramObjectId()
{
    return m_programObjectId;
}

void OpenGLProgram::mapBuffer(GLuint& vbo, std::vector<GLfloat>& vertices)
{
    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * vertices.size(), &vertices[0], GL_STATIC_DRAW);
}

void OpenGLProgram::unmapBuffer(GLuint& vbo)
{
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    
    glDeleteBuffers(1, &vbo);
}

GLuint OpenGLProgram::buildProgram(const void * vertex_shader_source, const int vertex_shader_source_length, const void * fragment_shader_source, const int fragment_shader_source_length)
{
    assert(vertex_shader_source != NULL);
    assert(fragment_shader_source != NULL);
    
    GLuint vertex_shader = compileShader(GL_VERTEX_SHADER, vertex_shader_source, vertex_shader_source_length);
    GLuint fragment_shader = compileShader(GL_FRAGMENT_SHADER, fragment_shader_source, fragment_shader_source_length);
    
    return linkProgram(vertex_shader, fragment_shader);
}

GLuint OpenGLProgram::compileShader(const GLenum type, const void* source, const GLint length)
{
    assert(source != NULL);
    
    GLuint shader_object_id = glCreateShader(type);
    GLint compile_status;
    
    assert(shader_object_id != GL_FALSE);
    
    glShaderSource(shader_object_id, 1, (const GLchar **)&source, &length);
    glCompileShader(shader_object_id);
    glGetShaderiv(shader_object_id, GL_COMPILE_STATUS, &compile_status);
    
    if (compile_status == GL_FALSE)
    {
        GLint maxLength = 0;
        glGetShaderiv(shader_object_id, GL_INFO_LOG_LENGTH, &maxLength);
        
        GLchar* errorLog = (GLchar*) malloc(maxLength);
        glGetShaderInfoLog(shader_object_id, maxLength, &maxLength, errorLog);
        printf("%s", errorLog);
        
        glDeleteShader(shader_object_id);
        
        free(errorLog);
    }
    
    assert(compile_status != GL_FALSE);
    
    return shader_object_id;
}

GLuint OpenGLProgram::linkProgram(const GLuint vertex_shader, const GLuint fragment_shader)
{
    GLuint program_object_id = glCreateProgram();
    GLint link_status;
    
    assert(program_object_id != GL_FALSE);
    
    glAttachShader(program_object_id, vertex_shader);
    glAttachShader(program_object_id, fragment_shader);
    glLinkProgram(program_object_id);
    glGetProgramiv(program_object_id, GL_LINK_STATUS, &link_status);
    
    assert(link_status != GL_FALSE);
    
    // Release vertex and fragment shaders.
    glDetachShader(program_object_id, vertex_shader);
    glDeleteShader(vertex_shader);
    glDetachShader(program_object_id, fragment_shader);
    glDeleteShader(fragment_shader);
    
    return program_object_id;
}
