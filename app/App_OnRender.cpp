#include "App.h"

void App::OnRender()
{
	SDL_FillRect(Surf_Display, NULL, SDL_MapRGB(Surf_Display->format, 0, 0, 0));
	SDL_Rect Rect;
	Rect.x = 0;
	Rect.y = 0;
	Rect.w = Settings::SettingsControl.GetWinWidth();
	Rect.h = Settings::SettingsControl.GetWinHeight();

	SDL_FillRect(Surf_Display, &Rect, 0);

	//SDL_Surface* Surf_Dest, SDL_Surface* Surf_Src, int X, int Y, int cropX, int cropY, int W, int H)
	if(Surface::OnDraw(Surf_Display,Surf_Test,0,0,0,0,47,27) == false)
	{
		std::cout << "Option Draw Failed!" << std::endl;
	}

	/*
	 * TEST
	 */
	Surface::OnDraw(Surf_Display,Surf_Test,0,0,0,AnimOption.GetCurrentFrame() * 27,47,27);


	SDL_Flip(Surf_Display);
}
