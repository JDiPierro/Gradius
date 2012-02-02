#include "App.h"

App::App()
{
	Running = true;
	PATH_TO_SETTINGS = "settings.txt";
}

int App::OnExecute()
{
	if(OnInit() == false)
		return -1;

	SDL_Event Event;

	while(Running)
	{
		while(SDL_PollEvent(&Event))
			OnEvent(&Event);

		OnLoop();
		OnRender();
	}

	OnCleanup();

	return 0;
}

int main(int argc, char* argv[])
{
	App gameApp;

	return gameApp.OnExecute();
}
