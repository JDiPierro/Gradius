#include "App.h"

void App::OnLoop()
{
	for(int i =0; i < Entity::EntityList.size(); i++)
	{
	    if(!Entity::EntityList[i])
		continue;
	    Entity::EntityList[i]->OnLoop();
	}//End For Loop
	
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
}
