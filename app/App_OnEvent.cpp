#include "App.h"

void App::OnEvent(SDL_Event* Event)
{
    Event::OnEvent(Event);
}

void App::OnExit()
{
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
		Player1.SpeedHack = 3;
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
		Player1.SpeedHack= 1;
		break;
	    }
	}
}
