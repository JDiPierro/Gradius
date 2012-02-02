#ifndef _CAMERA_H_
	#define _CAMERA_H_

#include <SDL/SDL.h>

#include "../settings/Settings.h"

enum
{
	TARGET_MODE_NORMAL = 0,
	TARGET_MODE_CENTER
};

class Camera
{
public:
	static Camera CameraControl;

private:
	int X;
	int Y;

	float* TargetX;
	float* TargetY;

public:
	int TargetMode;

public:
	Camera();

public:
	void OnMove(int MoveX, int MoveY);

public:
	int GetX();
	int GetY();

public:
	void SetPos(int X, int Y);
	void SetTarget(float* X, float* Y);
};

#endif
