#include "App.h"

bool App::OnInit()
{
/*
 * Load Settings from file:
 */
	if(!App::LoadSettings(PATH_TO_SETTINGS))
	{
		std::cout << "Load Settings failed." << std::endl;
		return false;
	}
/*
 * SDL Initialization:
 */
	if(SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		std::cout << "SDL Init Failed." << std::endl;
		return false;
	}
/*
 * Initialize Window:
 */
	if((Surf_Display = SDL_SetVideoMode(Settings::SettingsControl.GetWinWidth(), Settings::SettingsControl.GetWinHeight(), 32, SDL_HWSURFACE | SDL_DOUBLEBUF)) == NULL)
	{
		std::cout << "Display Create Failed." << std::endl;
		return false;
	}

/*
 * TEST SPRITE:
 */
	if((Surf_Test = Surface::OnLoad("./gfx/option.png")) == false)
	{
		std::cout << "Option image load failed." << std::endl;
		return false;
	}
	AnimOption.MaxFrames = 5;
	AnimOption.Oscillate = false;
	AnimOption.SetFrameRate(200);



	/*END*/
	return true;
}
