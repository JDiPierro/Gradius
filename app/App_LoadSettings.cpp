#include "App.h"

bool App::LoadSettings(char* File)
{
	FILE* SettingsFile = fopen(File,"r");

	if(SettingsFile == NULL)
	{
		std::cout << "Settings file not found." << std::endl;
		return false;
	}



	/* LOAD SETTINGS HERE */

	return true;
}
