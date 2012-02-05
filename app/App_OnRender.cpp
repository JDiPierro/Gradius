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

	//SDL_Surface* Surf_Dest, SDL_Surface* Surf_Src, int X, int Y, int cropX, int cropY, int W, int H)

	/*
	 * TEST
	 */
	//Surface::OnDraw(Surf_Display,Surf_Test,0,0,0,AnimOption.GetCurrentFrame() * 27,47,27);
	
	for(int i = 0; i < Entity::EntityList.size(); i++)
	{
	    if(!Entity::EntityList[i])
		continue;
	    Entity::EntityList[i]->OnRender(Surf_Display);
	}


	SDL_Flip(Surf_Display);
}
