#ifndef _SURFACE_H_
	#define _SURFACE_H_

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

class Surface
{
public:
	Surface();

public:
	static SDL_Surface* OnLoad(char* File);

	static bool OnDraw(SDL_Surface* Surf_Dest, SDL_Surface* Surf_Src, int X, int Y);

	static bool OnDraw(SDL_Surface* Surf_Dest, SDL_Surface* Surf_src, int X, int Y, int crop_X, int crop_Y, int W, int H);
};

#endif
