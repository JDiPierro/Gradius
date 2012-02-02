#ifndef _LEVEL_H_
	#define _LEVEL_H_

#include <SDL/SDL.h>
#include <vector>

#include "Zone.h"
#include "../app/Surface.h"
#include "../settings/Settings.h"

class Level
{
public:
	SDL_Surface* Surf_Tileset;

private:
	std::vector<Tile> TileList;

public:
	Level();

public:
	bool OnLoad(char* File);
	void OnRender(SDL_Surface* Surf_Display, int MapX, int MapY);

public:
	Tile* GetTile(int X, int Y);
};

#endif
