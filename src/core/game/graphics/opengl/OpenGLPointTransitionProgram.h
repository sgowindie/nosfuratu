//
//  OpenGLPointTransitionProgram.h
//  nosfuratu
//
//  Created by Stephen Gowen on 7/28/16.
//  Copyright (c) 2017 Noctis Games. All rights reserved.
//

#ifndef __nosfuratu__OpenGLPointTransitionProgram__
#define __nosfuratu__OpenGLPointTransitionProgram__

#include "OpenGLProgram.h"

class OpenGLPointTransitionProgram : public OpenGLProgram
{
public:
    GLint u_mvp_matrix_location;
    GLint u_center_x_unit_location;
    GLint u_center_y_unit_location;
    GLint u_from_location;
    GLint u_to_location;
    GLint u_progress_location;
    GLint a_position_location;
    
    OpenGLPointTransitionProgram(const char* vertexShaderName, const char* fragmentShaderName);
    
    virtual void bind();
    
    virtual void unbind();
};

#endif /* defined(__nosfuratu__OpenGLPointTransitionProgram__) */
