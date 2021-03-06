#include "Powerup.h"
#include <iostream>

Powerup::Powerup(int X, int Y)
{
    OnLoad(X,Y);
}

bool Powerup::OnLoad(int X, int Y)
{
    if(Entity::OnLoad("./gfx/PowerUp.png", 13, 13, 0) == false)
    {
	std::cout << "Powerup Entity Load Failed" << std::endl;
	return false;
    }

    Type = ENTITY_TYPE_POWERUP;
    
    this->X = X;
    this->Y = Y;
    
    Width = 13;
    Height = 13;

    Entity::EntityList.push_back(this);
    
    return true;
}

bool Powerup::OnCollision(Entity* Entity)
{
    if(Entity->Type == ENTITY_TYPE_PLAYER)
    {
	Entity->GetPowerup();
	Dead = true;
	Entity::OnCleanup();
    }
    return true;
}

void Powerup::OnRender(SDL_Surface* Surf_Display)
{
    Entity::OnRender(Surf_Display);
}
