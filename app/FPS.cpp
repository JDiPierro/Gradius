#include "FPS.h"

FPS FPS::FPSControl;

FPS::FPS() {
	OldTime     = 0;
	LastTime    = 0;

	SpeedFactor	= 0;

	Frames      = 0;
	NumFrames   = 0;
	
}

void FPS::OnLoop() {
	//More than a second has passed since the last FPS update
	if(OldTime + 1000 < SDL_GetTicks())
	{
	    OldTime = SDL_GetTicks();

	    //The FPS is the number of frames that rendered in the last loop.
	    NumFrames = Frames;

	    //Start counting frames from 0 again.
	    Frames = 0;
	}
	//Controls how fast the game runs. TODO: Change the 32.0f to a user-controlled TARGET_FRAMERATE setting.
	SpeedFactor = ((SDL_GetTicks() - LastTime) / 1000.0f) * 32.0f;
	
	LastTime = SDL_GetTicks();

	Frames++;
}

int FPS::GetFPS() {
    return NumFrames;
}

float FPS::GetSpeedFactor() {
    return SpeedFactor;
}
