#ifndef _ENTITY_H_
	#define _ENTITY_H_

#include <vector>

#include "../app/Animation.h"
#include "../world/Camera.h"
#include "../app/FPS.h"
#include "../app/Surface.h"
#include "../world/Tile.h"

class Entity
{
public:
	enum
	{
		ENTITY_TYPE_NONE = 0, //Should never be used. If an entity has this type something is very wrong.
		ENTITY_TYPE_GENERIC,
		ENTITY_TYPE_PLAYER,
		ENTITY_TYPE_BULLET,
		ENTITY_TYPE_POWERUP
	};

	enum
	{
		ENTITY_FLAG_NONE 	= 0,

		ENTITY_FLAG_GHOST	= 0x01,
		ENTITY_FLAG_MAPONLY	= 0x02,
					//0x04
					//0x08
					//0x10 =16
					//0x20 =32
					//0x40 =64
	};

public:
	static std::vector<Entity*> EntityList;

protected:
	Animation Anim_Control;
	SDL_Surface* Surf_Entity;

protected:
	float X;
	float Y;

	int Width;
	int Height;

public:
	bool MoveLeft;
	bool MoveRight;
	bool MoveUp;
	bool MoveDown;
	
public:
	bool Firing;
	int numBullets;
protected:
	Uint32 lastFireTime;

public:
	int Type;

	bool Dead;
	int Flags;

protected:
	float SpeedX;
	float SpeedY;
	float Speed;
public:
	int SpeedHack;

protected:
	int CurrFrameCol;
	int CurrFrameRow;

protected:
	int Col_X;
	int Col_Y;
	int Col_Width;
	int Col_Height;

public:
	Entity();
	virtual ~Entity();

public:
	virtual bool OnLoad(char* File, int Width, int Height, int MaxFrames);
	virtual bool OnLoad(SDL_Surface* Surface, int Width, int Height, int MaxFrames);

	virtual void OnLoop();

	virtual void OnRender(SDL_Surface* Surf_Display);

	virtual void OnCleanup();

	virtual void OnAnimate();

	virtual bool OnCollision(Entity* Entity);
	
	virtual void GetPowerup();

	virtual void OnDeath();

public:
	void OnMove(float MoveX, float MoveY);

	void StopMove();
	
public:
	virtual void OnFire();

public:
	bool Collides(int oX, int oY, int oW, int oH);

private:
	bool PosValid(int NewX, int NewY);

	bool PosValidTile(Tile* Tile);

	bool PosValidEntity(Entity* Entity, int NewX, int NewY);
};

class EntityCol
{
public:
	static std::vector<EntityCol> EntityColList;

public:
	Entity* EntityA;
	Entity* EntityB;

public:
	EntityCol();
};
#endif
