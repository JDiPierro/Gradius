#include "Enemy.h"
#include <iostream>
#include "../settings/Settings.h"

Enemy::Enemy()
{
    
}

bool Enemy::OnLoad(char* File, int Width, int Height, int MaxFrames)
{
    if(Entity::OnLoad(File, Width, Height, MaxFrames) == false)
    {
	std::cout << "Player 1 Entity Load Failed" << std::endl;
	return false;
    }
    Entity::EntityList.push_back(this);
    
    Type = ENTITY_TYPE_GENERIC;
    return true;
}

void Enemy::ForcePos(int fX, int fY)
{
    Entity::ForcePos(fX, fY);
}

void Enemy::ForcePos(int fY, char dim)
{
    Entity::ForcePos(fY, dim);
}


void Enemy::OnRender(SDL_Surface* Surf_Display)
{
    Entity::OnRender(Surf_Display);
}

void Enemy::OnCleanup()
{
    Entity::OnCleanup();
}

void Enemy::OnAnimate()
{
    Anim_Control.OnAnimate();
}

bool Enemy::OnCollision(Entity* Entity)
{
    return Entity::OnCollision(Entity);
}

void Enemy::OnDeath()
{
    Entity::OnDeath();
}

bool Enemy::isDead()
{
    return Dead;
}

void Enemy::OnFire()
{
    Entity::OnFire();
}

void Enemy::OnLoop()
{
    //Basic move up and down the screen.
    if(X < 10)
    {
	MoveUp = false;
	MoveDown = true;
    }
    else if(X > Settings::SettingsControl.GetMapHeight() - 10);
    {
	MoveDown = false;
	MoveUp = true;
    }
}
