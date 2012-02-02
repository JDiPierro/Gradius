#include "Settings.h"

Settings Settings::SettingsControl;

Settings::Settings()
{
	WWIDTH  		= 600;
	WHEIGHT 		= 600;
	TILE_SIZE 	= 16;
	MAP_WIDTH 	= 40;
	MAP_HEIGHT 	= 40;
}

int Settings::GetWinWidth()
{
	return WWIDTH;
}

int Settings::GetWinHeight()
{
	return WHEIGHT;
}

int Settings::GetTileSize()
{
	return TILE_SIZE;
}

int Settings::GetMapWidth()
{
	return WWIDTH;
}

int Settings::GetMapHeight()
{
	return WHEIGHT;
}
