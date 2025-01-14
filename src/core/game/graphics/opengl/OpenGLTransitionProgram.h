//
//  OpenGLTransitionProgram.h
//  nosfuratu
//
//  Created by Stephen Gowen on 1/27/16.
//  Copyright (c) 2017 Noctis Games. All rights reserved.
//

#ifndef __nosfuratu__OpenGLTransitionProgram__
#define __nosfuratu__OpenGLTransitionProgram__

#include "OpenGLProgram.h"

class OpenGLTransitionProgram : public OpenGLProgram
{
public:
    GLint u_from_location;
    GLint u_to_location;
    GLint u_progress_location;
    GLint a_position_location;
    
    OpenGLTransitionProgram(const char* vertexShaderName, const char* fragmentShaderName);
    
    virtual void bind();
    
    virtual void unbind();
};

#endif /* defined(__nosfuratu__OpenGLTransitionProgram__) */
