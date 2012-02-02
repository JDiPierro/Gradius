#ifndef _TILE_H_
	#define _TIME_H_

#include "../settings/Settings.h"


class Tile
{
public:
	enum
	{
		TILE_TYPE_NONE = 0,
		TILE_TYPE_NORMAL,
		TILE_TYPE_BLOCK,
		TILE_TYPE_EFFECT
	};
public:
	int TileID;
	int TypeID;

public:
	Tile();
};


#endif
