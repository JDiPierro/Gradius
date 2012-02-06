#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "Entity.h"

class Player : public Entity
{
public:
    int powerUps;
public:
    Player();
    
public:
    bool OnLoad(char* File, int Width, int Height, int MaxFrames);
    void OnLoop();
    void OnRender(SDL_Surface* Surf_Display);
    void OnCleanup();
    void OnAnimate();
    void OnFire();
    bool OnCollision(Entity* Entity);
    void GetPowerup();
};

#endif // PLAYER_H
