//
//  Direct3DFramebufferTintGpuProgramWrapper.h
//  nosfuratu
//
//  Created by Stephen Gowen on 1/28/16.
//  Copyright (c) 2017 Noctis Games. All rights reserved.
//

#ifndef __nosfuratu__Direct3DFramebufferTintGpuProgramWrapper__
#define __nosfuratu__Direct3DFramebufferTintGpuProgramWrapper__

#include "GpuProgramWrapper.h"

class Direct3DProgram;

class Direct3DFramebufferTintGpuProgramWrapper : public GpuProgramWrapper
{
public:
    Direct3DFramebufferTintGpuProgramWrapper();
    
    virtual ~Direct3DFramebufferTintGpuProgramWrapper();
    
    virtual void bind();
    
    virtual void unbind();
    
private:
    Direct3DProgram* m_program;
};

#endif /* defined(__nosfuratu__Direct3DFramebufferTintGpuProgramWrapper__) */
