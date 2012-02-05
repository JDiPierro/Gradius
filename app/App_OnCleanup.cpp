#include "App.h"

void App::OnCleanup()
{

	if(Surf_Bullet != NULL)
		SDL_FreeSurface(Surf_Bullet);
	
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
