#include "App.h"

void App::OnCleanup()
{
	//Cleanup and delete all the entities currently alive.
	for(int i = i; i < Entity::EntityList.size(); i++)
	{
	    if(Entity::EntityList[i])
	    {
		Entity::EntityList[i]->OnCleanup();
		delete Entity::EntityList[i];
	    }
	}

	//Cleanup the loaded font
	TTF_CloseFont(Font);
	//Quit out of the frameworks
	TTF_Quit();
	SDL_Quit();
	//Alert successfull cleanup TODO:Remove from final build
	std::cout << "Cleanup Complete." << std::endl;
}
