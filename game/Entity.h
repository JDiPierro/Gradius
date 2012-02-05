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
		ENTITY_TYPE_NONE = 0,
		ENTITY_TYPE_GENERIC,
		ENTITY_TYPE_PLAYER
	};

	enum
	{
		ENTITY_FLAG_NONE 	= 0,

		ENTITY_FLAG_GHOST	= 0x00000001,
		ENTITY_FLAG_MAPONLY	= 0x00000002
	};

public:
	static std::vector<Entity*> EntityList;

protected:
	Animation Anim_Control;
	SDL_Surface* Surf_Entity;

public:
	float X;
	float Y;

	int Width;
	int Height;

	bool MoveLeft;
	bool MoveRight;
	bool MoveUp;
	bool MoveDown;
	
	bool Firing;

public:
	int Type;

	bool Dead;
	int Flags;

protected:
	float SpeedX;
	float SpeedY;
	float AccelX;
	float AccelY;

public:
	float MaxSpeedX;
	float MaxSpeedY;

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

	virtual void OnLoop();

	virtual void OnRender(SDL_Surface* Surf_Display);

	virtual void OnCleanup();

	virtual void OnAnimate();

	virtual bool OnCollision(Entity* Entity);

public:
	void OnMove(float MoveX, float MoveY);

	void StopMove();
	
public:
	void OnFire();

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
