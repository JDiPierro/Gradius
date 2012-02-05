#include "App.h"

void App::OnCleanup()
{

	if(Surf_Test != NULL)
		SDL_FreeSurface(Surf_Test);
	
	for(int i = i; i < Entity::EntityList.size(); i++)
	{
	    if(Entity::EntityList[i])
	    {
		delete Entity::EntityList[i];
	    }
	}

	SDL_Quit();
	std::cout << "Cleanup Complete." << std::endl;
}
