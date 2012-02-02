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
	/**/
}

void App::OnKeyUp(SDLKey sym, SDLMod mod, Uint16 unicode)
{
	/**/
}
