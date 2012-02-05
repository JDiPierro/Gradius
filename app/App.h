#ifndef _APP_H_
	#define _APP_H_

#include <SDL/SDL.h>
#include <iostream>					//For debugging.

#include "Event.h"
#include "Surface.h"
#include "Animation.h"
#include "../world/Camera.h"
//#include "../game/Entity.h"
#include "../game/Player.h"
//#include "../game/Bullet.h"
#include "../settings/Settings.h"

class App : public Event
{
private:
	bool Running;

	SDL_Surface* Surf_Display;
	/*
	 * TESTS:
	 */
	Player Player1;
	
	Animation AnimOption;
private:
	SDL_Surface* Surf_Bullet;

public:
	App();

	int OnExecute();

public:
	char* PATH_TO_SETTINGS;

	bool OnInit();

	void OnEvent(SDL_Event* Event);

		void OnKeyDown(SDLKey sym, SDLMod mod, Uint16 unicode);
		void OnKeyUp(SDLKey sym, SDLMod mod, Uint16 unicode);
		void OnExit();

	void OnLoop();

	void OnRender();

	void OnCleanup();

	bool LoadSettings(char* File);
};

#endif
