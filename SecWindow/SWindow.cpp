#include "SWindow.h"

#include <tchar.h>
#pragma comment(lib, "winmm.lib")

DWORD KeyState[256];


int   FPS = 0;
int TempCount = 0;
float SecPerFrame = 0.0f;
float GameTime = 0.0f;

TCHAR Buffer[255];
DWORD Tick = timeGetTime();




LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	switch (iMessage)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}

	return (DefWindowProc(hWnd, iMessage, wParam, lParam));
}


bool cWindow::Init(HINSTANCE hInst)
{
	MSG msg;
	WNDCLASSEX wc;
	ZeroMemory(&wc, sizeof(WNDCLASSEX));
	wc.cbSize = sizeof(WNDCLASSEX);
	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.hInstance = hInst;
	wc.lpfnWndProc = WndProc;
	wc.lpszClassName = L"WINDOW";

	if (RegisterClassEx(&wc) == false)
	{
		return false;		
	}


	HWND hWnd = CreateWindowEx(WS_EX_APPWINDOW, L"WINDOW", L"MYNAME", WS_OVERLAPPEDWINDOW, 0,0,500,500, NULL, NULL, hInst, NULL);
	if (hWnd == NULL)
		return false;

	ShowWindow(hWnd, SW_SHOW);
	
	HBITMAP hBitmap = (HBITMAP)LoadImage(hInst, L"test.bmp", IMAGE_BITMAP, 0, 0, LR_DEFAULTSIZE | LR_LOADFROMFILE);

	
	HDC hdc = GetDC(hWnd);
	HDC hMemDC = CreateCompatibleDC(hdc);
	HBITMAP hOldBitmap = (HBITMAP)SelectObject(hMemDC, hBitmap);

	while (1)
	{
		if (PeekMessage(&msg, NULL, 0,0,PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);

			if (msg.message == WM_QUIT)
				break;
		}
		else
		{
			DWORD currentTick = timeGetTime();
			DWORD ElapseTick = currentTick - Tick;

			static DWORD Frame_100 = 0;
			Frame_100 += SecPerFrame;
			if (ElapseTick < 100 )
			{
				continue;
			}



			SecPerFrame = ElapseTick / 1000.0f;

			GameTime += SecPerFrame;
			static float Time = 0.0f;
			Time += SecPerFrame;

			if (Time >= 1.0f)
			{
				FPS = TempCount;
				Time -= 1.0f;
				TempCount = 0;
			}

			_stprintf_s(Buffer, L"%d : %10.4f : %10.4f", FPS, GameTime, SecPerFrame);

			TextOut(hdc, 0, 0, Buffer, wcslen(Buffer));


			for (int i = 0; i < 256; i++)
			{
				SHORT key = GetAsyncKeyState(i);
				KeyState[i] = (key & 0x8000) ? 1 : 0;

			}

			if (KeyState[VK_LBUTTON])
			{
				MessageBox(NULL, L"VK_LBUTTON", L"MOUSE", MB_OK);
			}

			if (KeyState[VK_LCONTROL] && KeyState[VK_LBUTTON] )
			{
				MessageBox(NULL, L"COMBO", L"MOUSE", MB_OK);
			}

			BitBlt(hdc, 0, 0, 800, 600, hMemDC, 0, 0, SRCCOPY);
			TempCount++;

			Tick = currentTick;
		}
	}

	SelectObject(hMemDC, hOldBitmap); // revert

	DeleteObject(hBitmap);
	ReleaseDC(hWnd, hMemDC);
	ReleaseDC(hWnd, hdc);


	return true;
}

cWindow::cWindow()
{
}


cWindow::~cWindow()
{
}
