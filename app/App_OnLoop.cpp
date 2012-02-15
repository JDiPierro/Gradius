#include "App.h"

void App::OnLoop()
{
    //Handle collisions that occured last loop.
    for(int i = 0; i < EntityCol::EntityColList.size(); i++)
    {
	Entity* EntityA = EntityCol::EntityColList[i].EntityA;
	Entity* EntityB = EntityCol::EntityColList[i].EntityB;
	
	//One of the entities is null, so skip this pair.
	if(EntityA == NULL || EntityB == NULL)
	    continue;
	
	//Tell the entities they collided with the others so they can handle it.
	if(EntityA->OnCollision(EntityB))
	    EntityB->OnCollision(EntityA);
    }//End Collision Events For Loop
    //Clear out the collision list in preparation for the next loop cycle
    EntityCol::EntityColList.clear();
    
    //Let entities have their 15 ticks of fame.
    for(int i =0; i < Entity::EntityList.size(); i++)
    {
	if(!Entity::EntityList[i])
	    continue;
	//Handle dead entities before the living get their spotlight.
	if(Entity::EntityList[i]->isDead() == true)
	{
	    //Let the entity have some final words..
	    Entity::EntityList[i]->OnDeath();
	    //then remove it from existence
	    delete Entity::EntityList[i];
	    //Remove it from the list. This will also shrink the vector.
	    Entity::EntityList.erase(Entity::EntityList.begin()+i);
	}
	else
	{
	    //Let the living entities do their thing.
	    Entity::EntityList[i]->OnLoop();
	}
    }//End entity loop
    
    //Calculate the current FPS.
    FPS::FPSControl.OnLoop();
    
    //Change the window title to the FPS for debugging. TODO:Get rid of this for final build
    char Buffer[255];
    sprintf(Buffer, "FPS: %d", FPS::FPSControl.GetFPS());
    SDL_WM_SetCaption(Buffer, Buffer);
}
