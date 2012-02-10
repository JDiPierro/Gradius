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
    MoveDown = true;
    
    Type = ENTITY_TYPE_GENERIC;
    Entity::EntityList.push_back(this);
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
    
    //0,0 is at the top left corner of the screen so if you add to Y you're going down.
    //Therefore my first test is if you're less than 25 DOWN, so you're in the top 24 pixels,
    //change direction and go down.
    if(Y < 25)
    {
	MoveUp = false;
	MoveDown = true;
	std::cout << "Going down!" << std::endl;
    }
    //If you're more than 25 pixels from the bottom, change direction and go up...
    else if(Y > Settings::SettingsControl.GetWinHeight() - 50)
    {
	MoveDown = false;
	MoveUp = true;
	std::cout << "Going Up!" << std::endl;
    }
    
    Entity::OnLoop();
}
