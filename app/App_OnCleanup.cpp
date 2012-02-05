#include "App.h"

void App::OnCleanup()
{
	
	for(int i = i; i < Entity::EntityList.size(); i++)
	{
	    if(Entity::EntityList[i])
	    {
		Entity::EntityList[i]->OnCleanup();
		delete Entity::EntityList[i];
	    }
	}

	SDL_Quit();
	std::cout << "Cleanup Complete." << std::endl;
}
