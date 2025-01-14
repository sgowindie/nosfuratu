//
//  Enemy.cpp
//  nosfuratu
//
//  Created by Stephen Gowen on 2/9/16.
//  Copyright (c) 2017 Noctis Games. All rights reserved.
//

#include "pch.h"

#include "Enemy.h"

#include "Game.h"
#include "Jon.h"
#include "EnemySpirit.h"

#include "OverlapTester.h"
#include "Assets.h"
#include "EntityUtils.h"
#include "NGAudioEngine.h"
#include "GameConstants.h"

#include <math.h>

Enemy* Enemy::create(int gridX, int gridY, int type)
{
    EnemyType et = (EnemyType)type;
    
    switch (et)
    {
        case EnemyType_MushroomGround:
            return new MushroomGround(gridX, gridY);
        case EnemyType_MushroomCeiling:
            return new MushroomCeiling(gridX, gridY);
        case EnemyType_SnakeGrunt:
            return new SnakeGrunt(gridX, gridY);
        case EnemyType_Sparrow:
            return new Sparrow(gridX, gridY);
        case EnemyType_Toad:
            return new Toad(gridX, gridY);
        case EnemyType_Fox:
            return new Fox(gridX, gridY);
        case EnemyType_BigMushroomGround:
            return new BigMushroomGround(gridX, gridY);
        case EnemyType_BigMushroomCeiling:
            return new BigMushroomCeiling(gridX, gridY);
        case EnemyType_MovingSnakeGruntV1: // Forest Green
            return new MovingSnakeGrunt(gridX, gridY, 2, 2, false, et, 0.13333333333333f, 0.54509803921569f, 0.13333333333333f);
        case EnemyType_MovingSnakeGruntV2: // Jungle green Green
            return new MovingSnakeGrunt(gridX, gridY, 4, 4, false, et, 0.16078431372549f, 0.67058823529412f, 0.52941176470588f);
        case EnemyType_MovingSnakeGruntV3: // Mantis Green
            return new MovingSnakeGrunt(gridX, gridY, 8, 8, false, et, 0.45490196078431f, 0.76470588235294f, 0.39607843137255f);
        case EnemyType_MovingSnakeGruntV4: // Fire Brick Red
            return new MovingSnakeGrunt(gridX, gridY, 4, 4, true, et, 0.69803921568627f, 0.13333333333333f, 0.13333333333333f);
        case EnemyType_MovingSnakeGruntV5: // Lust Red
            return new MovingSnakeGrunt(gridX, gridY, 8, 8, true, et, 0.90196078431373f, 0.12549019607843f, 0.12549019607843f);
    }
    
    assert(false);
}

Enemy::Enemy(int gridX, int gridY, int gridWidth, int gridHeight, float boundsX, float boundsY, float boundsWidth, float boundsHeight, EnemyType type, EnemySpiritType enemySpiritType, short deathSoundId) : GridLockedPhysicalEntity(gridX, gridY, gridWidth, gridHeight, boundsX, boundsY, boundsWidth, boundsHeight), m_enemySpirit(nullptr), m_type(type), m_enemySpiritType(enemySpiritType), m_color(1, 1, 1, 2), m_fEnemySpiritStateTime(0), m_fXOfDeath(0), m_fYOfDeath(0), m_deathSoundId(deathSoundId), m_isDying(false), m_isDead(false), m_game(nullptr)
{
    // Empty
}

void Enemy::update(float deltaTime)
{
    updateBounds();
    
    if (m_isDead)
    {
        handleDead(deltaTime);
    }
    else if (m_isDying)
    {
        handleDying(deltaTime);
    }
    else
    {
        handleAlive(deltaTime);
    }
}

void Enemy::updateBounds()
{
    GridLockedPhysicalEntity::updateBounds();
    
    if (m_isDying)
    {
        // Bye bye!
        Vector2D &lowerLeft = getMainBounds().getLowerLeft();
        lowerLeft.setY(1337);
    }
}

void Enemy::triggerHit()
{
    m_isDying = true;
    
    m_fXOfDeath = getMainBounds().getLeft() + getMainBounds().getWidth() / 2;
    m_fYOfDeath = getMainBounds().getBottom() + getMainBounds().getHeight() / 2;
    
    NG_AUDIO_ENGINE->playSound(m_deathSoundId);
}

bool Enemy::isEntityLanding(PhysicalEntity* entity, float deltaTime)
{
    Jon *jon = nullptr;
    if (entity->getRTTI().derivesFrom(Jon::rtti))
    {
        jon = reinterpret_cast<Jon *>(entity);
        if (calcIsJonLanding(jon, deltaTime))
        {
            triggerHit();
            
            float boost = fmaxf(fabsf(jon->getVelocity().getY()) / 1.5f, 6);
            
            jon->onEnemyDestroyed();
            jon->triggerBoostOffEnemy(boost);
        }
    }
    
    return false;
}

int Enemy::getEntityLandingPriority()
{
    return 0;
}

bool Enemy::isJonBlockedAbove(Jon& jon, float deltaTime)
{
    return false;
}

bool Enemy::isJonHittingHorizontally(Jon& jon, float deltaTime)
{
    NGRect& bounds = jon.getMainBounds();
    
    if (OverlapTester::doNGRectsOverlap(bounds, getMainBounds()))
    {
        triggerHit();
        
        jon.onEnemyDestroyed();
        
        return true;
    }
    
    return false;
}

bool Enemy::isJonHittingFromBelow(Jon& jon, float deltaTime)
{
    NGRect& bounds = jon.getMainBounds();
    
    if (OverlapTester::doNGRectsOverlap(bounds, getMainBounds()))
    {
        triggerHit();
        
        jon.onEnemyDestroyed();
        
        return true;
    }
    
    return false;
}

Enemy::~Enemy()
{
    delete m_enemySpirit;
    m_enemySpirit = nullptr;
}

bool Enemy::hasSpirit()
{
    return m_enemySpirit ? true : false;
}

EnemySpirit& Enemy::getSpirit()
{
    return *m_enemySpirit;
}

Color Enemy::getColor()
{
    return m_color;
}

bool Enemy::isDying()
{
    return m_isDying;
}

bool Enemy::isDead()
{
    return m_isDead;
}

void Enemy::setGame(Game* game)
{
    m_game = game;
}

EnemyType Enemy::getType()
{
    return m_type;
}

#pragma mark protected

void Enemy::handleAlive(float deltaTime)
{
    PhysicalEntity::update(deltaTime);

	handleJon();
}

void Enemy::handleDying(float deltaTime)
{
    m_color.alpha -= deltaTime * 4;
    
    if (m_color.alpha < 1)
    {
        m_color.alpha = 1;
        m_isDead = true;
        
        m_enemySpirit = EnemySpirit::create(m_fXOfDeath, m_fYOfDeath, m_enemySpiritType);
    }
}

void Enemy::handleDead(float deltaTime)
{
    m_color.alpha -= deltaTime * 2;
    if (m_color.alpha < 0)
    {
        m_color.alpha = 0;
    }
    
    m_fEnemySpiritStateTime += deltaTime;
    if (m_fEnemySpiritStateTime > 1.00f)
    {
        m_isRequestingDeletion = true;
    }
    
    if (m_enemySpirit)
    {
        m_enemySpirit->update(deltaTime);
    }
}

bool Enemy::calcIsJonLanding(Jon *jon, float deltaTime)
{
    float jonVelocityY = jon->getVelocity().getY();
    
    if (jonVelocityY <= 0)
    {
		float entityYDelta = fabsf(jonVelocityY * deltaTime);

		NGRect enemyBounds = NGRect(getMainBounds().getLeft(), getMainBounds().getBottom(), getMainBounds().getWidth(), getMainBounds().getHeight());

		enemyBounds.setHeight(enemyBounds.getHeight() + entityYDelta);

        if (OverlapTester::doNGRectsOverlap(jon->getMainBounds(), enemyBounds))
        {
            float jonBottom = jon->getMainBounds().getBottom();
            
            float itemBottom = enemyBounds.getBottom();
            float padding = enemyBounds.getHeight() * 0.05f;
            float itemBottomReq = itemBottom + padding;
            
            if (jonBottom > itemBottomReq)
            {
				jon->getPosition().setY(getMainBounds().getTop() + jon->getMainBounds().getHeight() / 2 * 1.01f);
				jon->updateBounds();

                return true;
            }
        }
    }
    
    return false;
}

void Enemy::handleJonInKillRange(Jon& jon)
{
    jon.kill();
}

void Enemy::handleJon()
{
	Jon& jon = m_game->getJon();

    if (OverlapTester::doNGRectsOverlap(jon.getMainBounds(), getMainBounds()))
    {
        if (jon.isConsumed()
            || jon.getAbilityState() == ABILITY_UPWARD_THRUST)
        {
            return;
        }
        
        if (jon.getAbilityState() == ABILITY_DASH
            && jon.getAbilityStateTime() < 0.5f)
        {
            return;
        }
        
        if (jon.getPosition().getY() > (getPosition().getY() + getHeight() / 2))
        {
            return;
        }
        
        handleJonInKillRange(jon);
    }
}

#pragma mark subclasses

Mushroom::Mushroom(int gridX, int gridY, int gridWidth, int gridHeight, float boundsX, float boundsY, float boundsWidth, float boundsHeight, EnemyType type) : Enemy(gridX, gridY, gridWidth, gridHeight, boundsX, boundsY, boundsWidth, boundsHeight, type, EnemySpiritType_None, SOUND_ID_NONE), m_isBeingBouncedOn(false), m_isBouncingBack(false)
{
    // Empty
}

void Mushroom::handleAlive(float deltaTime)
{
    Entity::update(deltaTime);
    
    if (m_fStateTime > 0.4f && (m_isBouncingBack || m_isBeingBouncedOn))
    {
		m_isBouncingBack = false;
        m_isBeingBouncedOn = false;
    }
    
    Jon& jon = m_game->getJon();
    
    if (OverlapTester::doNGRectsOverlap(jon.getMainBounds(), getMainBounds()))
    {
        jon.triggerBounceBackOffEnemy(-9);
        
        m_fStateTime = 0;
        
        m_isBouncingBack = true;
        
        NG_AUDIO_ENGINE->playSound(SOUND_ID_MUSHROOM_BOUNCE);
    }
}

bool Mushroom::isJonHittingHorizontally(Jon& jon, float deltaTime)
{
    return false;
}

bool Mushroom::isJonHittingFromBelow(Jon& jon, float deltaTime)
{
    return false;
}

bool Mushroom::isBeingBouncedOn()
{
    return m_isBeingBouncedOn;
}

bool Mushroom::isBouncingBack()
{
    return m_isBouncingBack;
}

MushroomGround::MushroomGround(int gridX, int gridY) : Mushroom(gridX, gridY, 7, 8, 0, 0, 1, 0.796875f, EnemyType_MushroomGround)
{
    // Empty
}

bool MushroomGround::isEntityLanding(PhysicalEntity* entity, float deltaTime)
{
    Jon *jon = nullptr;
    if (entity->getRTTI().derivesFrom(Jon::rtti))
    {
        jon = reinterpret_cast<Jon *>(entity);
        if (calcIsJonLanding(jon, deltaTime))
        {
			jon->triggerBoostOffEnemy(18);
            
            m_fStateTime = 0;
            
            NG_AUDIO_ENGINE->playSound(SOUND_ID_MUSHROOM_BOUNCE);
        }
    }

	return false;
}

MushroomCeiling::MushroomCeiling(int gridX, int gridY) : Mushroom(gridX, gridY, 7, 8, 0, 0.203125f, 1, 0.796875f, EnemyType_MushroomCeiling)
{
    // Empty
}

bool MushroomCeiling::isJonBlockedAbove(Jon& jon, float deltaTime)
{
    float entityVelocityY = jon.getVelocity().getY();
    
    if (entityVelocityY > 0 && OverlapTester::doNGRectsOverlap(jon.getMainBounds(), getMainBounds()))
    {
        jon.getPosition().sub(0, jon.getVelocity().getY() * deltaTime);
        jon.updateBounds();
        
        jon.triggerBounceDownardsOffEnemy(-18);

		m_fStateTime = 0;
        
        NG_AUDIO_ENGINE->playSound(SOUND_ID_MUSHROOM_BOUNCE);
        
        return true;
    }
    
    return false;
}

SnakeGrunt::SnakeGrunt(int gridX, int gridY) : Enemy(gridX, gridY, 8, 6, 0, 0, 1, 0.79166666666667f, EnemyType_SnakeGrunt, EnemySpiritType_Snake, SOUND_ID_SNAKE_DEATH)
{
    // Empty
}

Sparrow::Sparrow(int gridX, int gridY) : Enemy(gridX, gridY, 10, 10, 0, 0, 1, 0.71875f, EnemyType_Sparrow, EnemySpiritType_Sparrow, SOUND_ID_SPARROW_DEATH), m_fOriginalY(0), m_isOnScreen(false)
{
    m_fOriginalY = m_position.getY();
}

void Sparrow::updateBounds()
{
    Enemy::updateBounds();
    
	NGRect& camBounds = *m_game->getCameraBounds();

	if (camBounds.getWidth() > CAM_WIDTH)
	{
		return;
	}

    if (OverlapTester::doNGRectsOverlap(camBounds, getMainBounds()))
    {
        if (!m_isOnScreen)
        {
            m_isOnScreen = true;
            
            m_position.setY(m_fOriginalY);
			m_acceleration.setY(1);
            
            NG_AUDIO_ENGINE->playSound(SOUND_ID_SPARROW_FLY, true);
        }
    }
    else if (m_isOnScreen)
    {
        m_velocity.setY(0);
        m_acceleration.setY(0);
        m_isOnScreen = false;
        
        NG_AUDIO_ENGINE->stopSound(SOUND_ID_SPARROW_FLY);
    }
}

void Sparrow::onMoved()
{
    m_fOriginalY = m_position.getY();
}

void Sparrow::handleAlive(float deltaTime)
{
    PhysicalEntity::update(deltaTime);

	if (m_isOnScreen)
	{
		if (m_position.getY() > (m_fOriginalY + 0.5f))
		{
			m_velocity.setY(0);
			m_acceleration.setY(-1);
		}
		else if (m_position.getY() < (m_fOriginalY - 0.5f))
		{
			m_velocity.setY(0);
			m_acceleration.setY(1);
		}
	}

	handleJon();
}

Toad::Toad(int gridX, int gridY) : Enemy(gridX, gridY, 32, 16, 0.58984375f, 0.109375f, 0.33984375f, 0.3359375f, EnemyType_Toad, EnemySpiritType_None, SOUND_ID_TOAD_DEATH),
m_isDeadPart1(false),
m_isEating(false),
m_hasSwallowedJon(false),
m_isJonVampire(false)
{
    // Empty
}

bool Toad::isDeadPart1()
{
    return m_isDeadPart1;
}

bool Toad::isEating()
{
    return m_isEating;
}

bool Toad::hasSwallowedJon()
{
    return m_hasSwallowedJon;
}

bool Toad::isJonVampire()
{
    return m_isJonVampire;
}

void Toad::handleAlive(float deltaTime)
{
    PhysicalEntity::update(deltaTime);
    
    Jon& jon = m_game->getJon();
    
    if (m_isEating)
    {
        if (m_hasSwallowedJon)
        {
            // TODO ?
        }
        else
        {
            if (m_fStateTime > 0.40f)
            {
                m_hasSwallowedJon = true;
                
                jon.getPosition().set(getMainBounds().getLeft() + getMainBounds().getWidth() / 2, getPosition().getY());
                jon.updateBounds();
                
                if (!m_isJonVampire)
                {
                    jon.kill();
                }
            }
            else if (m_fStateTime > 0.10f)
            {
                if (jon.getMainBounds().getBottom() < getMainBounds().getTop()
                    && jon.getMainBounds().getRight() > getMainBounds().getLeft() - 1.2f
                    && jon.getMainBounds().getRight() < getMainBounds().getLeft())
                {
                    if (!jon.isConsumed())
                    {
                        jon.consume();
                    }
                }
                else
                {
                    m_fStateTime = 0;
                    m_isEating = false;
                }
            }
        }
    }
    else
    {
        float jonPredictedRight = jon.getMainBounds().getRight() + jon.getVelocity().getX() * 0.10f;
        if (jon.getMainBounds().getBottom() > (getMainBounds().getBottom() - 1.0f)
			&& jon.getMainBounds().getTop() < (getMainBounds().getTop() + 2.0f)
            && jonPredictedRight > getMainBounds().getLeft() - 1.2f
            && jonPredictedRight < getMainBounds().getLeft()
            && !jon.isConsumed())
        {
            m_fStateTime = 0;
            m_isEating = true;
            
            m_isJonVampire = jon.shouldUseVampireFormForConsumeAnimation();
            
            NG_AUDIO_ENGINE->playSound(SOUND_ID_TOAD_EAT);
        }
		else
		{
			handleJon();
		}
    }
}

void Toad::handleDying(float deltaTime)
{
    m_fStateTime = 0;
    m_isDead = true;
    m_isDeadPart1 = true;
}

void Toad::handleDead(float deltaTime)
{
    m_fStateTime += deltaTime;
    
    if (m_isDeadPart1)
    {
        if (m_hasSwallowedJon && m_isJonVampire)
        {
            if (m_fStateTime > 0.10f)
            {
                m_fStateTime = 0;
                m_isDeadPart1 = false;
            }
        }
        else
        {
            if (m_fStateTime > 0.25f)
            {
                m_fStateTime = 0;
                m_isDeadPart1 = false;
            }
        }
    }
    else
    {
        if (m_fStateTime > 0.35f)
        {
            m_isRequestingDeletion = true;
        }
    }
}

void Toad::handleJonInKillRange(Jon& jon)
{
    m_fStateTime = 0.50f;
    m_isEating = true;
    
    m_isJonVampire = jon.shouldUseVampireFormForConsumeAnimation();
    
    NG_AUDIO_ENGINE->playSound(SOUND_ID_TOAD_EAT);
    
    if (!jon.isConsumed())
    {
        jon.consume();
    }
    
    jon.getPosition().set(getMainBounds().getLeft() + getMainBounds().getWidth() / 2, getPosition().getY());
    jon.updateBounds();
    
    if (!m_isJonVampire)
    {
        jon.kill();
    }
}

Fox::Fox(int gridX, int gridY) : Enemy(gridX, gridY, 16, 16, 0.25f, 0.09375f, 0.50f, 0.734375f, EnemyType_Fox, EnemySpiritType_None, SOUND_ID_FOX_DEATH),
m_isHitting(false),
m_isLeft(true),
m_isBeingHit(false),
m_isOnScreen(false)
{
    // Empty
}

void Fox::updateBounds()
{
	Enemy::updateBounds();

	NGRect& camBounds = *m_game->getCameraBounds();

	if (camBounds.getWidth() > CAM_WIDTH)
	{
		return;
	}

	if (!m_isOnScreen)
	{
		if (OverlapTester::doNGRectsOverlap(camBounds, getMainBounds()))
		{
			m_isOnScreen = true;
		}
	}
}

bool Fox::isEntityLanding(PhysicalEntity* entity, float deltaTime)
{
    Jon *jon = nullptr;
    if (entity->getRTTI().derivesFrom(Jon::rtti))
    {
        jon = reinterpret_cast<Jon *>(entity);
        if (calcIsJonLanding(jon, deltaTime))
        {
            float jonVelocityY = jon->getVelocity().getY();
            float jonAccelY = jon->getAcceleration().getY();
            
            if (jonAccelY < GAME_GRAVITY * 2)
            {
                triggerHit();
                
                jon->onEnemyDestroyed();
            }
            
            m_fStateTime = 0;
            m_isBeingHit = true;
            m_isHitting = false;
            m_velocity.setX(0);
            
            float boost = fmaxf(fabsf(jonVelocityY) / 1.5f, 6);
            
            jon->triggerBoostOffEnemy(boost);
            
            NG_AUDIO_ENGINE->playSound(SOUND_ID_FOX_BOUNCED_ON);
        }
    }
    
    return false;
}

bool Fox::isHitting()
{
    return m_isHitting;
}

bool Fox::isLeft()
{
    return m_isLeft;
}

bool Fox::isBeingHit()
{
    return m_isBeingHit;
}

void Fox::handleAlive(float deltaTime)
{
    PhysicalEntity::update(deltaTime);

	if (!m_isOnScreen)
	{
		return;
	}
    
    if (m_isBeingHit)
    {
        if (m_fStateTime > 0.30f)
        {
            m_isBeingHit = false;
        }
        
        return;
    }
    
	bool isGrounded;
	if ((isGrounded = m_game->isEntityGrounded(this, deltaTime)))
	{
		m_acceleration.setY(0);
		m_velocity.setY(0);
	}
	else
	{
		m_acceleration.setY(GAME_GRAVITY);
	}

	if (EntityUtils::isBlockedOnLeft(this, m_game->getForegroundObjects(), deltaTime)
		|| EntityUtils::isBlockedOnLeft(this, m_game->getGrounds(), deltaTime)
		|| EntityUtils::isBlockedOnRight(this, m_game->getForegroundObjects(), deltaTime)
		|| EntityUtils::isBlockedOnRight(this, m_game->getGrounds(), deltaTime))
	{
		if (!isGrounded)
		{
			m_velocity.setX(0);
		}
	}

    Jon& jon = m_game->getJon();
    
    if (m_isHitting)
    {
        if (m_fStateTime > 0.55f)
        {
            m_velocity.setX(0);
            m_isHitting = false;
        }
    }
    else
    {
        if (jon.getMainBounds().getTop() > getMainBounds().getBottom()
			&& jon.getMainBounds().getBottom() < getMainBounds().getTop()
            && jon.getMainBounds().getRight() > getMainBounds().getLeft() - 4
            && jon.getMainBounds().getRight() < getMainBounds().getLeft())
        {
            m_fStateTime = 0;
            m_isHitting = true;
            m_isLeft = true;
            
            m_velocity.setX(-RABBIT_DEFAULT_MAX_SPEED);
            
            NG_AUDIO_ENGINE->playSound(SOUND_ID_FOX_STRIKE);
        }
        else if (jon.getMainBounds().getTop() > getMainBounds().getBottom()
			&& jon.getMainBounds().getBottom() < getMainBounds().getTop()
			&& jon.getMainBounds().getLeft() < getMainBounds().getRight() + 4
			&& jon.getMainBounds().getLeft() > getMainBounds().getRight())
        {
            m_fStateTime = 0;
            m_isHitting = true;
            m_isLeft = false;
            
            m_velocity.setX(RABBIT_DEFAULT_MAX_SPEED);
            
            NG_AUDIO_ENGINE->playSound(SOUND_ID_FOX_STRIKE);
        }
        else
        {
            if (m_fStateTime > 0.45f)
            {
                m_fStateTime = 0;
                m_isLeft = !m_isLeft;
                m_velocity.setX(m_isLeft ? -3.2f : 3.2f);
            }
            else if (m_fStateTime > 0.30f)
            {
                m_velocity.setX(0);
            }
        }
    }

	handleJon();
}

void Fox::handleDying(float deltaTime)
{
    m_fStateTime = 0;
    m_isDead = true;
    
    float halfHeight = m_fHeight / 2;
    m_fHeight *= 2;
    m_position.add(0, halfHeight);
    updateBounds();
}

void Fox::handleDead(float deltaTime)
{
    m_fStateTime += deltaTime;
    
    if (m_fStateTime > 0.50f)
    {
        m_isRequestingDeletion = true;
    }
}

BigMushroomGround::BigMushroomGround(int gridX, int gridY) : Mushroom(gridX, gridY, 16, 13, 0, 0.05f, 1, 0.95f, EnemyType_BigMushroomGround)
{
    // Empty
}

void BigMushroomGround::handleAlive(float deltaTime)
{
    Mushroom::handleAlive(deltaTime);
    
    m_fStateTime += deltaTime;
}

bool BigMushroomGround::isEntityLanding(PhysicalEntity* entity, float deltaTime)
{
    Jon *jon = nullptr;
    if (entity->getRTTI().derivesFrom(Jon::rtti))
    {
        jon = reinterpret_cast<Jon *>(entity);
        if (calcIsJonLanding(jon, deltaTime))
        {
            jon->triggerBoostOffEnemy(18);
            
            m_fStateTime = 0;
            
            m_isBeingBouncedOn = true;
            
            NG_AUDIO_ENGINE->playSound(SOUND_ID_MUSHROOM_BOUNCE);
        }
    }
    
    return false;
}

BigMushroomCeiling::BigMushroomCeiling(int gridX, int gridY) : Mushroom(gridX, gridY, 16, 13, 0, 0, 1, 1, EnemyType_BigMushroomCeiling)
{
    // Empty
}

void BigMushroomCeiling::handleAlive(float deltaTime)
{
    Mushroom::handleAlive(deltaTime);
    
    m_fStateTime += deltaTime;
}

bool BigMushroomCeiling::isJonBlockedAbove(Jon& jon, float deltaTime)
{
    float entityVelocityY = jon.getVelocity().getY();
    
    if (entityVelocityY > 0 && OverlapTester::doNGRectsOverlap(jon.getMainBounds(), getMainBounds()))
    {
        jon.getPosition().sub(0, jon.getVelocity().getY() * deltaTime);
        jon.updateBounds();
        
        jon.triggerBounceDownardsOffEnemy(-18);
        
        m_fStateTime = 0;
        
        m_isBeingBouncedOn = true;
        
        NG_AUDIO_ENGINE->playSound(SOUND_ID_MUSHROOM_BOUNCE);
        
        return true;
    }
    
    return false;
}

MovingSnakeGrunt::MovingSnakeGrunt(int gridX, int gridY, float acceleration, float topSpeed, bool isAbleToJump, EnemyType type, float red, float green, float blue) : Enemy(gridX, gridY, 16, 8, 0.1f, 0, 0.8f, 1, type, EnemySpiritType_Snake, SOUND_ID_SNAKE_DEATH), m_fAcceleration(-1 * acceleration), m_fTopSpeed(-1 * topSpeed), m_isAbleToJump(isAbleToJump), m_isPausing(false), m_isPreparingToJump(false), m_isLanding(false), m_isGrounded(false), m_isOnScreen(false)
{
    m_color.red = red;
    m_color.green = green;
    m_color.blue = blue;
}

void MovingSnakeGrunt::updateBounds()
{
    Enemy::updateBounds();
    
    NGRect& camBounds = *m_game->getCameraBounds();
    
    if (camBounds.getWidth() > CAM_WIDTH)
    {
        return;
    }
    
    if (!m_isOnScreen)
    {
        if (OverlapTester::doNGRectsOverlap(camBounds, getMainBounds()))
        {
            m_isOnScreen = true;
            
            m_acceleration.set(m_fAcceleration, 0);
        }
    }
}

bool MovingSnakeGrunt::isPreparingToJump()
{
    return m_isPreparingToJump;
}

bool MovingSnakeGrunt::isLanding()
{
    return m_isLanding;
}

bool MovingSnakeGrunt::isPausing()
{
    return m_isPausing;
}

void MovingSnakeGrunt::handleAlive(float deltaTime)
{
    PhysicalEntity::update(deltaTime);
    
    if (!m_isOnScreen)
    {
        return;
    }
    
    bool wasGrounded = m_isGrounded;
    
    if ((m_isGrounded = m_game->isEntityGrounded(this, deltaTime)))
    {
		m_acceleration.set(m_fAcceleration, 0);
		m_velocity.setY(0);

        if (!wasGrounded)
        {
            m_isLanding = true;
            m_fStateTime = 0;
        }

		if (EntityUtils::isBlockedOnLeft(this, m_game->getForegroundObjects(), deltaTime)
			|| EntityUtils::isBlockedOnLeft(this, m_game->getGrounds(), deltaTime))
		{
			m_velocity.setX(0);
		}
        
        if (m_isLanding)
        {
            if (m_fStateTime > 0.40f)
            {
                m_fStateTime = 0;
                m_isLanding = false;
            }
        }
        else if (m_isPausing)
        {
            if (m_fStateTime > 0.5f)
            {
                m_fStateTime = 0;
                m_isPausing = false;
            }
        }
        else if (m_isPreparingToJump)
        {
            if (m_fStateTime > 0.30f)
            {
                m_velocity.sub(2, 0);
				m_velocity.setY(12);
                m_acceleration.setY(GAME_GRAVITY);
                
                m_fStateTime = 0;
                m_isPreparingToJump = false;
            }
        }
        else
        {
			if (m_velocity.getX() < m_fTopSpeed)
            {
                m_velocity.setX(m_fTopSpeed);
            }
            
            if (m_isAbleToJump)
            {
				Jon& jon = m_game->getJon();
				if (jon.getMainBounds().getTop() > getMainBounds().getBottom()
					&& jon.getMainBounds().getBottom() < (getMainBounds().getTop() + 8)
					&& jon.getMainBounds().getRight() > getMainBounds().getLeft() - 8
					&& jon.getMainBounds().getRight() < getMainBounds().getLeft())
				{
					m_fStateTime = 0;
					m_isPreparingToJump = true;

					NG_AUDIO_ENGINE->playSound(SOUND_ID_SNAKE_JUMP);
				}
            }
            else
            {
                if (m_fStateTime > 0.6f)
                {
                    m_fStateTime = 0;
                    m_isPausing = true;
                    m_velocity.setX(0);
                }
            }
        }
    }
    else
    {
        m_acceleration.setY(GAME_GRAVITY);
        
        if (m_velocity.getX() < (m_fTopSpeed - 2))
        {
            m_velocity.setX(m_fTopSpeed - 2);
        }
    }

	handleJon();
}

RTTI_IMPL(Enemy, GridLockedPhysicalEntity);
RTTI_IMPL(Mushroom, Enemy);
RTTI_IMPL(MushroomGround, Mushroom);
RTTI_IMPL(MushroomCeiling, Mushroom);
RTTI_IMPL(SnakeGrunt, Enemy);
RTTI_IMPL(Sparrow, Enemy);
RTTI_IMPL(Toad, Enemy);
RTTI_IMPL(Fox, Enemy);
RTTI_IMPL(BigMushroomGround, Mushroom);
RTTI_IMPL(BigMushroomCeiling, Mushroom);
RTTI_IMPL(MovingSnakeGrunt, Enemy);
