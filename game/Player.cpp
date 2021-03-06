#include "Player.h"
#include <iostream>
#include "Bullet.h"
//#include <math.h> //Unused right now. May use a logarithmic function for speed upgrades.

Player::Player()
{
    powerUps = 0;
    speedLevel = 1;
    numOptions = 0;
}

bool Player::OnLoad(char* File, int Width, int Height, int MaxFrames)
{
    if(Entity::OnLoad(File, Width, Height, MaxFrames) == false)
    {
	std::cout << "Player 1 Entity Load Failed" << std::endl;
	return false;
    }
    Entity::EntityList.push_back(this);
    Speed = 5; //base: 15 //1: 25 //2:40
    Type = ENTITY_TYPE_PLAYER;
    return true;
}

void Player::OnFire()
{
    if(lastFireTime + 50 < SDL_GetTicks())
    {
	if(numBullets < 2)
	{
	    //TODO: This was just for debugging, delete it at some point
	    if(numBullets < 0)
	    {
		std::cout << "NumBullets less than 0" << std::endl;
	    }
	    lastFireTime = SDL_GetTicks();
	    Bullet* bullet = new Bullet();
	    if(SpeedX > 0)
		bullet->OnLoad(this,4,4,0,X + SpeedX + Width - 20,Y + 12) == false;
	    else 
		bullet->OnLoad(this,4,4,0,X + Width - 20,Y + 12) == false;
	}
    }
}

void Player::GetPowerup()
{
    if(powerUps < 7)
	powerUps++;
    else
	powerUps = 1;
    std::cout << "Powerup total: " << powerUps << std::endl;
}

void Player::usePowerup()
{
    switch(powerUps)
    {
	case PUP_SPEED:
	{
	    if(speedLevel < 6)
	    {
		Upgrade_Speed();
	    }
	    break;
	}
	case PUP_MISSILES:
	{
	    if(!(activated ^ POWERUP_FLAG_MISSILES))
		Upgrade_Missiles();
	    break;
	}
	case PUP_GUNUP:
	{
	    Upgrade_Gun();
	    break;
	}
	case PUP_LASERS:
	{
	    Upgrade_Lasers();
	    break;
	}
	case PUP_OPTION:
	{
	    if(numOptions < 4)
	    {
		Upgrade_Option();
	    }
	    else
		Option_Spread();
	    break;
	}
	case PUP_SHIELD:
	{
	    if(activated ^ POWERUP_FLAG_SHIELDS)
		break;
	    else
		Upgrade_Shields();
	    break;
	}
	case PUP_SPECIAL:
	{
	    //TODO:Figure out specials O,o
	}
    }//end switch
    std::cout << "Remaining Powerups: " << powerUps << std::endl;
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

void Player::Upgrade_Speed()
{
    Speed = Speed + (speedLevel * 3);
    powerUps = PUP_NONE;
}
void Player::Upgrade_Gun()
{

}
void Player::Option_Spread()
{

}
void Player::Upgrade_Lasers()
{

}
void Player::Upgrade_Missiles()
{

}
void Player::Upgrade_Option()
{

}
void Player::Upgrade_Shields()
{

}

