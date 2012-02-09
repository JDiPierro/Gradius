#ifndef _ENEMY_H_
    #define _ENEMY_H_
#include "Entity.h"

/*
 * ENEMY CLASS:
 * This is the base class for enemies that should define basic movement direction
 * and firing direction. Ground enemies and Air enemies will be derived from this.
 * 
 * Each enemy type will have it's own class. This will allow each enemy to have their own
 * AI. All will be derived from this.
 * 
 * BOSSES:
 * I'm not yet sure if Bosses will be an extension of this or will have their
 * own class.
 */

class Enemy : public Entity
{
public:
    Enemy();
    
public:
    bool OnLoad(char* File, int Width, int Height, int MaxFrames);
    
    void OnLoop();
    
    void OnAnimate();
    
    void OnRender(SDL_Surface* Surf_Display);
    
    void OnFire();
    
    void OnDeath();
	bool isDead();
    
    void OnCleanup();
    
    bool OnCollision(Entity* Entity);
    
    void ForcePos(int fX, int fY);
    void ForcePos(int fY, char dim);
    
};

#endif