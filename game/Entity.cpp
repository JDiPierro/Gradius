#include "Entity.h"


std::vector<Entity*> Entity::EntityList;

std::vector<EntityCol> EntityCol::EntityColList;

EntityCol::EntityCol()
{
	EntityA = NULL;
	EntityB = NULL;
}

Entity::Entity()
{
	Surf_Entity = NULL;

	X = 0;
	Y = 0;

	Width = 0;
	Height = 0;

	MoveLeft 	= false;
	MoveRight	= false;
	MoveUp	= false;
	MoveDown	= false;

	Type = ENTITY_TYPE_GENERIC;

	Dead = false;

	Flags = ENTITY_FLAG_NONE;

	SpeedX = 0;
	SpeedY = 0;

	AccelX = 0;
	AccelY = 0;

	MaxSpeedX = 0;
	MaxSpeedY = 0;

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
		return false;
	}

	Surface::Transparent(Surf_Entity, 255, 0, 255);

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
		AccelX = -0.5;
	else if(MoveRight)
		AccelX = 0.5;
	if(MoveUp)
		AccelY = -0.5;
	else if(MoveDown)
		AccelY = 0.5;

	SpeedX += AccelX * FPS::FPSControl.GetSpeedFactor();
	SpeedY += AccelY * FPS::FPSControl.GetSpeedFactor();

	//This next block will be deleted soon:
	//TODO: Implement standard speed w/ upgrades
	if(SpeedX > MaxSpeedX)  SpeedX =  MaxSpeedX;
	if(SpeedX < -MaxSpeedX) SpeedX = -MaxSpeedX;
	if(SpeedY > MaxSpeedY)  SpeedY =  MaxSpeedY;
	if(SpeedY < -MaxSpeedY) SpeedY = -MaxSpeedY;

	OnAnimate();
	OnMove(SpeedX, SpeedY);
}

void Entity::OnRender(SDL_Surface* Surf_Display)
{
	if(Surf_Entity == NULL || Surf_Display == NULL)
	{
		return;
	}

	Surface::OnDraw(	Surf_Display,					//Surface to Draw to
					Surf_Entity,					//Surface to Draw
					X - Camera::CameraControl.GetX(),	//X to draw at
					Y - Camera::CameraControl.GetY(),	//Y to draw at
					CurrFrameCol * Width,			//Width of Sprite crop
					(CurrFrameRow + Anim_Control.GetCurrentFrame()) * Height,	//Height of sprite crop
					Width,						//Width of Sprite
					Height);						//Height of Sprite
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

void Entity::OnCollision(Entity* Entity)
{
	//
}

void Entity::OnMove(float MoveX, float MoveY)
{
	if(MoveX == 0 && MoveY == 0)
		return;

	double NewX = 0;
	double NewY = 0;

	MoveX *= FPS::FPSControl.GetSpeedFactor();
	MoveY *= FPS::FPSControl.GetSpeedFactor();

	if(MoveX != 0)
	{
		if(MoveX >= 0)
			NewX =  FPS::FPSControl.GetSpeedFactor();
		else
			NewX = -FPS::FPSControl.GetSpeedFactor();
	}
	if(MoveY != 0)
	{
		if(MoveY >= 0)
			NewY = FPS::FPSControl.GetSpeedFactor();
		else
			NewY = -FPS::FPSControl.GetSpeedFactor();
	}
	while(true)
	{
		if(Flags & ENTITY_FLAG_GHOST)
		{
			PosValid((int)(X + NewX), (int)(Y + NewY));

			X += NewX;
			Y += NewY;
		}
		else
		{
			if(PosValid((int)(X + NewX), (int)(Y + NewY)))
				X += NewX;
			else
				SpeedX = 0;
			if(PosValid((int)(X), (int)(Y + NewY)))
				Y += NewY;
			else
				SpeedY = 0;
		}

		MoveX += -NewX;
		MoveY += -NewY;

		if(NewX > 0 && MoveX <= 0)
			NewX = 0;
		if(NewX < 0 && MoveX >= 0)
			NewX = 0;

		if(NewY > 0 && MoveY <= 0)
			NewY = 0;
		if(NewY < 0 && MoveY >= 0)
			NewY = 0;

		if(MoveX == 0)
			NewX = 0;
		if(MoveY == 0)
			NewY = 0;

		if(MoveX == 0 && MoveY 	== 0) 	break;
		if(NewX  == 0 && NewY 	== 0) 	break;
	}
}

void Entity::StopMove()
{
	if(SpeedX > 0)
		AccelX = -1;

	if(SpeedX < 0)
		AccelX = 1;

	if(SpeedX < 2.0f && SpeedX > -2.0f)
	{
		AccelX = 0;
		SpeedX = 0;
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
	left2 = tY;

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
