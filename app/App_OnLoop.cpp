#include "App.h"

void App::OnLoop()
{
	for(int i =0; i < Entity::EntityList.size(); i++)
	{
	    if(!Entity::EntityList[i])
		continue;
	    if(Entity::EntityList[i]->Dead == true)
	    {
		Entity::EntityList[i]->OnDeath();
		delete Entity::EntityList[i];
		Entity::EntityList.erase(Entity::EntityList.begin()+i);
	    }
	    else
	    {
		Entity::EntityList[i]->OnLoop();
	    }
	}//End entity loops
	
	for(int i = 0; i < EntityCol::EntityColList.size(); i++)
	{
	    Entity* EntityA = EntityCol::EntityColList[i].EntityA;
	    Entity* EntityB = EntityCol::EntityColList[i].EntityB;
	    
	    if(EntityA == NULL || EntityB == NULL)
		continue;
	    
	    if(EntityA->OnCollision(EntityB))
		EntityB->OnCollision(EntityA);
	}//End Collision Events For Loop
	
	EntityCol::EntityColList.clear();
	
	FPS::FPSControl.OnLoop();
	
	char Buffer[255];
	sprintf(Buffer, "%d", FPS::FPSControl.GetFPS());
	SDL_WM_SetCaption(Buffer, Buffer);
	SDL_Delay(1);
}
