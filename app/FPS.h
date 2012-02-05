#ifndef _FPS_H_
	#define _FPS_H_

#include <SDL/SDL.h>

class FPS
{
public:
	static FPS FPSControl;

private:
	int	OldTime;
	int	LastTime;

	float	SpeedFactor;

	int NumFrames;
	int Frames;

public:
	FPS();
	void OnLoop();

public:
	int GetFPS();
	float GetSpeedFactor();
};

#endif
