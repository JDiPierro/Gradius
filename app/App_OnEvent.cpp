#include "App.h"
#include "../game/Powerup.h" //TODO: FOR DEBUG ONLY. Remove later

void App::OnEvent(SDL_Event* Event)
{
    Event::OnEvent(Event);
}

void App::OnExit()
{
    //Exits the main game loop
    Running = false;
}

void App::OnKeyDown(SDLKey sym, SDLMod mod, Uint16 unicode)
{
    switch(sym)
    {
	case SDLK_LEFT:
	{
	    Player1.MoveLeft = true;
	    break;
	}
	case SDLK_RIGHT:
	{
	    Player1.MoveRight = true;
	    break;
	}
	case SDLK_UP:
	{
	    Player1.MoveUp = true;
	    break;
	}
	case SDLK_DOWN:
	{
	    Player1.MoveDown = true;
	    break;
	}
	case SDLK_SPACE:
	{
	    Player1.Firing = true;
	    break;
	}
	case SDLK_LCTRL:
	{
	    Player1.usePowerup();
	    break;
	}
    }
}

void App::OnKeyUp(SDLKey sym, SDLMod mod, Uint16 unicode)
{
	switch(sym)
	{
	    case SDLK_LEFT:
	    {
		Player1.MoveLeft = false;
		break;
	    }
	    case SDLK_RIGHT:
	    {
		Player1.MoveRight = false;
		break;
	    }
	    case SDLK_UP:
	    {
		Player1.MoveUp = false;
		break;
	    }
	    case SDLK_DOWN:
	    {
		Player1.MoveDown = false;
		break;
	    }
	    case SDLK_SPACE:
	    {
		Player1.Firing = false;
		break;
	    }
	    case SDLK_LCTRL:
	    {
		break;
	    }
	}
}

void App::OnLButtonDown(int mX, int mY)
{
    Powerup* pUp = new Powerup(mX,mY);
}