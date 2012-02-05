#include "Player.h"
#include <iostream>
#include "Bullet.h"

Player::Player()
{
    powerUps = 0;
}

bool Player::OnLoad(char* File, int Width, int Height, int MaxFrames)
{
    if(Entity::OnLoad(File, Width, Height, MaxFrames) == false)
    {
	std::cout << "Player 1 Entity Load Failed" << std::endl;
	return false;
    }
    
    Speed = 25;
    Type = ENTITY_TYPE_PLAYER;
    return true;
}

void Player::OnFire()
{
    if(lastFireTime + 150 < SDL_GetTicks())
    {
	if(numBullets < 2)
	{
	    if(numBullets < 0)
	    {
		std::cout << "NumBullets less than 0" << std::endl;
	    }
	    lastFireTime = SDL_GetTicks();
	    Bullet* bullet = new Bullet();
	    bullet->OnLoad(this,4,4,0,X + Width + 1,Y + 12) == false;
	}
    }
}

void Player::OnLoop()
{
    Entity::OnLoop();
}

void Player::OnRender(SDL_Surface* Surf_Display)
{
    Entity::OnRender(Surf_Display);
}

void Player::OnCleanup()
{
    Entity::OnCleanup();
}

void Player::OnAnimate()
{
    Entity::OnAnimate();
}

bool Player::OnCollision(Entity* Entity)
{
    return true;
}
