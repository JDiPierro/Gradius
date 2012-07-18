#ifndef _BULLET_H_
#define _BULLET_H_

#include "Entity.h"

class Bullet : public Entity{    
    
public:
    Entity* parent;

public:
    Bullet();
    
public:
    bool OnLoad(Entity* parent, int Width, int Height, int MaxFrames,int X, int Y);
    
    void OnLoop();
    
    void OnRender(SDL_Surface* Surf_Display);
    
    void OnCleanup();
    
    void OnDeath();
    
    bool OnCollision(Entity* Entity);
    
private:
    bool PosValidEntity(Entity* Entity, int NewX, int NewY);
    
};

#endif