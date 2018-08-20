#include "Core.h"

HDC g_hOffScreenDC = NULL;

bool	Core::GameInit()
{
	timer.Init();
	I_Input.Init();

	hScreenDC = GetDC(hWnd);
	hOffScreenDC = CreateCompatibleDC(hScreenDC);
	g_hOffScreenDC = hOffScreenDC;

	hOffScreenBitmap = CreateCompatibleBitmap(hScreenDC, client.right, client.bottom);
	SelectObject(hOffScreenDC, hOffScreenBitmap);

	COLORREF bkColor = RGB(255, 0, 0);
	hbrBack = CreateSolidBrush(bkColor);
	SelectObject(g_hOffScreenDC, hbrBack);

	Init();
	return true;
}

bool	Core::GameUpdate()
{
	timer.Update();
	I_Input.Update();

	Update();
	return true;
}

//////////////////////////RENDER//////////////////////////

bool	Core::GameRender()
{
	GamePreRender();
	{
		Render();
		timer.Render();
		I_Input.Render();
	}
	GamePostRender();
	return true;
}
bool	Core::GamePreRender()
{
	PatBlt(hOffScreenDC, 0, 0, client.right, client.bottom, PATCOPY);
	return true;
}
bool	Core::GamePostRender() 
{
	BitBlt(hScreenDC, 0, 0, client.right, client.bottom, hOffScreenDC, 0, 0, SRCCOPY);
	return true;
}

bool	Core::GameRun()
{
	GameUpdate();
	GameRender();
	return true;
}

///////////////////////////RELEASE/////////////////////////
bool	Core::GameRelease()
{
	Release();
	//////////////////////////////////////추가 삭제 되는 클래스들 작성부
	I_Input.Release();
	timer.Release();
	/////////////////////////////////////

	DeleteObject(hbrBack);
	DeleteObject(hOffScreenBitmap);
	ReleaseDC(hWnd, hScreenDC);
	ReleaseDC(hWnd, hOffScreenDC);

	return true;

}



/////////////
Core::Core()
{

}
Core::~Core()
{

}
