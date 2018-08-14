#pragma once
#include <windows.h>
#include <math.h>
struct TSphere
{
	POINT pCenter;
	float fRadius;
};

class TCollision
{
public:
	static bool	RectInRect(RECT rtDesk, RECT rtSrc);
	static bool	RectInPt(RECT rtDesk, POINT pt);
	static bool	SphereInSphere(RECT rtDesk, RECT rtSrc);
	static bool	SphereInPt(RECT rtDesk, POINT pt);
public:
	TCollision();
	virtual ~TCollision();
};

