#ifndef _POWERUP_H_
#define _POWERUP_H_

#include "Entity.h"
#include "Player.h"

class Powerup : public Entity
{
public:
    Powerup(int X, int Y);
    
public:
    bool OnLoad(int X, int Y);
    
    void OnRender(SDL_Surface* Surf_Display);
    
    bool OnCollision(Entity* Entity);
    bool OnCollision(Player* Player);
    
};

#endif