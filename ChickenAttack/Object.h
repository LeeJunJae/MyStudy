#pragma once
#include "BitmapMgr.h"
#include "Collision.h"

#define LR_ROTATION 0x01
#define TB_ROTATION 0x02
#define LRTB_ROTATION 0x04



class Object
{
public:
	Bitmap* pColorBitmap;
	Bitmap* pMaskBitmap;
	Point pos;
	Point posDraw;

	RECT rtDraw;
	RECT rtCollision;

	float dir[2];
	float speed;
	
	bool debugRect;
	bool dead;

public:
	
	virtual void	Set(Point pos);
	virtual void	Set(float x, float y, DWORD l, DWORD t, DWORD r, DWORD b);
	virtual bool	Load(const TCHAR* pszColor, const TCHAR* pszMask = 0);
	virtual bool	Init();
	virtual bool	Update();

	virtual bool    Draw(short sType, RECT* rt );
	virtual bool    DrawColorKey(DWORD maskColor);

	virtual bool	Render();
	virtual bool	Release();

public:
	Object();
	virtual ~Object();
};

