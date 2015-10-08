//
//  EntityUtils.h
//  nosfuratu
//
//  Created by Stephen Gowen on 9/23/15.
//  Copyright © 2015 Gowen Game Dev. All rights reserved.
//

#ifndef __nosfuratu__EntityUtils__
#define __nosfuratu__EntityUtils__

#include "EntityAnchor.h"
#include "OverlapTester.h"
#include "PhysicalEntity.h"
#include "DestructiblePhysicalEntity.h"
#include "Rectangle.h"
#include "Vector2D.h"

#include <math.h>
#include <vector>

class PhysicalEntity;

class EntityUtils
{
public:
    static void applyAnchor(PhysicalEntity& entity, EntityAnchor anchor, float offset = 0);
    
    static void attach(PhysicalEntity& entity, PhysicalEntity& to, bool leftOf, bool yCorrection);
    
    static void placeOn(PhysicalEntity& entity, PhysicalEntity& on);
    
    template<typename T>
    static bool isLanding(PhysicalEntity& entity, std::vector<T>& items, float deltaTime)
    {
        float entityVelocityY = entity.getVelocity().getY();
        float entityLowerLeftY = entity.getBounds().getLowerLeft().getY();
        float entityYDelta = fabsf(entityVelocityY * deltaTime);
        
        if (entityVelocityY <= 0)
        {
            for (typename std::vector<T>::iterator i = items.begin(); i != items.end(); i++)
            {
                if (OverlapTester::doRectanglesOverlap(entity.getBounds(), (*i).getBounds()))
                {
                    float itemTop = (*i).getBounds().getLowerLeft().getY() + (*i).getBounds().getHeight();
                    float padding = itemTop * .01f;
                    padding += entityYDelta;
                    float itemTopReq = itemTop - padding;
                    
                    if (entityLowerLeftY >= itemTopReq)
                    {
                        entity.getPosition().setY(itemTop + entity.getBounds().getHeight() / 2 * .99f);
                        entity.updateBounds();
                        
                        return true;
                    }
                }
            }
        }
        
        return false;
    }
    
    template<typename T>
    static bool isLandingOnSpring(PhysicalEntity& entity, std::vector<T>& items, float deltaTime)
    {
        float entityVelocityY = entity.getVelocity().getY();
        float entityLowerLeftY = entity.getBounds().getLowerLeft().getY();
        float entityYDelta = fabsf(entityVelocityY * deltaTime);
        
        if (entityVelocityY <= 0)
        {
            for (typename std::vector<T>::iterator i = items.begin(); i != items.end(); i++)
            {
                if (OverlapTester::doRectanglesOverlap(entity.getBounds(), (*i).getBounds()))
                {
                    float itemTop = (*i).getBounds().getLowerLeft().getY() + (*i).getBounds().getHeight();
                    float padding = itemTop * .01f;
                    padding += entityYDelta;
                    float itemTopReq = itemTop - padding;
                    
                    if (entityLowerLeftY >= itemTopReq)
                    {
                        (*i).trigger();
                        
                        return true;
                    }
                }
            }
        }
        
        return false;
    }
    
    template<typename T>
    static bool isBlockedOnRight(PhysicalEntity& entity, std::vector<T>& items, float deltaTime)
    {
        float entityBottom = entity.getBounds().getLowerLeft().getY();
        float entityRight = entity.getBounds().getLowerLeft().getX() + entity.getBounds().getWidth();
        float padding = fabsf(entity.getVelocity().getX() * deltaTime);
        
        for (typename std::vector<T>::iterator i = items.begin(); i != items.end(); i++)
        {
            if (OverlapTester::doRectanglesOverlap(entity.getBounds(), (*i).getBounds()))
            {
                float itemLeft = (*i).getBounds().getLowerLeft().getX();
                float itemTop = (*i).getBounds().getLowerLeft().getY() + (*i).getBounds().getHeight();
                float itemTopReq = itemTop * 0.99f;
                float itemLeftReq = itemLeft - padding;
                
                if (entityRight > itemLeftReq && entityBottom < itemTopReq)
                {
                    entity.getPosition().setX(itemLeft - entity.getBounds().getWidth() / 2 * 1.01f);
                    entity.updateBounds();
                    
                    return true;
                }
            }
        }
        
        return false;
    }
    
    template<typename T>
    static bool isBlockedAbove(PhysicalEntity& entity, std::vector<T>& items, float deltaTime)
    {
        float entityVelocityY = entity.getVelocity().getY();
        float entityLeft = entity.getBounds().getLowerLeft().getX();
        
        if (entityVelocityY > 0)
        {
            for (typename std::vector<T>::iterator i = items.begin(); i != items.end(); i++)
            {
                if (OverlapTester::doRectanglesOverlap(entity.getBounds(), (*i).getBounds()))
                {
                    float itemLeft = (*i).getBounds().getLowerLeft().getX();
                    
                    if (itemLeft < entityLeft)
                    {
                        entity.getPosition().sub(0, entity.getVelocity().getY() * deltaTime);
                        entity.updateBounds();
                        
                        return true;
                    }
                }
            }
        }
        
        return false;
    }
    
    template<typename T>
    static bool isCollected(PhysicalEntity& entity, std::vector<T>& items, float deltaTime)
    {
        bool retval = false;
        
        for (typename std::vector<T>::iterator i = items.begin(); i != items.end(); )
        {
            if (OverlapTester::doRectanglesOverlap(entity.getBounds(), (*i).getBounds()))
            {
                retval = true;
                i = items.erase(i);
            }
            else
            {
                i++;
            }
        }
        
        return retval;
    }
    
    template<typename T>
    static bool isHitting(PhysicalEntity& entity, std::vector<T>& items)
    {
        Rectangle& bounds = entity.getBounds();
        Rectangle hittingBounds = Rectangle(bounds.getLowerLeft().getX(), bounds.getLowerLeft().getY() + bounds.getHeight() / 2, bounds.getWidth() * 1.2f, bounds.getHeight());
        
        for (typename std::vector<T>::iterator i = items.begin(); i != items.end(); )
        {
            if (OverlapTester::doRectanglesOverlap(hittingBounds, (*i).getBounds()))
            {
                (*i).triggerHit();
                
                if ((*i).isRequestingDeletion())
                {
                    i = items.erase(i);
                }
                
                return true;
            }
            else
            {
                i++;
            }
        }
        
        return false;
    }
    
    template<typename T>
    static bool isHit(PhysicalEntity& entity, std::vector<T>& items)
    {
        for (typename std::vector<T>::iterator i = items.begin(); i != items.end(); i++)
        {
            if (OverlapTester::doRectanglesOverlap(entity.getBounds(), (*i).getBounds()))
            {
                return true;
            }
        }
        
        return false;
    }
    
    template<typename T>
    static bool isFallingIntoDeath(PhysicalEntity& entity, std::vector<T>& items)
    {
        float entityVelocityY = entity.getVelocity().getY();
        if (entityVelocityY < 0)
        {
            for (typename std::vector<T>::iterator i = items.begin(); i != items.end(); i++)
            {
                if (OverlapTester::doRectanglesOverlap(entity.getBounds(), (*i).getBounds()))
                {
                    return true;
                }
            }
        }
        
        return false;
    }
    
    template<typename T>
    static void updateBackgrounds(std::vector<T>& items, Vector2D& cameraPosition)
    {
        for (typename std::vector<T>::iterator i = items.begin(); i != items.end(); i++)
        {
            i->update(cameraPosition);
        }
    }
    
    template<typename T>
    static void update(std::vector<T>& items, float deltaTime)
    {
        for (typename std::vector<T>::iterator i = items.begin(); i != items.end(); i++)
        {
            i->update(deltaTime);
        }
    }
    
    template<typename T>
    static void updateAndClean(std::vector<T>& items, float deltaTime)
    {
        for (typename std::vector<T>::iterator i = items.begin(); i != items.end(); )
        {
            i->update(deltaTime);
            
            if (i->isRequestingDeletion())
            {
                i = items.erase(i);
            }
            else
            {
                i++;
            }
        }
    }
    
    template<typename T>
    static void addAll(std::vector<T>& itemsFrom, std::vector<PhysicalEntity*>& itemsTo)
    {
        for (typename std::vector<T>::iterator i = itemsFrom.begin(); i != itemsFrom.end(); i++)
        {
            T* p_i = &(*i);
            itemsTo.push_back(p_i);
        }
    }
    
    template<typename T>
    static int isTouching(std::vector<T*>& items, Vector2D& touchPoint)
    {
        int last = ((int) items.size()) - 1;
        for (int i = last; i >= 0; i--)
        {
            T* item = items.at(i);
            float width = item->getWidth();
            float height = item->getHeight();
            float x = item->getPosition().getX() - width / 2;
            float y = item->getPosition().getY() - height / 2;
            
            Rectangle tempBounds = Rectangle(x, y, width, height);
            if (OverlapTester::isPointInRectangle(touchPoint, tempBounds))
            {
                return i;
            }
        }
        
        return -1;
    }
    
    template<typename T>
    static int isTouchingEntityForPlacement(std::vector<T>& items, Vector2D& touchPoint)
    {
        int index = 0;
        for (typename std::vector<T>::iterator i = items.begin(); i != items.end(); i++, index++)
        {
            T& item = *i;
            float width = item.getWidth();
            float height = item.getHeight();
            float x = item.getPosition().getX() - width / 2;
            float y = item.getPosition().getY() - height / 2;
            
            Rectangle tempBounds = Rectangle(x, y, width, height);
            if (OverlapTester::isPointInRectangle(touchPoint, tempBounds))
            {
                return index;
            }
        }
        
        return -1;
    }
    
    template<typename T>
    static int doRectanglesOverlap(std::vector<T>& items, PhysicalEntity& pe)
    {
        int index = 0;
        for (typename std::vector<T>::iterator i = items.begin(); i != items.end(); i++, index++)
        {
            if ((&(*i)) == &pe)
            {
                continue;
            }
            
            if (OverlapTester::doRectanglesOverlap(pe.getBounds(), i->getBounds()))
            {
                return index;
            }
        }
        
        return -1;
    }
    
    template<typename T>
    static void boxInAll(std::vector<T>& items, float size)
    {
        for (typename std::vector<T>::iterator i = items.begin(); i != items.end(); i++)
        {
            i->boxIn(size);
        }
    }
    
private:
    // ctor, copy ctor, and assignment should be private in a Singleton
    EntityUtils();
    EntityUtils(const EntityUtils&);
    EntityUtils& operator=(const EntityUtils&);
};

#endif /* defined(__nosfuratu__EntityUtils__) */