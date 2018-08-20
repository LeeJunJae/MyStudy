//#include "Window.h"
#include "Core.h"
#include "Bitmap.h"
#include "Object.h"


class Sample : public Core
{
	Bitmap  bitmap;
	Point  posDraw;

	///////////////
	Object hero;

public:
	bool Init()
	{
		posDraw.x = 0;
		posDraw.y = 0;
		bitmap.Load(L"lastBG.bmp");

		hero.Set(300, 300, 0, 0, 120, 130);
		hero.Load(L"charLink.bmp", L"LinkMask.bmp");

		return true;
	}

	bool Update()
	{
		if (I_Input.Key('0') == KEY_PUSH)
		{
			hero.debugRect = !hero.debugRect;
			
		}

		hero.Update();
	/*	if (I_Input.Key('W'))
		{
			posDraw.y += -1 * 300.0f;
		}
		if (I_Input.Key('S'))
		{
			posDraw.y += 1 * 300.0f;
		}
		if (I_Input.Key('A'))
		{
			posDraw.x += -1 * 300.0f;
		}
		if (I_Input.Key('D'))
		{
			posDraw.x += 1 * 300.0f;
		}*/

		return true;
	}

	bool Render()
	{
		BitBlt(hOffScreenDC, posDraw.x, posDraw.y, 1280, 960, bitmap.hMemDC, 0, 0, SRCCOPY);

		hero.Render();


		return true;
	}

	bool Release()
	{

		return true;
	}

public:
	Sample() {};
	~Sample() {};
};



int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevIst, LPSTR lpCmdLine, int nCmdShow)
{
	Sample win;
	win.SetWindow(hInst, L"CHICKENATTACK", 1280, 960); //655, 518
	win.Run();
}