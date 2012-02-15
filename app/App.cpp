#include "App.h"

App::App()
{
	Running = true;
	PATH_TO_SETTINGS = "./settings/settings.txt";
}

int App::OnExecute()
{
    #define FPS 35 //TODO: Allow target framerate to be set.
    Uint32 waittime = 1000.0f/FPS;
    Uint32 framestarttime = 0;
    Sint32 delaytime;

    if(OnInit() == false)
	return -1;

    SDL_Event Event;

    while(Running)
    {
	while(SDL_PollEvent(&Event))
	    OnEvent(&Event);

	OnLoop();
	OnRender();
	delaytime = waittime - (SDL_GetTicks() - framestarttime);
	if(delaytime > 0)
	    SDL_Delay((Uint32)delaytime);
	framestarttime = SDL_GetTicks();
    }

    OnCleanup();

    return 0;
}

int main(int argc, char* argv[])
{
    App gameApp;

    return gameApp.OnExecute();
}
