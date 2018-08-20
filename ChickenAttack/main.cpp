//#include "Window.h"
#include "Core.h"
#include "Bitmap.h"

struct Point
{
	float x, y;
};
class Sample : public Core
{
	Bitmap  bitmap;
	Point  posDraw;


public:
	bool Init()
	{
		posDraw.x = 0;
		posDraw.y = 0;
		bitmap.Load(L"BGImage.bmp");
		return true;
	}

	bool Update()
	{
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
		BitBlt(hOffScreenDC, posDraw.x, posDraw.y, 800, 600, bitmap.hMemDC, 0, 0, SRCCOPY);
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
	win.SetWindow(hInst, L"CHICKENATTACK", 655, 518);
	win.Run();
}