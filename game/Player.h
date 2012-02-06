#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "Entity.h"

class Player : public Entity
{
private:
enum
{
    PUP_NONE = 0,
    PUP_SPEED,
    PUP_MISSILES,
    PUP_GUNUP,
    PUP_LASERS,
    PUP_OPTION,
    PUP_SHIELD,
    PUP_SPECIAL
};
    
enum
{
	POWERUP_FLAG_NONE 	= 0,

	POWERUP_FLAG_MISSILES	= 0x00000001,
	POWERUP_FLAG_GUNUP	= 0x00000002,
	POWERUP_FLAG_LASERS	= 0x00000004,
	POWERUP_FLAG_SHIELDS	= 0x00000008,
};
private:
    int powerUps;
    
    int numOptions;
    
    int speedLevel;
    int activated;
    
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
    
private:
    void GetPowerup();
    
    void usePowerup();
    
private:
    void Upgrade_Speed();
    
    void Upgrade_Missiles();
    
    void Upgrade_Gun();
    
    void Upgrade_Lasers();
    
    void Upgrade_Option();
	void Option_Spread();
	
    void Upgrade_Shields();

};

#endif // PLAYER_H
