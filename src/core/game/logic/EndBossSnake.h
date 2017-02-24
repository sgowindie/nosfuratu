//
//  EndBossSnake.h
//  nosfuratu
//
//  Created by Stephen Gowen on 9/24/16.
//  Copyright (c) 2016 Noctis Games. All rights reserved.
//

#ifndef __nosfuratu__EndBossSnake__
#define __nosfuratu__EndBossSnake__

#include "GridLockedPhysicalEntity.h"

#include "GameConstants.h"
#include "Color.h"
#include "RTTI.h"

#include <memory>
#include <vector>

class Game;
class EndBossSnake;

class SnakeSpirit : public PhysicalEntity
{
    RTTI_DECL;
    
public:
    SnakeSpirit(float x, float y, EndBossSnake* endBossSnake) : PhysicalEntity(x, y, 51.25f * GRID_CELL_SIZE, 22.5f * GRID_CELL_SIZE), m_endBossSnake(endBossSnake), m_color(1, 1, 1, 1), m_isShowing(false)
    {
        // Empty
    }
    
    virtual void update(float deltaTime);
    
    void onDeath();
    
    EndBossSnake& getEndBossSnake() { return *m_endBossSnake; }
    
    Color& getColor() { return m_color; }
    
private:
    EndBossSnake* m_endBossSnake;
    Color m_color;
    bool m_isShowing;
};

class SnakeHeadImpact : public PhysicalEntity
{
    RTTI_DECL;
    
public:
	SnakeHeadImpact(float x, float y, EndBossSnake* endBossSnake) : PhysicalEntity(x, y, 32 * GRID_CELL_SIZE, 32 * GRID_CELL_SIZE), m_endBossSnake(endBossSnake), m_color(1, 1, 1, 1), m_isShowing(false)
	{
		// Empty
	}

	virtual void update(float deltaTime);

	void onDamageTaken();

	EndBossSnake& getEndBossSnake() { return *m_endBossSnake; }

	Color& getColor() { return m_color; }

private:
	EndBossSnake* m_endBossSnake;
	Color m_color;
	bool m_isShowing;
};

class SnakeSkin : public PhysicalEntity
{
    RTTI_DECL;
    
public:
    SnakeSkin(float x, float y, float width, float height, EndBossSnake* endBossSnake) : PhysicalEntity(x, y, width, height), m_endBossSnake(endBossSnake), m_color(1, 1, 1, 1), m_isShowing(false)
    {
        // Empty
    }
    
    virtual void update(float deltaTime);
    
    void onDamageTaken();
    
    EndBossSnake& getEndBossSnake() { return *m_endBossSnake; }
    
    Color& getColor() { return m_color; }
    
private:
    EndBossSnake* m_endBossSnake;
    Color m_color;
    bool m_isShowing;
};

class SnakeEye : public PhysicalEntity
{
    RTTI_DECL;
    
public:
    SnakeEye(float x, float y, EndBossSnake* endBossSnake) : PhysicalEntity(x, y, 1.037109375f, 1.037109375f), m_endBossSnake(endBossSnake), m_isWakingUp(false), m_isShowing(true)
    {
        // Empty
    }
    
    virtual void update(float deltaTime);
    
    void onAwaken();
    
    EndBossSnake& getEndBossSnake() { return *m_endBossSnake; }
    
private:
    EndBossSnake* m_endBossSnake;
    bool m_isWakingUp;
    bool m_isShowing;
};

class SnakeTonque : public PhysicalEntity
{
    RTTI_DECL;
    
public:
    SnakeTonque(float x, float y, EndBossSnake* endBossSnake) : PhysicalEntity(x, y, 4.869140625f, 0.685546875f), m_endBossSnake(endBossSnake), m_isMouthOpen(false)
    {
        // Empty
    }
    
	virtual void update(float deltaTime);
    
    void onMouthOpen();
    
    void onMouthClose() { m_isMouthOpen = false; }
    
    EndBossSnake& getEndBossSnake() { return *m_endBossSnake; }
    
    bool isMouthOpen() { return m_isMouthOpen; }
    
private:
    EndBossSnake* m_endBossSnake;
    bool m_isMouthOpen;
};

class SnakeBody : public PhysicalEntity
{
    RTTI_DECL;
    
public:
    SnakeBody(float x, float y, float height, EndBossSnake* endBossSnake) : PhysicalEntity(x, y, 30.65625f, height), m_endBossSnake(endBossSnake), m_color(1, 1, 1, 1), m_isDead(false)
    {
		update(0);
    }
    
    virtual void update(float deltaTime);
    
    virtual void updateBounds()
    {
        getMainBounds().setWidth(getWidth());
        getMainBounds().setHeight(getHeight());
        
        PhysicalEntity::updateBounds();
        
        getMainBounds().getLowerLeft().add(getWidth() * 0.15f, getHeight() * 0.0f);
        getMainBounds().setWidth(getWidth() * 0.70f);
        getMainBounds().setHeight(getHeight() * 0.50f);
    }

	void onDeath();
    
    EndBossSnake& getEndBossSnake() { return *m_endBossSnake; }
    
    Color& getColor() { return m_color; }
    
private:
    EndBossSnake* m_endBossSnake;
    Color m_color;
	bool m_isDead;
};

typedef enum
{
    EndBossSnakeState_Sleeping,
    EndBossSnakeState_Awakening,
    EndBossSnakeState_OpeningMouthLeft,
	EndBossSnakeState_OpenMouthLeft,
    EndBossSnakeState_ChargingLeft,
	EndBossSnakeState_Waiting,
    EndBossSnakeState_Pursuing,
    EndBossSnakeState_Damaged,
    EndBossSnakeState_OpeningMouthRight,
	EndBossSnakeState_OpenMouthRight,
    EndBossSnakeState_ChargingRight,
    EndBossSnakeState_Dying,
	EndBossSnakeState_DeadSpiritReleasing,
    EndBossSnakeState_Dead
} EndBossSnakeState;

class EndBossSnake : public GridLockedPhysicalEntity
{
    RTTI_DECL;
    
public:
    static EndBossSnake* create(int gridX, int gridY, int type)
    {
        return new EndBossSnake(gridX, gridY);
    }
    
    EndBossSnake(int gridX, int gridY);
    
    virtual void update(float deltaTime);
    
	void begin();

	void awaken();

	void beginPursuit();

    void triggerHit();

	void checkPointKill();
    
    virtual bool isEntityLanding(PhysicalEntity* entity, float deltaTime);
    
    virtual int getEntityLandingPriority() { return 0; }
    
    Game* getGame() { return m_game; }
    void setGame(Game* game) { m_game = game; }
    
    std::vector<EndBossSnake *>& getAfterImages() { return m_afterImages; }
    SnakeSkin& getSnakeSkin() { return *m_snakeSkin; }
    SnakeEye& getSnakeEye() { return *m_snakeEye; }
    SnakeTonque& getSnakeTonque() { return *m_snakeTonque; }
    SnakeBody& getSnakeBody() { return *m_snakeBody; }
	SnakeHeadImpact& getSnakeHeadImpact() { return *m_snakeHeadImpact; }
    SnakeSpirit& getSnakeSpirit() { return *m_snakeSpirit; }
    
    EndBossSnakeState getState() { return m_state; }
    
    Color getColor() { return m_color; }
    
    int getDamage() { return m_iDamage; }
    
    int getType() { return m_type; }
    
private:
    std::vector<EndBossSnake *> m_afterImages;
    std::unique_ptr<SnakeSkin> m_snakeSkin;
    std::unique_ptr<SnakeEye> m_snakeEye;
    std::unique_ptr<SnakeTonque> m_snakeTonque;
    std::unique_ptr<SnakeBody> m_snakeBody;
	std::unique_ptr<SnakeHeadImpact> m_snakeHeadImpact;
    std::unique_ptr<SnakeSpirit> m_snakeSpirit;
    Game* m_game;
    EndBossSnakeState m_state;
    Color m_color;
    float m_fTimeSinceLastVelocityCheck;
    int m_iDamage;
    int m_type;
    bool m_hasPlayedChargeSound;
    
    void setState(EndBossSnakeState state);
};

#endif /* defined(__nosfuratu__EndBossSnake__) */