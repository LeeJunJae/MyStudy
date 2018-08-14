#include "Collision.h"



bool Collision::RectInRect(RECT rtDesk, RECT rtSrc)
{

	POINT cDesk;
	cDesk.x = (rtDesk.left + (rtDesk.left + rtDesk.right)) / 2;
	cDesk.y = (rtDesk.top + (rtDesk.top + rtDesk.bottom))  / 2;

	POINT cSrc;
	cSrc.x = (rtSrc.left + (rtSrc.left + rtSrc.right)) / 2;
	cSrc.y = (rtSrc.top + (rtSrc.top + rtSrc.bottom)) / 2;

	POINT radius;
	radius.x = abs(cDesk.x - cSrc.x);
	radius.y = abs(cDesk.x - cSrc.x);

	POINT deskRadius, srcRadius;
	deskRadius.x = ((rtDesk.left + rtDesk.right) - rtDesk.left) / 2;
	deskRadius.y = ((rtDesk.top + rtDesk.bottom) - rtDesk.top) / 2;

	srcRadius.x = ((rtSrc.left + rtSrc.right) - rtSrc.left) / 2;
	srcRadius.y = ((rtSrc.top + rtSrc.bottom) - rtSrc.top) / 2;

	if (radius.x  <= (srcRadius.x + deskRadius.x) && (srcRadius.y + deskRadius.y) )
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
	Sphere sphereDesk;
	sphereDesk.center.x = (rtDesk.left + (rtDesk.left + rtDesk.right)) / 2;
	sphereDesk.center.y = (rtDesk.top + (rtDesk.top + rtDesk.bottom)) / 2;


	LONG dwX = (rtDesk.right - rtDesk.left) / 2;
	LONG dwY = (rtDesk.top - rtDesk.bottom) / 2;


	sphereDesk.radius = (dwX < dwY) ? dwY : dwX;


	Sphere sphereSrc;
	sphereSrc.center.x = (rtSrc.left + (rtSrc.left + rtSrc.right)) / 2;
	sphereSrc.center.y = (rtSrc.top + (rtSrc.top + rtSrc.bottom)) / 2;


	LONG dwX = (rtSrc.right - rtSrc.left) / 2;
	LONG dwY = (rtSrc.top - rtSrc.bottom) / 2;


	sphereSrc.radius = (dwX < dwY) ? dwY : dwX;

	float distance = sqrt((sphereDesk.center.x - sphereSrc.center.x) ^ 2 + (sphereDesk.center.y - sphereSrc.center.y) ^ 2); 

	if (distance < (sphereDesk.radius + sphereSrc.radius))
	{
		return true;
	}


	return false;
}

bool Collision::SphereInPt(RECT rtDesk, POINT pt)
{
	Sphere sphereDesk;
	sphereDesk.center.x = (rtDesk.left + (rtDesk.left + rtDesk.right)) / 2;
	sphereDesk.center.y = (rtDesk.top + (rtDesk.top + rtDesk.bottom)) / 2;
	LONG dwX = (rtDesk.right - rtDesk.left) / 2;
	LONG dwY = (rtDesk.top - rtDesk.bottom) / 2;
	sphereDesk.radius = (dwX < dwY) ? dwY : dwX;





	return false;
}

Collision::Collision()
{
}


Collision::~Collision()
{
}
