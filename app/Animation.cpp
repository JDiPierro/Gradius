#include "Animation.h"

Animation::Animation()
{
	CurrentFrame 		= 0;
	MaxFrames			= 0;
	FrameInc			= 1;

	FrameRate			= 100; //Milliseconds
	OldTime				= 0;
	Oscillate			= false;
}

void Animation::OnAnimate() {
    //Check to see if enough ticks have passed to render another frame
    //
    //Ticks are milliseconds since the process started.
    if(OldTime + FrameRate > SDL_GetTicks())
    {
        return;
    }
    //The new old time is the current time.
    OldTime = SDL_GetTicks();
    
    //Increment the current frame.
    CurrentFrame += FrameInc;

    if(Oscillate)
    {
        if(FrameInc > 0)
        {
            if(CurrentFrame >= MaxFrames - 1)
            {
                FrameInc = -FrameInc;
            }
        }
        else if(CurrentFrame <= 0)
        {
			FrameInc = -FrameInc;
		}
    }
    else if(CurrentFrame >= MaxFrames - 1)
	{
		CurrentFrame = 0;
	}
}

void Animation::SetFrameRate(int Rate)
{
    FrameRate = Rate;
}

void Animation::SetCurrentFrame(int Frame)
{
    if(Frame < 0 || Frame >= MaxFrames) return;

    CurrentFrame = Frame;
}

int Animation::GetCurrentFrame()
{
    return CurrentFrame;
}
