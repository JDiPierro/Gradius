#include "App.h"

void App::OnCleanup()
{

	if(Surf_Test != NULL)
		SDL_FreeSurface(Surf_Test);

	SDL_Quit();
	std::cout << "Cleanup Complete." << std::endl;
}
