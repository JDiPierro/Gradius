#include "Bullet.h"
#include <iostream>

Bullet::Bullet()
{
    //
}

bool Bullet::OnLoad(Entity* inParent, int Width, int Height, int MaxFrames, int X, int Y)
{
    parent = inParent;
    if(parent->Type == ENTITY_TYPE_NONE || parent->Type == ENTITY_TYPE_BULLET)
	return false;
    else if(parent->Type == ENTITY_TYPE_PLAYER)
    {
	parent->numBullets++;
	if(Entity::OnLoad("./gfx/playerBullet.png", Width, Height, MaxFrames) == false)
	{
	    std::cout << "Bullet Load Failed" << std::endl;
	    return false;
	}
	MoveRight = true;
    }
    else if(parent->Type == ENTITY_TYPE_GENERIC) //TODO: Change GENERIC to ENEMY.
    {
	if(Entity::OnLoad("./gfx/enemyBullet.png", Width, Height, MaxFrames) == false)
	{
	    std::cout << "Bullet Load Failed" << std::endl;
	    return false;
	}
	MoveLeft = true;
    }
    
    Type = ENTITY_TYPE_BULLET;
    
    this->X = X;
    this->Y = Y;
    
    Speed = 35;
    
    Entity::EntityList.push_back(this);
    
    return true;
}

void Bullet::OnLoop()
{
    Entity::OnLoop();
}

void Bullet::OnRender(SDL_Surface* Surf_Display)
{
    Entity::OnRender(Surf_Display);
}

void Bullet::OnDeath()
{
    parent->numBullets--;
    Entity::OnCleanup();
}

void Bullet::OnCleanup()
{
    Entity::OnCleanup();
}

bool Bullet::OnCollision(Entity* Entity)
{    
    if(Entity == parent) 
	return false;
    Dead = true;    
    return true;
}
