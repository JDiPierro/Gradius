#include "Camera.h"

Camera Camera::CameraControl;

Camera::Camera()
{
	X = Y = 0;
	TargetX = TargetY = NULL;

	TargetMode = TARGET_MODE_NORMAL;
}

void Camera::OnMove(int MoveX, int MoveY)
{
	X += MoveX;
	Y += MoveY;
}

int Camera::GetX()
{
	if(TargetX != NULL)
	{
		if(TargetMode == TARGET_MODE_CENTER)
		{
			return *TargetX - (Settings::SettingsControl.GetWinWidth() / 2);
		}

		return *TargetX;
	}

	return X;
}

int Camera::GetY()
{
	if(TargetY != NULL)
	{
		if(TargetMode == TARGET_MODE_CENTER)
		{
			return *TargetY - (Settings::SettingsControl.GetWinHeight() / 2);
		}

		return *TargetY;
	}
	return Y;
}

void Camera::SetPos(int X, int Y)
{
	this->X = X;
	this->Y = Y;
}

void Camera::SetTarget(float* X, float* Y)
{
	TargetX = X;
	TargetY = Y;
}
