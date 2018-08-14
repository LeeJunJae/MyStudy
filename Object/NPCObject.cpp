#include "NPCObject.h"

bool NPCObject::Update()
{
	int iHalfX = rtDraw.right / 2;
	int iHalfY = rtDraw.bottom / 2;

	if ((pos.x) < (g_rtClient.left - iHalfX))
	{
		dir[0] *= -1.0f;
		pos.x = g_rtClient.left + iHalfX;
	}

	if ((pos.y) < (g_rtClient.top - iHalfY))
	{
		dir[1] *= -1.0f;
		pos.y = g_rtClient.top + iHalfY;
	}

	if ((pos.x + iHalfX) > (g_rtClient.right))
	{
		dir[0] *= -1.0f;
		pos.x = g_rtClient.right - iHalfX;
	}

	if ((pos.y + iHalfY) > (g_rtClient.bottom))
	{
		dir[1] *= -1.0f;
		pos.y = g_rtClient.bottom - iHalfY;
	}

	pos.x += dir[0] * speed * g_fSecPerFrame;
	pos.y += dir[1] * speed * g_fSecPerFrame;

	rtCollision.left   = posDraw.x;
	rtCollision.top    = posDraw.y;
	rtCollision.right  = rtDraw.right;
	rtCollision.bottom = rtDraw.bottom;

	return true;
}

NPCObject::NPCObject()
{
	speed = 50.0f + (rand() % 150);
}


NPCObject::~NPCObject()
{
}
