//#include "Window.h"
#include "Core.h"
#include "Bitmap.h"
#include "Object.h"
#include "NPCObject.h"

const int maxNpcCnt = 10;

class Sample : public Core
{
	Bitmap  bitmap;
	Point  posDraw;

	///////////////
	Object hero;

	std::vector<NPCObject> lNpcArr;
	std::vector<NPCObject> RNpcArr;

public:
	bool Init()
	{
		posDraw.x = 0;
		posDraw.y = 0;
		bitmap.Load(L"lastBG.bmp");

		hero.Set(500, 500, 0, 0, 120, 130);
		hero.Load(L"charLink.bmp", L"LinkMask.bmp");

		lNpcArr.resize(maxNpcCnt);
		RNpcArr.resize(maxNpcCnt);


		for (int obj = 0; obj < maxNpcCnt; obj++)
		{
			
			lNpcArr[obj].Set( 100 , 100 + rand() % 1000, 0, 0, 54, 65);
			lNpcArr[obj].Load(L"ChickenSample.bmp", L"ChickenSampleMask.bmp");
			//lNpcArr[obj].pos.x *= 1.0f;
		}
		
		for (int obj = 0; obj < maxNpcCnt; obj++)
		{
			RNpcArr[obj].Set(1000, 100 + rand() % 1000, 0, 0, 54, 65); //1380
			RNpcArr[obj].Load(L"ChickenSample.bmp", L"ChickenSampleMask.bmp");
			RNpcArr[obj].fdir = -1.0f;
		}


		return true;
	}

	bool Update()
	{
		if (I_Input.Key('0') == KEY_PUSH)
		{
			hero.debugRect = !hero.debugRect;
			
		}

		hero.Update();
	

		for (int inpc = 0; inpc < maxNpcCnt; inpc++)
		{
			if (!lNpcArr[inpc].dead)
			{
				lNpcArr[inpc].Update();
			}
		}

		for (int inpc = 0; inpc < maxNpcCnt; inpc++)
		{
			if (!RNpcArr[inpc].dead)
			{
				RNpcArr[inpc].Update();
			}
		}

		for (int inpc = 0; inpc < maxNpcCnt; inpc++)
		{
			if (Collision::SphereInSphere( lNpcArr[inpc].rtCollision, hero.rtCollision))
			{
				lNpcArr[inpc].dead = true;
			}
		}

		return true;
	}

	bool Render()
	{
		BitBlt(hOffScreenDC, posDraw.x, posDraw.y, 1280, 960, bitmap.hMemDC, 0, 0, SRCCOPY);

		hero.Render();

		for (int inpc = 0; inpc < maxNpcCnt; inpc++)
		{
			if (!lNpcArr[inpc].dead)
			{
				lNpcArr[inpc].Render();
			}
		}

		for (int inpc = 0; inpc < maxNpcCnt; inpc++)
		{
			if (!RNpcArr[inpc].dead)
			{
				RNpcArr[inpc].Render();
			}
		}

		return true;
	}

	bool Release()
	{
		bitmap.Release();
		hero.Release();
		for (int inpc = 0; inpc < maxNpcCnt; inpc++)
		{
			if (!lNpcArr[inpc].dead)
			{
				lNpcArr[inpc].Release();
			}
		}

		for (int inpc = 0; inpc < maxNpcCnt; inpc++)
		{
			if (!RNpcArr[inpc].dead)
			{
				RNpcArr[inpc].Release();
			}
		}
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