#include "Bitmap.h"


bool Bitmap::Load(T_STR szLoadFile)
{
	HDC hdc = GetDC(g_hWnd);
	hBitmap = (HBITMAP)LoadImage(g_hInstance, szLoadFile.c_str(), IMAGE_BITMAP, 0, 0, LR_DEFAULTSIZE | LR_LOADFROMFILE);

	if (hBitmap != NULL)
	{
		GetObject(hBitmap, sizeof(BITMAP), &bmpInfo);
		hMemDC = CreateCompatibleDC(hdc);
		SelectObject(hMemDC, hBitmap);
		szName = szLoadFile;
		ReleaseDC(g_hWnd, hdc);

		return true;
	}
	ReleaseDC(g_hWnd, hdc);
	return false;
}




bool	Bitmap::Init()
{
	return true;
}
bool	Bitmap::Update()
{
	return true;
}
bool	Bitmap::Render()
{
	return true;
}
bool	Bitmap::Release()
{
	DeleteObject(hBitmap);
	ReleaseDC(g_hWnd, hMemDC);
	return true;
}



Bitmap::Bitmap()
{
}


Bitmap::~Bitmap()
{
}
