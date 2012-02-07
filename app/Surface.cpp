#include "Surface.h"
#include <iostream>

Surface::Surface()
{
	//
}

SDL_Surface* Surface::OnLoad(char* File)
{
    SDL_Surface* Surf_Temp = NULL;
    SDL_Surface* Surf_Return = NULL;

    //Attempt to load the passed file into the temporary surface.
    if((Surf_Temp = IMG_Load(File)) == NULL)
    {
	    std::cout << "Surface Load Failed" << std::endl;
	    return NULL;
    }

    //If the image has an alpha layer format it to display transparency and save it in the returned surface.
    Surf_Return = SDL_DisplayFormatAlpha(Surf_Temp);
    SDL_FreeSurface(Surf_Temp);
    return Surf_Return;
}

bool Surface::OnDraw(SDL_Surface* Surf_Dest, SDL_Surface* Surf_Src, int X, int Y)
{
    if(Surf_Dest == NULL || Surf_Src == NULL)
	    return false;

    SDL_Rect DestR;
    DestR.x = X;
    DestR.y = Y;
    
    //Blitting is the act of putting one surface on top of another surface.
    SDL_BlitSurface(Surf_Src, NULL, Surf_Dest, &DestR);

    return true;
}

//This is an overload of the OnDraw that allows us to crop the image.
//This allows for sprite-sheet based animation instead of every frame being a separate file.
bool Surface::OnDraw(SDL_Surface* Surf_Dest, SDL_Surface* Surf_Src, int X, int Y, int cropX, int cropY, int W, int H)
{
    if(Surf_Dest == NULL || Surf_Src == NULL)
	    return false;

    SDL_Rect DestR;
    DestR.x = X;
    DestR.y = Y;

    SDL_Rect SrcR;
    SrcR.x = cropX;
    SrcR.y = cropY;
    SrcR.w = W;
    SrcR.h = H;

    SDL_BlitSurface(Surf_Src, &SrcR, Surf_Dest, &DestR);

    return true;
}
