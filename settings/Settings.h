#ifndef _SETTINGS_H_
	#define _SETTINGS_H_

class Settings
{
public:
	static Settings SettingsControl;
/*
 * FUNCTIONS:
 */
public:
	Settings();

public:
	int GetWinWidth();
	int GetWinHeight();

public:
	int GetTileSize();

public:
	int GetMapWidth();
	int GetMapHeight();

/*
 * SETTING VARS:
 */
private:
	int WWIDTH;
	int WHEIGHT;

private:
	int TILE_SIZE;

private:
	int MAP_WIDTH;
	int MAP_HEIGHT;

};


#endif
