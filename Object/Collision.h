#pragma once
#include <Windows.h>
#include <math.h>


struct Sphere
{
	POINT center;
	float radius;
};


class Collision
{
public:
	static	bool RectInRect(RECT rtDesk, RECT rtSrc);
	static	bool RectInpt(RECT rt, POINT pt);
	static	bool SphereInSpher(RECT rtDesk, RECT rtSrc);
	static	bool SphereInPt(RECT rtDesk, POINT pt);
public:
	Collision();
	~Collision();
};

