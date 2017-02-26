//
//  OpenGLGeometryProgram.h
//  noctisgames-framework
//
//  Created by Stephen Gowen on 8/4/15.
//  Copyright (c) 2017 Noctis Games. All rights reserved.
//

#ifndef __noctisgames__OpenGLGeometryProgram__
#define __noctisgames__OpenGLGeometryProgram__

extern "C"
{
#include "platform_gl.h"
}

typedef struct
{
    GLuint program;
    
    GLint u_mvp_matrix_location;
    GLint a_position_location;
    GLint a_color_location;
} OpenGLGeometryProgramStruct;

class OpenGLGeometryProgram
{
public:
    static OpenGLGeometryProgramStruct build(GLuint program);
    
private:
    OpenGLGeometryProgram();
};

#endif /* defined(__noctisgames__OpenGLGeometryProgram__) */