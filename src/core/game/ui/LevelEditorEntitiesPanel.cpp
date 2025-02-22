//
//  LevelEditorEntitiesPanel.cpp
//  nosfuratu
//
//  Created by Stephen Gowen on 10/2/15.
//  Copyright (c) 2017 Noctis Games. All rights reserved.
//

#include "pch.h"

#include "LevelEditorEntitiesPanel.h"

#include "Game.h"
#include "ScreenEvent.h"
#include "Vector2D.h"
#include "NGRect.h"
#include "Midground.h"
#include "Ground.h"
#include "ExitGround.h"
#include "Hole.h"
#include "ForegroundObject.h"
#include "Enemy.h"
#include "CollectibleItem.h"
#include "Jon.h"
#include "EndBossSnake.h"
#include "ForegroundCoverObject.h"
#include "CountHissWithMina.h"

#include "EntityUtils.h"
#include "NGSTDUtil.h"
#include "OverlapTester.h"

#include <math.h>

LevelEditorEntitiesPanel::LevelEditorEntitiesPanel(float x, float y, float width, float height) : PhysicalEntity(x, y, width, height),
m_openButton(new NGRect(CAM_WIDTH - 1, height * 0.49081920903955f, 1, 1)),
m_closeButton(new NGRect(CAM_WIDTH - width, height * 0.49081920903955f, 1, 1)),
m_touchPointDown(new Vector2D()),
m_touchPointDown2(new Vector2D()),
m_isOpen(false),
m_fEntitiesCameraPos(0),
m_fEntitiesHeight(0)
{
    // Empty
}

LevelEditorEntitiesPanel::~LevelEditorEntitiesPanel()
{
    delete m_openButton;
    delete m_closeButton;
    delete m_touchPointDown;
    delete m_touchPointDown2;
}

void LevelEditorEntitiesPanel::initForLevel(int world, int level)
{
    NGSTDUtil::cleanUpVectorOfPointers(m_midgrounds);
    NGSTDUtil::cleanUpVectorOfPointers(m_grounds);
    NGSTDUtil::cleanUpVectorOfPointers(m_pits);
    NGSTDUtil::cleanUpVectorOfPointers(m_exitGrounds);
    NGSTDUtil::cleanUpVectorOfPointers(m_holes);
    NGSTDUtil::cleanUpVectorOfPointers(m_foregroundObjects);
    NGSTDUtil::cleanUpVectorOfPointers(m_midBossForegroundObjects);
    NGSTDUtil::cleanUpVectorOfPointers(m_endBossForegroundObjects);
	NGSTDUtil::cleanUpVectorOfPointers(m_countHissWithMinas);
    NGSTDUtil::cleanUpVectorOfPointers(m_endBossSnakes);
    NGSTDUtil::cleanUpVectorOfPointers(m_enemies);
    NGSTDUtil::cleanUpVectorOfPointers(m_collectibleItems);
    NGSTDUtil::cleanUpVectorOfPointers(m_jons);
    NGSTDUtil::cleanUpVectorOfPointers(m_extraForegroundObjects);
    NGSTDUtil::cleanUpVectorOfPointers(m_foregroundCoverObjects);
    
    if (world == 1)
    {
        m_grounds.push_back(Ground::create(0, 0, GroundType_GrassWithoutCaveEndLeft));
        m_grounds.push_back(Ground::create(0, 0, GroundType_GrassWithoutCaveSmall));
        m_grounds.push_back(Ground::create(0, 0, GroundType_GrassWithoutCaveMedium));
        m_grounds.push_back(Ground::create(0, 0, GroundType_GrassWithoutCaveLarge));
        m_grounds.push_back(Ground::create(0, 0, GroundType_GrassWithoutCaveEndRight));
        
        if (level >= 10)
        {
            m_grounds.push_back(Ground::create(0, 0, GroundType_GrassWithCaveEndLeft));
            m_grounds.push_back(Ground::create(0, 0, GroundType_GrassWithCaveSmall));
            m_grounds.push_back(Ground::create(0, 0, GroundType_GrassWithCaveMedium));
            m_grounds.push_back(Ground::create(0, 0, GroundType_GrassWithCaveLarge));
            m_grounds.push_back(Ground::create(0, 0, GroundType_GrassWithCaveEndRight));
            
            m_grounds.push_back(Ground::create(0, 0, GroundType_CaveRaisedEndLeft));
            m_grounds.push_back(Ground::create(0, 0, GroundType_CaveRaisedSmall));
            m_grounds.push_back(Ground::create(0, 0, GroundType_CaveRaisedMedium));
            m_grounds.push_back(Ground::create(0, 0, GroundType_CaveRaisedLarge));
            m_grounds.push_back(Ground::create(0, 0, GroundType_CaveRaisedEndRight));
            
            m_grounds.push_back(Ground::create(0, 0, GroundType_CaveEndLeft));
            m_grounds.push_back(Ground::create(0, 0, GroundType_CaveSmall));
            m_grounds.push_back(Ground::create(0, 0, GroundType_CaveMedium));
            m_grounds.push_back(Ground::create(0, 0, GroundType_CaveLarge));
            m_grounds.push_back(Ground::create(0, 0, GroundType_CaveEndRight));
            
            m_grounds.push_back(Ground::create(0, 0, GroundType_CaveDeepEndLeft));
            m_grounds.push_back(Ground::create(0, 0, GroundType_CaveDeepSmall));
            m_grounds.push_back(Ground::create(0, 0, GroundType_CaveDeepMedium));
            m_grounds.push_back(Ground::create(0, 0, GroundType_CaveDeepLarge));
            m_grounds.push_back(Ground::create(0, 0, GroundType_CaveDeepEndRight));
            
            m_grounds.push_back(Ground::create(0, 0, GroundType_CaveExtraDeepEndLeft));
            m_grounds.push_back(Ground::create(0, 0, GroundType_CaveExtraDeepSmall));
            m_grounds.push_back(Ground::create(0, 0, GroundType_CaveExtraDeepMedium));
            m_grounds.push_back(Ground::create(0, 0, GroundType_CaveExtraDeepLarge));
            m_grounds.push_back(Ground::create(0, 0, GroundType_CaveExtraDeepEndRight));
        }
        
        if (level >= 10)
        {
            m_exitGrounds.push_back(ExitGround::create(0, 0, ExitGroundType_GrassWithCaveSmallExitMid));
            m_exitGrounds.push_back(ExitGround::create(0, 0, ExitGroundType_GrassWithCaveSmallExitEnd));
            m_exitGrounds.push_back(ExitGround::create(0, 0, ExitGroundType_CaveSmallExit));
            
            m_exitGrounds.push_back(ExitGround::create(0, 0, ExitGroundType_CaveDeepSmallWaterfall));
            
            m_holes.push_back(Hole::create(0, 0, HoleType_GrassTileLeft));
            m_holes.push_back(Hole::create(0, 0, HoleType_GrassTileCenter));
            m_holes.push_back(Hole::create(0, 0, HoleType_GrassTileRight));
            m_holes.push_back(Hole::create(0, 0, HoleType_Grass));
            m_holes.push_back(Hole::create(0, 0, HoleType_Cave));
        }
        
        if (level != 10 && level != 21)
        {
            m_pits.push_back(Ground::create(0, 0, GroundType_GrassPitSmall));
            m_pits.push_back(Ground::create(0, 0, GroundType_GrassPitMedium));
            m_pits.push_back(Ground::create(0, 0, GroundType_GrassPitLarge));
            m_pits.push_back(Ground::create(0, 0, GroundType_GrassPitExtraLarge));
            
            m_pits.push_back(Ground::create(0, 0, GroundType_PitTunnelLeft));
            m_pits.push_back(Ground::create(0, 0, GroundType_PitTunnelCenter));
            m_pits.push_back(Ground::create(0, 0, GroundType_PitTunnelRight));
        }
        
        m_foregroundObjects.push_back(ForegroundObject::create(0, 0, ForegroundObjectType_GrassPlatformLeft));
        m_foregroundObjects.push_back(ForegroundObject::create(0, 0, ForegroundObjectType_GrassPlatformCenter));
        m_foregroundObjects.push_back(ForegroundObject::create(0, 0, ForegroundObjectType_GrassPlatformRight));
		m_foregroundObjects.push_back(ForegroundObject::create(0, 0, ForegroundObjectType_CavePlatformLeft));
		m_foregroundObjects.push_back(ForegroundObject::create(0, 0, ForegroundObjectType_CavePlatformCenter));
		m_foregroundObjects.push_back(ForegroundObject::create(0, 0, ForegroundObjectType_CavePlatformRight));
        
        m_foregroundObjects.push_back(ForegroundObject::create(0, 0, ForegroundObjectType_RockLarge));
        m_foregroundObjects.push_back(ForegroundObject::create(0, 0, ForegroundObjectType_RockMedium));
        m_foregroundObjects.push_back(ForegroundObject::create(0, 0, ForegroundObjectType_RockSmall));
        
        m_foregroundObjects.push_back(ForegroundObject::create(0, 0, ForegroundObjectType_StumpBig));
        m_foregroundObjects.push_back(ForegroundObject::create(0, 0, ForegroundObjectType_StumpSmall));
        
        m_foregroundObjects.push_back(ForegroundObject::create(0, 0, ForegroundObjectType_EndSign));
        
        m_foregroundObjects.push_back(ForegroundObject::create(0, 0, ForegroundObjectType_ThornsLeft));
        m_foregroundObjects.push_back(ForegroundObject::create(0, 0, ForegroundObjectType_ThornsCenterBig));
        m_foregroundObjects.push_back(ForegroundObject::create(0, 0, ForegroundObjectType_ThornsRight));
        
        m_foregroundObjects.push_back(ForegroundObject::create(0, 0, ForegroundObjectType_JumpSpringLightFlushNew));
        m_foregroundObjects.push_back(ForegroundObject::create(0, 0, ForegroundObjectType_JumpSpringLightFlush));
        m_foregroundObjects.push_back(ForegroundObject::create(0, 0, ForegroundObjectType_JumpSpringLight));
        m_foregroundObjects.push_back(ForegroundObject::create(0, 0, ForegroundObjectType_JumpSpringMedium));
        m_foregroundObjects.push_back(ForegroundObject::create(0, 0, ForegroundObjectType_JumpSpringHeavy));
        
        m_foregroundObjects.push_back(ForegroundObject::create(0, 0, ForegroundObjectType_SpikeGrassSingle));
        m_foregroundObjects.push_back(ForegroundObject::create(0, 0, ForegroundObjectType_SpikeGrassFour));
        m_foregroundObjects.push_back(ForegroundObject::create(0, 0, ForegroundObjectType_SpikeGrassEight));
        
        if (level >= 10)
        {
            m_foregroundObjects.push_back(ForegroundObject::create(0, 0, ForegroundObjectType_SpikeCaveSingle));
            m_foregroundObjects.push_back(ForegroundObject::create(0, 0, ForegroundObjectType_SpikeCaveFour));
            m_foregroundObjects.push_back(ForegroundObject::create(0, 0, ForegroundObjectType_SpikeCaveEight));
            
            m_foregroundObjects.push_back(ForegroundObject::create(0, 0, ForegroundObjectType_SpikeCaveCeilingSingle));
            m_foregroundObjects.push_back(ForegroundObject::create(0, 0, ForegroundObjectType_SpikeCaveCeilingFour));
            m_foregroundObjects.push_back(ForegroundObject::create(0, 0, ForegroundObjectType_SpikeCaveCeilingEight));
        }
        
        m_foregroundObjects.push_back(ForegroundObject::create(0, 0, ForegroundObjectType_SpikeWallSingle));
        m_foregroundObjects.push_back(ForegroundObject::create(0, 0, ForegroundObjectType_SpikeWallFour));
        m_foregroundObjects.push_back(ForegroundObject::create(0, 0, ForegroundObjectType_SpikeWallEight));
        
        m_foregroundObjects.push_back(ForegroundObject::create(0, 0, ForegroundObjectType_SpikeStar));
        m_foregroundObjects.push_back(ForegroundObject::create(0, 0, ForegroundObjectType_VerticalSaw));
        
        if (level == 10)
        {
            m_midBossForegroundObjects.push_back(ForegroundObject::create(0, 0, ForegroundObjectType_GiantShakingTree));
            m_midBossForegroundObjects.push_back(ForegroundObject::create(0, 0, ForegroundObjectType_GiantPerchTree));
        }
        else if (level > 10)
        {
            m_foregroundObjects.push_back(ForegroundObject::create(0, 0, ForegroundObjectType_GiantTree));
        }
        
        m_foregroundObjects.push_back(ForegroundObject::create(0, 0, ForegroundObjectType_MetalGrassPlatform));
        m_foregroundObjects.push_back(ForegroundObject::create(0, 0, ForegroundObjectType_MetalGrassPlatformLeft));
        m_foregroundObjects.push_back(ForegroundObject::create(0, 0, ForegroundObjectType_MetalGrassPlatformCenter));
        m_foregroundObjects.push_back(ForegroundObject::create(0, 0, ForegroundObjectType_MetalGrassPlatformRight));
        m_foregroundObjects.push_back(ForegroundObject::create(0, 0, ForegroundObjectType_WoodPlatform));
        m_foregroundObjects.push_back(ForegroundObject::create(0, 0, ForegroundObjectType_WoodBoxTop));
        m_foregroundObjects.push_back(ForegroundObject::create(0, 0, ForegroundObjectType_WoodBox));
        m_foregroundObjects.push_back(ForegroundObject::create(0, 0, ForegroundObjectType_GreenThornsLeft));
        m_foregroundObjects.push_back(ForegroundObject::create(0, 0, ForegroundObjectType_GreenThornsCenterSmall));
        m_foregroundObjects.push_back(ForegroundObject::create(0, 0, ForegroundObjectType_GreenThornsCenterBig));
        m_foregroundObjects.push_back(ForegroundObject::create(0, 0, ForegroundObjectType_GreenThornsRight));
        m_foregroundObjects.push_back(ForegroundObject::create(0, 0, ForegroundObjectType_Logs));
        m_foregroundObjects.push_back(ForegroundObject::create(0, 0, ForegroundObjectType_Stone_Bottom));
        m_foregroundObjects.push_back(ForegroundObject::create(0, 0, ForegroundObjectType_Stone_Middle));
        m_foregroundObjects.push_back(ForegroundObject::create(0, 0, ForegroundObjectType_Stone_Top));
        m_foregroundObjects.push_back(ForegroundObject::create(0, 0, ForegroundObjectType_Stone_Platform));
        m_foregroundObjects.push_back(ForegroundObject::create(0, 0, ForegroundObjectType_Stone_Square));
        m_foregroundObjects.push_back(ForegroundObject::create(0, 0, ForegroundObjectType_Floating_Platform));
        
        if (level == 21)
        {
            m_endBossForegroundObjects.push_back(ForegroundObject::create(0, 0, ForegroundObjectType_SpikedBall));
            m_endBossForegroundObjects.push_back(ForegroundObject::create(0, 0, ForegroundObjectType_SpikedBallChain));
            m_endBossForegroundObjects.push_back(ForegroundObject::create(0, 0, ForegroundObjectType_SpikedBallRollingLeft));
            m_endBossForegroundObjects.push_back(ForegroundObject::create(0, 0, ForegroundObjectType_SpikedBallRollingRight));
        }
        
        m_countHissWithMinas.push_back(CountHissWithMina::create(0, 0, -1));
        
		if (level == 21)
		{
			m_endBossSnakes.push_back(new EndBossSnake(0, 0));
		}
        
        m_enemies.push_back(new BigMushroomGround(0, 0));
        
        if (level > 10)
        {
            m_enemies.push_back(new BigMushroomCeiling(0, 0));
        }
        
        m_enemies.push_back(Enemy::create(0, 0, EnemyType_MovingSnakeGruntV1));
        m_enemies.push_back(Enemy::create(0, 0, EnemyType_MovingSnakeGruntV2));
        m_enemies.push_back(Enemy::create(0, 0, EnemyType_MovingSnakeGruntV3));
        m_enemies.push_back(Enemy::create(0, 0, EnemyType_MovingSnakeGruntV4));
        m_enemies.push_back(Enemy::create(0, 0, EnemyType_MovingSnakeGruntV5));
        m_enemies.push_back(new Sparrow(0, 0));
        m_enemies.push_back(new Toad(0, 0));
        
        if (level > 10)
        {
            m_enemies.push_back(new Fox(0, 0));
        }

		if (level == 10 || level == 21)
		{
			m_enemies.clear();
		}
        
        m_collectibleItems.push_back(new Carrot(0, 0));
        m_collectibleItems.push_back(new GoldenCarrot(0, 0));
        m_collectibleItems.push_back(new BigCarrot(0, 0));
        m_collectibleItems.push_back(new Vial(0, 0));
        
        m_midgrounds.push_back(Midground::create(0, 0, MidgroundType_TreeOne));
        m_midgrounds.push_back(Midground::create(0, 0, MidgroundType_TreeTwo));
        m_midgrounds.push_back(Midground::create(0, 0, MidgroundType_TreeThree));
        
        if (level > 10)
        {
            m_midgrounds.push_back(Midground::create(0, 0, MidgroundType_DeepCaveColumnSmall));
            m_midgrounds.push_back(Midground::create(0, 0, MidgroundType_DeepCaveColumnMedium));
            m_midgrounds.push_back(Midground::create(0, 0, MidgroundType_DeepCaveColumnBig));
        }
        
        m_midgrounds.push_back(Midground::create(0, 0, MidgroundType_Plant));
        m_midgrounds.push_back(Midground::create(0, 0, MidgroundType_Metal_Tower_Section));
        m_midgrounds.push_back(Midground::create(0, 0, MidgroundType_Billboard_Count_Hiss));
        m_midgrounds.push_back(Midground::create(0, 0, MidgroundType_Billboard_Slag_Town));
        m_midgrounds.push_back(Midground::create(0, 0, MidgroundType_Billboard_Jon_Wanted));
        m_midgrounds.push_back(Midground::create(0, 0, MidgroundType_Hill));
        m_midgrounds.push_back(Midground::create(0, 0, MidgroundType_Train_Car));
        m_midgrounds.push_back(Midground::create(0, 0, MidgroundType_Short_Stump));
        m_midgrounds.push_back(Midground::create(0, 0, MidgroundType_Tall_Stump));
        m_midgrounds.push_back(Midground::create(0, 0, MidgroundType_Thin_Tall_Tree));
        m_midgrounds.push_back(Midground::create(0, 0, MidgroundType_Thin_Short_Tree));
        m_midgrounds.push_back(Midground::create(0, 0, MidgroundType_Stone_Square));
        m_midgrounds.push_back(Midground::create(0, 0, MidgroundType_Stone_Diamond));
        m_midgrounds.push_back(Midground::create(0, 0, MidgroundType_Wall));
        m_midgrounds.push_back(Midground::create(0, 0, MidgroundType_Roof));
        
        if (level == 21)
        {
            m_midgrounds.push_back(Midground::create(0, 0, MidgroundType_DiagonalChain));
            m_midgrounds.push_back(Midground::create(0, 0, MidgroundType_StraightChain));
        }
        
        m_foregroundCoverObjects.push_back(ForegroundCoverObject::create(0, 0, ForegroundCoverObjectType_Tree));
        m_foregroundCoverObjects.push_back(ForegroundCoverObject::create(0, 0, ForegroundCoverObjectType_Plant));
        m_foregroundCoverObjects.push_back(ForegroundCoverObject::create(0, 0, ForegroundCoverObjectType_Bush));
        m_foregroundCoverObjects.push_back(ForegroundCoverObject::create(0, 0, ForegroundCoverObjectType_Ferns));
        m_foregroundCoverObjects.push_back(ForegroundCoverObject::create(0, 0, ForegroundCoverObjectType_Wall));
        m_foregroundCoverObjects.push_back(ForegroundCoverObject::create(0, 0, ForegroundCoverObjectType_Wall_Bottom));
        m_foregroundCoverObjects.push_back(ForegroundCoverObject::create(0, 0, ForegroundCoverObjectType_Wall_Window));
        m_foregroundCoverObjects.push_back(ForegroundCoverObject::create(0, 0, ForegroundCoverObjectType_Wall_Window_Bottom));
        m_foregroundCoverObjects.push_back(ForegroundCoverObject::create(0, 0, ForegroundCoverObjectType_Roof_Side_Left));
        m_foregroundCoverObjects.push_back(ForegroundCoverObject::create(0, 0, ForegroundCoverObjectType_Roof_Side_Right));
        m_foregroundCoverObjects.push_back(ForegroundCoverObject::create(0, 0, ForegroundCoverObjectType_Roof_Plain));
        m_foregroundCoverObjects.push_back(ForegroundCoverObject::create(0, 0, ForegroundCoverObjectType_Roof_Chimney));
        m_foregroundCoverObjects.push_back(ForegroundCoverObject::create(0, 0, ForegroundCoverObjectType_Wall_PassThrough));
        m_foregroundCoverObjects.push_back(ForegroundCoverObject::create(0, 0, ForegroundCoverObjectType_Wall_Bottom_PassThrough));
        m_foregroundCoverObjects.push_back(ForegroundCoverObject::create(0, 0, ForegroundCoverObjectType_Wall_Window_PassThrough));
        m_foregroundCoverObjects.push_back(ForegroundCoverObject::create(0, 0, ForegroundCoverObjectType_Wall_Window_Bottom_PassThrough));
        
        m_extraForegroundObjects.push_back(ExtraForegroundObject::create(0, 0, ForegroundObjectType_SpikeTower));
    }
    else if (world == 2)
    {
        // TODO, Desert
    }
    else if (world == 3)
    {
        // TODO, Slag Town
    }
    else if (world == 4)
    {
        // TODO, Volcano
    }
    else if (world == 5)
    {
        // TODO, Castle
    }
    
    m_jons.push_back(new Jon(0, 0));
    
    float eWidth = m_fWidth * 0.6f;
    float eHeight = m_fHeight / 6;
    float eX = CAM_WIDTH - m_fWidth / 2 + 0.4f;
    float eY = eHeight / 2;
    
    int i = EntityUtils::boxInAll(m_midgrounds, eX, eY, eWidth, eHeight, 0);
    i = EntityUtils::boxInAll(m_grounds, eX, eY, eWidth, eHeight, i);
    i = EntityUtils::boxInAll(m_pits, eX, eY, eWidth, eHeight, i);
    i = EntityUtils::boxInAll(m_exitGrounds, eX, eY, eWidth, eHeight, i);
    i = EntityUtils::boxInAll(m_holes, eX, eY, eWidth, eHeight, i);
    i = EntityUtils::boxInAll(m_foregroundObjects, eX, eY, eWidth, eHeight, i);
    i = EntityUtils::boxInAll(m_midBossForegroundObjects, eX, eY, eWidth, eHeight, i);
    i = EntityUtils::boxInAll(m_endBossForegroundObjects, eX, eY, eWidth, eHeight, i);
	i = EntityUtils::boxInAll(m_countHissWithMinas, eX, eY, eWidth, eHeight, i);
    i = EntityUtils::boxInAll(m_endBossSnakes, eX, eY, eWidth, eHeight, i);
    i = EntityUtils::boxInAll(m_enemies, eX, eY, eWidth, eHeight, i);
    i = EntityUtils::boxInAll(m_collectibleItems, eX, eY, eWidth, eHeight, i);
    i = EntityUtils::boxInAll(m_jons, eX, eY, eWidth, eHeight, i);
    i = EntityUtils::boxInAll(m_extraForegroundObjects, eX, eY, eWidth, eHeight, i);
    i = EntityUtils::boxInAll(m_foregroundCoverObjects, eX, eY, eWidth, eHeight, i);
    
    m_fEntitiesHeight = fmaxf((i * eHeight), m_fHeight);
    
    if (m_fEntitiesCameraPos > (m_fEntitiesHeight - getHeight()))
    {
        m_fEntitiesCameraPos = m_fEntitiesHeight - getHeight();
    }
}

int LevelEditorEntitiesPanel::handleTouch(ScreenEvent& te, Vector2D& touchPoint, Game& game, Vector2D& camPos, PhysicalEntity** lastAddedEntity)
{
    if (m_isOpen && touchPoint.getX() > (CAM_WIDTH - getWidth()))
    {
        switch (te.getType())
        {
            case ScreenEventType_DOWN:
            {
                if(touchPoint.getX() > m_closeButton->getLeft() + m_closeButton->getWidth())
                {
                    m_touchPointDown->set(touchPoint.getX(), touchPoint.getY());
                    m_touchPointDown2->set(touchPoint.getX(), touchPoint.getY());
                    
                    return LEVEL_EDITOR_ENTITIES_PANEL_RC_HANDLED;
                }
            }
                break;
            case ScreenEventType_DRAGGED:
                m_fEntitiesCameraPos += (m_touchPointDown->getY() - touchPoint.getY()) * 3;
                if (m_fEntitiesCameraPos < 0)
                {
                    m_fEntitiesCameraPos = 0;
                }
                else if (m_fEntitiesCameraPos > (m_fEntitiesHeight - getHeight()))
                {
                    m_fEntitiesCameraPos = m_fEntitiesHeight - getHeight();
                }
                
                m_touchPointDown->set(touchPoint.getX(), touchPoint.getY());
                
                return LEVEL_EDITOR_ENTITIES_PANEL_RC_HANDLED;
            case ScreenEventType_UP:
            {
                if (OverlapTester::isPointInNGRect(touchPoint, *m_closeButton))
                {
                    m_position.setX(CAM_WIDTH + (3.76608187134503f - 1.894736842105263f) / 2);
                    
                    m_isOpen = false;
                    
                    return LEVEL_EDITOR_ENTITIES_PANEL_RC_HANDLED;
                }
                else if (touchPoint.getY() < m_touchPointDown2->getY() + 0.25f && touchPoint.getY() > m_touchPointDown2->getY() - 0.25f)
                {
                    touchPoint.add(0, m_fEntitiesCameraPos);
                    
                    int gridX = (camPos.getX() + ZOOMED_OUT_CAM_WIDTH / 2) / GRID_CELL_SIZE;
                    int gridY = GAME_HEIGHT / 2 / GRID_CELL_SIZE;
                    
                    if (EntityUtils::isTouchingEntityForPlacement(m_midgrounds, game.getMidgrounds(), gridX, gridY, lastAddedEntity, touchPoint)
                        || EntityUtils::isTouchingEntityForPlacement(m_grounds, game.getGrounds(), gridX, gridY, lastAddedEntity, touchPoint)
                        || EntityUtils::isTouchingEntityForPlacement(m_pits, game.getPits(), gridX, gridY, lastAddedEntity, touchPoint)
                        || EntityUtils::isTouchingEntityForPlacement(m_exitGrounds, game.getExitGrounds(), gridX, gridY, lastAddedEntity, touchPoint)
                        || EntityUtils::isTouchingEntityForPlacement(m_holes, game.getHoles(), gridX, gridY, lastAddedEntity, touchPoint)
                        || EntityUtils::isTouchingEntityForPlacement(m_foregroundObjects, game.getForegroundObjects(), gridX, gridY, lastAddedEntity, touchPoint)
                        || EntityUtils::isTouchingEntityForPlacement(m_midBossForegroundObjects, game.getMidBossForegroundObjects(), gridX, gridY, lastAddedEntity, touchPoint)
                        || EntityUtils::isTouchingEntityForPlacement(m_endBossForegroundObjects, game.getEndBossForegroundObjects(), gridX, gridY, lastAddedEntity, touchPoint)
                        || EntityUtils::isTouchingEntityForPlacement(m_countHissWithMinas, game.getCountHissWithMinas(), gridX, gridY, lastAddedEntity, touchPoint)
                        || EntityUtils::isTouchingEntityForPlacement(m_endBossSnakes, game.getEndBossSnakes(), gridX, gridY, lastAddedEntity, touchPoint)
                        || EntityUtils::isTouchingEntityForPlacement(m_enemies, game.getEnemies(), gridX, gridY, lastAddedEntity, touchPoint)
                        || EntityUtils::isTouchingEntityForPlacement(m_collectibleItems, game.getCollectibleItems(), gridX, gridY, lastAddedEntity, touchPoint)
                        || EntityUtils::isTouchingEntityForPlacement(m_jons, game.getJons(), gridX, gridY, lastAddedEntity, touchPoint)
                        || EntityUtils::isTouchingEntityForPlacement(m_extraForegroundObjects, game.getExtraForegroundObjects(), gridX, gridY, lastAddedEntity, touchPoint)
                        || EntityUtils::isTouchingEntityForPlacement(m_foregroundCoverObjects, game.getForegroundCoverObjects(), gridX, gridY, lastAddedEntity, touchPoint))
                    {
                        return LEVEL_EDITOR_ENTITIES_PANEL_RC_ENTITY_ADDED;
                    }
                }
            }
        }
    }
    else
    {
		if (OverlapTester::isPointInNGRect(touchPoint, *m_openButton))
		{
			if (te.getType() == ScreenEventType_UP)
			{
				m_position.setX(CAM_WIDTH - getWidth() / 2);

				m_isOpen = true;
			}

			return LEVEL_EDITOR_ENTITIES_PANEL_RC_HANDLED;
		}
    }
    
    return LEVEL_EDITOR_ENTITIES_PANEL_RC_UNHANDLED;
}

std::vector<Midground *>& LevelEditorEntitiesPanel::getMidgrounds()
{
    return m_midgrounds;
}

std::vector<Ground *>& LevelEditorEntitiesPanel::getGrounds()
{
    return m_grounds;
}

std::vector<Ground *>& LevelEditorEntitiesPanel::getPits()
{
    return m_pits;
}

std::vector<ExitGround *>& LevelEditorEntitiesPanel::getExitGrounds()
{
    return m_exitGrounds;
}

std::vector<Hole *>& LevelEditorEntitiesPanel::getHoles()
{
    return m_holes;
}

std::vector<ForegroundObject *>& LevelEditorEntitiesPanel::getForegroundObjects()
{
    return m_foregroundObjects;
}

std::vector<ForegroundObject *>& LevelEditorEntitiesPanel::getMidBossForegroundObjects()
{
    return m_midBossForegroundObjects;
}

std::vector<ForegroundObject *>& LevelEditorEntitiesPanel::getEndBossForegroundObjects()
{
    return m_endBossForegroundObjects;
}

std::vector<CountHissWithMina *>& LevelEditorEntitiesPanel::getCountHissWithMinas()
{
	return m_countHissWithMinas;
}

std::vector<EndBossSnake *>& LevelEditorEntitiesPanel::getEndBossSnakes()
{
    return m_endBossSnakes;
}

std::vector<Enemy *>& LevelEditorEntitiesPanel::getEnemies()
{
    return m_enemies;
}

std::vector<CollectibleItem *>& LevelEditorEntitiesPanel::getCollectibleItems()
{
    return m_collectibleItems;
}

std::vector<Jon *>& LevelEditorEntitiesPanel::getJons()
{
    return m_jons;
}

std::vector<ExtraForegroundObject *>& LevelEditorEntitiesPanel::getExtraForegroundObjects()
{
    return m_extraForegroundObjects;
}

std::vector<ForegroundCoverObject *>& LevelEditorEntitiesPanel::getForegroundCoverObjects()
{
    return m_foregroundCoverObjects;
}

float LevelEditorEntitiesPanel::getEntitiesCameraPos()
{
    return m_fEntitiesCameraPos;
}

bool LevelEditorEntitiesPanel::isOpen()
{
    return m_isOpen;
}

RTTI_IMPL(LevelEditorEntitiesPanel, PhysicalEntity);
