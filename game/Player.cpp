#include "Player.h"
#include <iostream>

Player::Player()
{
    //
}

bool Player::OnLoad(char* File, int Width, int Height, int MaxFrames)
{
    if(Entity::OnLoad(File, Width, Height, MaxFrames) == false)
    {
	std::cout << "Player 1 Entity Load Failed" << std::endl;
	return false;
    }
    return true;
}

void Player::OnFire()
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
	
	Entity::EntityList.push_back(bullet);
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
