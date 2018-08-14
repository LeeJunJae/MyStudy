#include "Collision.h"



bool Collision::RectInRect(RECT rtDesk, RECT rtSrc)
{

	POINT cDesk, cSrc;
	cDesk.x = (rtDesk.left + rtDesk.right) / 2;
	cDesk.y = (rtDesk.top + rtDesk.bottom) / 2;
	cSrc.x = (rtSrc.left + rtSrc.right) / 2;
	cSrc.y = (rtSrc.top + rtSrc.bottom) / 2;

	POINT radius;
	radius.x = abs(cDesk.x - cSrc.x);
	radius.y = abs(cDesk.y - cSrc.y);

	POINT deskRadius, srcRadius;
	deskRadius.x = (rtDesk.right - rtDesk.left) / 2;
	deskRadius.y = (rtDesk.bottom - rtDesk.top) / 2;
	srcRadius.x = (rtSrc.right - rtSrc.left) / 2;
	srcRadius.y = (rtSrc.bottom - rtSrc.top) / 2;

	if (radius.x <= (deskRadius.x + srcRadius.x) && radius.y <= (deskRadius.y + srcRadius.y))
	{
		return true;
	}

	return false;
}

bool Collision::RectInpt(RECT rt, POINT pt)
{
	if (rt.left <= pt.x && rt.right >= pt.x)
	{
		if (rt.top <= pt.y && rt.bottom >= pt.y)
		{
			return true;
		}
	}
	return false;
}

bool Collision::SphereInSpher(RECT rtDesk, RECT rtSrc)
{
	Sphere sphereDesk, sphereSrc;
	sphereDesk.center.x = (rtDesk.left + rtDesk.right) / 2;
	sphereDesk.center.y = (rtDesk.top + rtDesk.bottom) / 2;
	LONG dwX = (rtDesk.right - rtDesk.left) / 2;
	LONG dwY = (rtDesk.bottom - rtDesk.top) / 2;
	sphereDesk.radius = (dwX < dwY) ? dwY : dwX;

	sphereSrc.center.x = (rtSrc.left + rtSrc.right) / 2;
	sphereSrc.center.y = (rtSrc.top + rtSrc.bottom) / 2;
	dwX = (rtSrc.right - rtSrc.left) / 2;
	dwY = (rtSrc.bottom - rtSrc.top) / 2;
	sphereSrc.radius = (dwX < dwY) ? dwY : dwX;

	float fDistance = sqrt((sphereDesk.center.x - sphereSrc.center.x)* (sphereDesk.center.x - sphereSrc.center.x) +
			(sphereDesk.center.y - sphereSrc.center.y)* (sphereDesk.center.y - sphereSrc.center.y));

	if (fDistance < (sphereDesk.radius + sphereSrc.radius))
	{
		return true;
	}


	return false;
}

bool Collision::SphereInPt(RECT rtDesk, POINT pt)
{
	Sphere sphereDesk;
	sphereDesk.center.x = (rtDesk.left + rtDesk.right) / 2;
	sphereDesk.center.y = (rtDesk.top + rtDesk.bottom) / 2;
	LONG dwX = (rtDesk.right - rtDesk.left) / 2;
	LONG dwY = (rtDesk.bottom - rtDesk.top) / 2;
	sphereDesk.radius = (dwX < dwY) ? dwY : dwX;

	float fDistance = sqrt((sphereDesk.center.x - pt.x)*(sphereDesk.center.x - pt.x) +
			(sphereDesk.center.y - pt.y)*(sphereDesk.center.y - pt.y));

	if (fDistance < sphereDesk.radius)
	{
		return true;
	}



	return false;
}

Collision::Collision()
{
}


Collision::~Collision()
{
}
