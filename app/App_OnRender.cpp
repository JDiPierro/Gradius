#include "App.h"

void App::OnRender()
{
	//Fills the screen with black to avoid ghosting.
	//SDL_FillRect(Surf_Display, NULL, SDL_MapRGB(Surf_Display->format, 0, 0, 0));
	SDL_Rect Rect;
	Rect.x = 0;
	Rect.y = 0;
	Rect.w = Settings::SettingsControl.GetWinWidth();
	Rect.h = Settings::SettingsControl.GetWinHeight();

	SDL_FillRect(Surf_Display, &Rect, 0);
	
	//Render each entity to the Display.
	for(int i = 0; i < Entity::EntityList.size(); i++)
	{
	    if(!Entity::EntityList[i])
		continue;
	    Entity::EntityList[i]->OnRender(Surf_Display);
	}
	
	//Flip the renders from the Buffer to the Display.
	SDL_Flip(Surf_Display);
}
