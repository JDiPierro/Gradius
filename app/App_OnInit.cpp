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
 * TEST PLAYER:
 */
	if(Player1.OnLoad("./gfx/option.png",48,28,5) == false)
	{
		std::cout << "Player 1 init failed" << std::endl;
		return false;
	}
	Entity::EntityList.push_back(&Player1);
	
	/*if((Surf_Test = Surface::OnLoad("./gfx/option.png")) == NULL)
	{
		std::cout << "Test Surface Fail" << std::endl;
		return false;
	}*/
	AnimOption.Oscillate = false;
	AnimOption.SetFrameRate(200);



	/*END*/
	return true;
}
