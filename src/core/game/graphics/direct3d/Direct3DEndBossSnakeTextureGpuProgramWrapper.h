//
//  Direct3DEndBossSnakeTextureGpuProgramWrapper.h
//  nosfuratu
//
//  Created by Stephen Gowen on 9/26/16.
//  Copyright (c) 2017 Noctis Games. All rights reserved.
//

#ifndef __nosfuratu__Direct3DEndBossSnakeTextureGpuProgramWrapper__
#define __nosfuratu__Direct3DEndBossSnakeTextureGpuProgramWrapper__

#include "EndBossSnakeTextureGpuProgramWrapper.h"

class Direct3DProgram;

class Direct3DEndBossSnakeTextureGpuProgramWrapper : public EndBossSnakeTextureGpuProgramWrapper
{
public:
    Direct3DEndBossSnakeTextureGpuProgramWrapper();
    
    virtual ~Direct3DEndBossSnakeTextureGpuProgramWrapper();
    
    virtual void bind();
    
    virtual void unbind();
    
private:
    Direct3DProgram* m_program;
};

#endif /* defined(__nosfuratu__Direct3DEndBossSnakeTextureGpuProgramWrapper__) */
