#ifndef _LEVEL_H_
  #define _LEVEL_H_

#include "Level.h"
#include "Tile.h"

class Zone
{
public:
    static Zone		ZoneControl;
    
public:
    std::vector<Level>	LevelList;
    
private:
    int			ZoneSize;
    
    SDL_Surface*	Surf_Tileset;
    
public:
    Zone();
    
    bool	OnLoad(char* file);
    
    void	OnRender(SDL_Surface* Surf_Display, int CameraX, int CameraY);
    
    void	OnCleanup();
    
public:
    Level*	GetLevel(int X, int Y);
    Tile*	GetTile(int X, int Y);
};

#endif