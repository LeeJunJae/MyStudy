#include "NPCObject.h"



bool NPCObject::Update()
{
	

	int iHalfX = rtDraw.right / 2;
	int iHalfY = rtDraw.bottom / 2;

	/*if ((pos.x + iHalfX) > g_rtClient.right)
	{
		dir[0] *= -1.0f;
		pos.x = g_rtClient.right - iHalfX;
	}
	if (pos.y + iHalfY > g_rtClient.bottom)
	{
		dir[1] *= -1.0f;
		pos.y = g_rtClient.bottom - iHalfY;
	}
	if ((pos.x - iHalfX) < g_rtClient.left)
	{
		dir[0] *= -1.0f;
		pos.x = g_rtClient.left + iHalfX;
	}
	if (pos.y - iHalfY < g_rtClient.top)
	{
		dir[1] *= -1.0f;
		pos.y = g_rtClient.top + iHalfY;
	}*/
	//if()


	pos.x += fdir *  speed  *g_fSecPerFrame;
	//pos.y += dir[1] * speed  *g_fSecPerFrame;

	posDraw.x = pos.x -iHalfX;
	posDraw.y = pos.y  -iHalfY;

	rtCollision.left = posDraw.x;
	rtCollision.top = posDraw.y;
	rtCollision.right = rtCollision.left + rtDraw.right;
	rtCollision.bottom = rtCollision.top + rtDraw.bottom;

	if (pos.x > 1480)
	{
		this->~NPCObject();
	}

	return true;
}

NPCObject::NPCObject()
{
	speed = 1.0f;
}


NPCObject::~NPCObject()
{
	
}
