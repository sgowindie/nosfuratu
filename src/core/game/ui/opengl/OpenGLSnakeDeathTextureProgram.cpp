//
//  OpenGLSnakeDeathTextureProgram.cpp
//  nosfuratu
//
//  Created by Stephen Gowen on 12/28/15.
//  Copyright (c) 2016 Noctis Games. All rights reserved.
//

#include "OpenGLSnakeDeathTextureProgram.h"

OpenGLSnakeDeathTextureProgramStruct OpenGLSnakeDeathTextureProgram::build(GLuint program)
{
    return (OpenGLSnakeDeathTextureProgramStruct)
    {
        program,
        glGetUniformLocation(program, "u_MvpMatrix"),
        glGetAttribLocation(program, "a_Position"),
        glGetAttribLocation(program, "a_Color"),
        glGetAttribLocation(program, "a_TextureCoordinates"),
        glGetUniformLocation(program, "u_TextureUnit")
    };
}