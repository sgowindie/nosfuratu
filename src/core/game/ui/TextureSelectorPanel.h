//
//  TextureSelectorPanel.h
//  nosfuratu
//
//  Created by Stephen Gowen on 11/8/16.
//  Copyright (c) 2016 Noctis Games. All rights reserved.
//

#ifndef __nosfuratu__TextureSelectorPanel__
#define __nosfuratu__TextureSelectorPanel__

#include "PhysicalEntity.h"
#include "GameConstants.h"
#include "TouchEvent.h"
#include "Vector2D.h"
#include "Rectangle.h"
#include "Text.h"
#include "TextureWrapper.h"
#include "RTTI.h"

#define TEXTURE_SELECTOR_PANEL_RC_UNHANDLED -1
#define TEXTURE_SELECTOR_PANEL_RC_HANDLED 0
#define TEXTURE_SELECTOR_PANEL_RC_CONFIRM 1

class TextureSelectorPanel : public PhysicalEntity
{
    RTTI_DECL;
    
public:
    TextureSelectorPanel(float x = CAM_WIDTH / 2, float y = CAM_HEIGHT / 2, float width = CAM_WIDTH / 3, float height = CAM_HEIGHT / 3);
    
    void open();
    
    void close();
    
    int handleTouch(TouchEvent& te, Vector2D& touchPoint, std::vector<TextureWrapper *>& textureWrappers);
    
    bool isOpen();
    
    Text& getText() { return *m_text; }
    
    TextureWrapper* getSelectedTexture() { return m_selectedTextureWrapper; }
    
private:
    std::unique_ptr<Rectangle> m_toggleTextureButton;
    std::unique_ptr<Rectangle> m_confirmButton;
    std::unique_ptr<Text> m_text;
    TextureWrapper* m_selectedTextureWrapper;
    int m_iSelectedTextureWrapperIndex;
    bool m_isOpen;
};

#endif /* defined(__nosfuratu__TextureSelectorPanel__) */