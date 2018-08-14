#include "Object.h"
#include "Input.h"

#pragma comment(lib, "msimg32.lib")

bool	Object::Load(const TCHAR* pszColor,	const TCHAR* pszMask)
{
	int iIndex = I_BitmapMgr.Load(pszColor);
	pColorBitmap = I_BitmapMgr.GetPtr(iIndex);
	if (pszMask != NULL)
	{
		iIndex = I_BitmapMgr.Load(pszMask);
		pMaskBitmap = I_BitmapMgr.GetPtr(iIndex);
	}
	return true;
};
void	Object::Set(Point pos)
{
	this->pos = pos;
	dir[0] = (rand() % 2) ? 1.0f : -1.0f;
	dir[1] = (rand() % 2) ? 1.0f : -1.0f;
}
void	Object::Set(float x, float y,DWORD left,DWORD top,DWORD right,DWORD bottom)
{
	pos.x = x;
	pos.y = y;
	rtDraw.left = left;
	rtDraw.right = right;
	rtDraw.top = top;
	rtDraw.bottom = bottom;
}
bool	Object::Init()
{

	return true;
}
bool	Object::Update()
{
	if (I_Input.Key('W'))
	{
		pos.y += -1 * g_fSecPerFrame*300.0f;
	}
	if (I_Input.Key('S'))
	{
		pos.y += 1 * g_fSecPerFrame*300.0f;
	}
	if (I_Input.Key('A'))
	{
		pos.x += -1 * g_fSecPerFrame*300.0f;
	}
	if (I_Input.Key('D'))
	{
		pos.x += 1 * g_fSecPerFrame*300.0f;
	}

	rtCollision.left = posDraw.x;
	rtCollision.top = posDraw.y;
	rtCollision.right = rtDraw.right;
	rtCollision.bottom = rtDraw.bottom;

	return true;
}
bool   Object::Draw(short sType, RECT* rt)
{
	RECT rtDraw = this->rtDraw;
	if (rt != 0)
	{
		rtDraw = *rt;
	}

	switch (sType)
	{
	case LR_ROTATION:
	{
		StretchBlt(g_hOffScreenDC,
			pos.x + rtDraw.right, pos.y,
			-rtDraw.right,
			rtDraw.bottom,
			pColorBitmap->hMemDC,
			rtDraw.left, rtDraw.top,
			rtDraw.right, rtDraw.bottom,
			SRCCOPY);
	}break;
	case TB_ROTATION:
	{
		StretchBlt(g_hOffScreenDC,
			pos.x, pos.y + rtDraw.bottom,
			rtDraw.right,
			-rtDraw.bottom,
			pColorBitmap->hMemDC,
			rtDraw.left, rtDraw.top,
			rtDraw.right, rtDraw.bottom,
			SRCCOPY);
	}break;
	case LRTB_ROTATION:
	{
		StretchBlt(g_hOffScreenDC, pos.x + rtDraw.right, pos.y + rtDraw.bottom, -rtDraw.right, -rtDraw.bottom, 
				   pColorBitmap->hMemDC, rtDraw.left, rtDraw.top, rtDraw.right, rtDraw.bottom, SRCCOPY);
	}break;
	default:
	{
		StretchBlt(g_hOffScreenDC, pos.x, pos.y, rtDraw.right, rtDraw.bottom, pColorBitmap->hMemDC, 
				   rtDraw.left, rtDraw.top, rtDraw.right, rtDraw.bottom, SRCCOPY);
	}break;
	}
	return true;
}
bool    Object::DrawColorKey(DWORD maskColor)
{
	TransparentBlt(g_hOffScreenDC, pos.x, pos.y, rtDraw.right, rtDraw.bottom, pColorBitmap->hMemDC, rtDraw.left, rtDraw.top, rtDraw.right, rtDraw.bottom, maskColor);
	return true;
}
bool	Object::Render()
{
	if (pMaskBitmap == NULL)
	{
		BitBlt(g_hOffScreenDC, pos.x, pos.y, rtDraw.right, rtDraw.bottom, pColorBitmap->hMemDC, rtDraw.left, rtDraw.top, SRCCOPY);
		return true;
	}
	else
	{
		BitBlt(g_hOffScreenDC, pos.x, pos.y, rtDraw.right, rtDraw.bottom, pMaskBitmap->hMemDC, rtDraw.left, rtDraw.top, SRCAND);
		BitBlt(g_hOffScreenDC, pos.x, pos.y, rtDraw.right, rtDraw.bottom, pColorBitmap->hMemDC, rtDraw.left,rtDraw.top, SRCINVERT);//XOR
		BitBlt(g_hOffScreenDC, pos.x, pos.y, rtDraw.right, rtDraw.bottom, pMaskBitmap->hMemDC, rtDraw.left, rtDraw.top, SRCINVERT);
	}

	return true;
}
bool	Object::Release() {

	return true;
}




Object::Object()
{
	pos.x = 0;
	pos.y = 0;
	pColorBitmap = NULL;
	pMaskBitmap = NULL;

	speed = 1.0f;
	dir[0] = 1.0f;
	dir[1] = 1.0f;
	
}


Object::~Object()
{
}
