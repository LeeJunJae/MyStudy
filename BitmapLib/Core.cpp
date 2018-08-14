#include "Core.h"

HDC g_hOffScreenDC = NULL;

bool	Core::GameInit() 
{	
	Timer.Init();
	I_Input.Init();

	hScreenDC = GetDC(hWnd);
	hOffScreenDC = CreateCompatibleDC(hScreenDC);
	g_hOffScreenDC = hOffScreenDC;

	hOffScreenBitmap = CreateCompatibleBitmap(hScreenDC, g_rtClient.right,g_rtClient.bottom);
	SelectObject(hOffScreenDC, hOffScreenBitmap);

	COLORREF bkColor = RGB(255, 0, 0);
	hbrBack = CreateSolidBrush(bkColor);
	SelectObject(hOffScreenDC, hbrBack);

	Init();
	return true;
}
bool	Core::GameFrame()
{
	Timer.Update();
	I_Input.Update();	
	Frame();
	return true;
}
bool	Core::GamePreRender()
{
	PatBlt(hOffScreenDC, 0, 0,g_rtClient.right,g_rtClient.bottom,	PATCOPY);
	return true;
}
bool	Core::GamePostRender()
{
	BitBlt(hScreenDC, 0, 0, g_rtClient.right,	g_rtClient.bottom,	hOffScreenDC, 0, 0, SRCCOPY);
	return true;
}
bool	Core::GameRender()
{
	GamePreRender();
	{
		Render();
		Timer.Render();
		I_Input.Render();
	}
	GamePostRender();
	return true;
}
bool	Core::GameRun() 
{
	GameFrame();	
	GameRender();
	return true;
}
bool	Core::GameRelease()
{
	Release();
	Timer.Release();
	I_Input.Release();

	DeleteObject(hbrBack);
	DeleteObject(hOffScreenBitmap);
	ReleaseDC(hWnd, hScreenDC);
	ReleaseDC(hWnd, hOffScreenDC);
	return true;
}
Core::Core()
{
}


Core::~Core()
{
}
