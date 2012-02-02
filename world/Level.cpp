#include "Level.h"

Level::Level()
{
	Surf_Tileset = NULL;
}

bool Level::OnLoad(char* File)
{
	TileList.clear();

	FILE* FileHandle = fopen(File, "r");

	if(FileHandle == NULL)
	{
		return false;
	}

	for(int Y = 0; Y < Settings::SettingsControl.GetMapHeight(); Y++)
	{
		for(int X = 0; X < Settings::SettingsControl.GetMapWidth(); X++)
		{
			Tile tempTile;

			fscanf(FileHandle, "%d:%d ", &tempTile.TileID, &tempTile.TypeID);
			TileList.push_back(tempTile);
		}
		fscanf(FileHandle, "\n");
	}
	fclose(FileHandle);
	return true;
}

void Level::OnRender(SDL_Surface* Surf_Display, int MapX, int MapY)
{
	int TILE_SIZE = Settings::SettingsControl.GetTileSize();
	if(Surf_Tileset == NULL)
		return;

	int TilesetWidth	= Surf_Tileset->w / TILE_SIZE;
	int TilsetHeight	= Surf_Tileset->h / TILE_SIZE;

	int ID = 0;

	for(int Y = 0; Y < Settings::SettingsControl.GetMapHeight(); Y++)
	{
		for(int X = 0; X < Settings::SettingsControl.GetMapWidth(); X++)
		{
			if(TileList[ID].TypeID == Tile::TILE_TYPE_NONE)
			{
				ID++;
				continue;
			}

			int tX = MapX + (X * TILE_SIZE);
			int tY = MapY + (Y * TILE_SIZE);

			int TileSetX = (TileList[ID].TileID % TilesetWidth) * TILE_SIZE;
			int TileSetY = (TileList[ID].TileID / TilesetWidth) * TILE_SIZE;

			Surface::OnDraw(Surf_Display, Surf_Tileset, tX, tY, TileSetX, TileSetY, TILE_SIZE, TILE_SIZE);

			ID++;
		}//End for X
	}//End for Y
}//End OnRender

Tile* Level::GetTile(int X, int Y)
{
	int ID = 0;
	ID = X / Settings::SettingsControl.GetTileSize();
	ID = ID + (Settings::SettingsControl.GetMapWidth() * (Y / Settings::SettingsControl.GetTileSize()));

	if(ID < 0 || ID >= TileList.size())
		return NULL;

	return &TileList[ID];
}//End GetTile
