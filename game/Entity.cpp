#include "Entity.h"
#include <iostream>
#include "../app/App.h"


std::vector<Entity*> Entity::EntityList;

Entity::Entity()
{
	Surf_Entity = NULL;

	X = 0;
	Y = 0;

	Width = 0;
	Height = 0;

	MoveLeft 	= false;
	MoveRight	= false;
	MoveUp		= false;
	MoveDown	= false;
	
	Firing		= false;
	numBullets	= 0;
	lastFireTime	= 0;

	Type = ENTITY_TYPE_GENERIC;

	Dead = false;

	Flags = ENTITY_FLAG_NONE;

	SpeedHack = 1;
	Speed = 1;
	SpeedX = 0;
	SpeedY = 0;

	CurrFrameCol = 0;
	CurrFrameRow = 0;

	Col_X = 0;
	Col_Y = 0;

	Col_Width = 0;
	Col_Height = 0;
}

Entity::~Entity()
{
	//
}

bool Entity::OnLoad(char* File, int Width, int Height, int MaxFrames)
{
	if((Surf_Entity = Surface::OnLoad(File)) == NULL)
	{
		std::cout << "Entity Surface Failure" << std::endl;
		return false;
	}

	//Surface::Transparent(Surf_Entity, 255, 0, 255);

	this->Width = Width;
	this->Height = Height;

	Anim_Control.MaxFrames = MaxFrames;

	return true;
}

bool Entity::OnLoad(SDL_Surface* Surface, int Width, int Height, int MaxFrames)
{
	Surf_Entity = Surface;
	//Surface::Transparent(Surf_Entity, 255, 0, 255);

	this->Width = Width;
	this->Height = Height;

	Anim_Control.MaxFrames = MaxFrames;

	return true;
}

void Entity::OnLoop()
{
	//We're not moving so make sure to stop.
	if(MoveLeft == false && MoveRight == false && MoveUp == false && MoveDown == false)
	{
		StopMove();
	}

	//Speed control.
	//TODO: Implement variables for speed upgrades.
	if(MoveLeft)
		SpeedX = -Speed*SpeedHack;
	else if(MoveRight)
		SpeedX =  Speed*SpeedHack;
	if(MoveUp)
		SpeedY = -Speed*SpeedHack;
	else if(MoveDown)
		SpeedY =  Speed*SpeedHack;
	if(Firing)
	    OnFire();
	

	SpeedX *= FPS::FPSControl.GetSpeedFactor();
	SpeedY *= FPS::FPSControl.GetSpeedFactor();

	OnAnimate();
	OnMove(SpeedX, SpeedY);
}

void Entity::OnRender(SDL_Surface* Surf_Display)
{
	if(Surf_Entity == NULL || Surf_Display == NULL)
	{
		std::cout << "Entity Render Error" << std::endl;
		return;
	}
	Surface::OnDraw(Surf_Display,Surf_Entity,X,Y,0,Anim_Control.GetCurrentFrame() * Height,Width,Height);
}

void Entity::OnDeath()
{
    OnCleanup();
}


void Entity::OnCleanup()
{
	if(Surf_Entity)
		SDL_FreeSurface(Surf_Entity);

	Surf_Entity = NULL;
}

void Entity::OnAnimate()
{
	//If different left/right anims change the CurrFrameCol here.
	Anim_Control.OnAnimate();
}

bool Entity::OnCollision(Entity* Entity)
{
    
}

void Entity::OnMove(float MoveX, float MoveY)
{
	if(MoveX == 0 && MoveY == 0)
		return;

	MoveX *= FPS::FPSControl.GetSpeedFactor();
	MoveY *= FPS::FPSControl.GetSpeedFactor();

	if(Flags & ENTITY_FLAG_GHOST)
	{
		PosValid((int)(X + MoveX), (int)(Y + MoveY));
		
		X += MoveX;
		Y += MoveY;
	}
	else
	{
		if(PosValid((int)(X + MoveX), (int)(Y)))
			X += MoveX;
		else
			SpeedX = 0;
		if(PosValid((int)(X), (int)(Y + MoveY)))
			Y += MoveY;
		else
			SpeedY = 0;
	}
}

void Entity::StopMove()
{
	SpeedX = 0;
	SpeedY = 0;
}

void Entity::OnFire()
{
    if(lastFireTime + 300 < SDL_GetTicks())
    {
	lastFireTime = SDL_GetTicks();
	Entity* bullet = new Entity();
	bullet->OnLoad("./gfx/playerBullet.png",4,4,0) == false;
	bullet->Type = ENTITY_TYPE_BULLET;
	bullet->X = this->X + this->Width + 1;
	bullet->Y = this->Y + 12;
	
	bullet->MoveRight = true;
    }
}

bool Entity::Collides(int oX, int oY, int oW, int oH)
{
    int left1, left2;
    int right1, right2;
    int top1, top2;
    int bottom1, bottom2;

    int tX = (int)X + Col_X;
    int tY = (int)Y + Col_Y;

    left1 = tX;
    left2 = oX;

    right1 = left1 + Width -1 - Col_Width;
    right2 = oX + oW -1;

    top1 = tY;
    top2 = oY;

    bottom1 = top1 + Height - 1 - Col_Height;
    bottom2 = oY + oH -1;

    if (bottom1 < top2) return false;
    if (top1 > bottom2) return false;

    if (right1 < left2) return false;
    if (left1 > right2) return false;

    return true;
}

bool Entity::PosValid(int NewX, int NewY)
{
	bool Return = true;

	int StartX = (NewX + Col_X) / Settings::SettingsControl.GetTileSize();
	int StartY = (NewY + Col_Y) / Settings::SettingsControl.GetTileSize();

	int EndX = ((NewX + Col_X) + Width - Col_Width - 1) / Settings::SettingsControl.GetTileSize();
	int EndY = ((NewY + Col_Y) + Height - Col_Height - 1) / Settings::SettingsControl.GetTileSize();

	for(int iY = StartY; iY <= EndY; iY++)
	{
		for(int iX = StartX; iX <= EndX; iX++)
		{
			/*
			 * TODO:Implement Tile Checking
			 */
			/*Tile* Tile = Area::AreaControl.GetTile(iX * Settings::SettingsControl.GetTileSize(), iY * Settings::SettingsControl.GetTileSize());

			if(PosValidTile(Tile) == false)
			{
				Return = false;
			}*/
		}
	}

	if( Flags & ENTITY_FLAG_MAPONLY)
	{
		//
	}
	else
	{
		for(int i = 0; i < EntityList.size(); i++)
		{
			if(PosValidEntity(EntityList[i],NewX, NewY) == false)
			{
				Return = false;
			}
		}
	}
	
	//TODO: Use the camera to determine this.
	if(NewX < 0 || NewY < 0 ||
	   NewX > Settings::SettingsControl.GetWinWidth() - Width ||
	   NewY > Settings::SettingsControl.GetWinHeight() - Height)
	{
	    if(Type == ENTITY_TYPE_BULLET)
	    {
		Dead = true;
	    }
	    Return = false;
	}

	return Return;
}

bool Entity::PosValidTile(Tile* Tile)
{
	if(Tile == NULL)
		return true;

	if(Tile->TypeID == Tile::TILE_TYPE_BLOCK)
		return false;

	return true;
}

bool Entity::PosValidEntity(Entity* Entity, int NewX, int NewY)
{
	if(this != Entity &&
		Entity != NULL &&
		Entity->Dead == false &&
	       (Entity->Flags ^ ENTITY_FLAG_MAPONLY) &&
		Entity->Collides(NewX + Col_X,NewY + Col_Y, Width - Col_Width - 1, Height - Col_Height - 1) == true)
	{
		EntityCol EntityCol;


		EntityCol.EntityA = this;
		EntityCol.EntityB = Entity;


		EntityCol::EntityColList.push_back(EntityCol);

		return false;
	}

	return true;
}

