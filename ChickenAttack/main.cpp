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

	std::vector<NPCObject> LNpcArr;
	std::vector<NPCObject> RNpcArr;

public:
	bool Init()
	{
		posDraw.x = 0;
		posDraw.y = 0;
		bitmap.Load(L"lastBG.bmp");

		hero.Set(500, 500, 0, 0, 120, 130);
		hero.Load(L"charLink.bmp", L"LinkMask.bmp");

		LNpcArr.resize(maxNpcCnt);
		RNpcArr.resize(maxNpcCnt);
		for (int obj = 0; obj < maxNpcCnt; obj++)
		{
			
			LNpcArr[obj].Set( 100 , 100 + rand() % 1000, 0, 0, 80, 96);
			LNpcArr[obj].Load(L"80ChickenSample110.bmp", L"80ChickenSampleMask110.bmp");
			//lNpcArr[obj].pos.x *= 1.0f;
		}
		
		for (int obj = 0; obj < maxNpcCnt; obj++)
		{
			RNpcArr[obj].Set(1000, 100 + rand() % 1000, 0, 0, 80, 96); //1380
			RNpcArr[obj].Load(L"80ChickenSample110.bmp", L"80ChickenSampleMask110.bmp");
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
	

		LNpcArr.resize(maxNpcCnt);
		RNpcArr.resize(maxNpcCnt);

		int time = 1;
		if ((g_fSecPerFrame / 10) == time)
		{
			if (hero.dead == false)
			{
				for (int obj = 0; obj < maxNpcCnt; obj++)
				{
					LNpcArr[obj].Set(100, 100 + rand() % 1000, 0, 0, 80, 96);
					LNpcArr[obj].Load(L"80ChickenSample110.bmp", L"80ChickenSampleMask110.bmp");
					LNpcArr[obj].pos.x *= 1.0f;
				}

				for (int obj = 0; obj < maxNpcCnt; obj++)
				{
					RNpcArr[obj].Set(1000, 100 + rand() % 1000, 0, 0, 80, 96); //1380
					RNpcArr[obj].Load(L"80ChickenSample110.bmp", L"80ChickenSampleMask110.bmp");
					RNpcArr[obj].fdir = -1.0f;
				}
			}
		}

		//for (int inpc = 0; inpc < maxNpcCnt; inpc++)
		//{
		//	if (!LNpcArr[inpc].dead)
		//	{
		//		LNpcArr[inpc].Update();

		//		if (LNpcArr[inpc].pos.x > 1480)
		//		{
		//			for (int inpc = 0; inpc < maxNpcCnt; inpc++)
		//			{
		//				if (!LNpcArr[inpc].dead)
		//				{
		//					LNpcArr[inpc].Release();
		//				}
		//			}
		//		}
		//	}
		//}

		for (int inpc = 0; inpc < maxNpcCnt; inpc++)
		{
			if (!RNpcArr[inpc].dead)
			{
				RNpcArr[inpc].Update();
			}
		}

		for (int inpc = 0; inpc < maxNpcCnt; inpc++)
		{
			if (Collision::SphereInSphere( LNpcArr[inpc].rtCollision, hero.rtCollision))
			{
				LNpcArr[inpc].dead = true;
			}
		}


	
		RNpcArr.clear();
		LNpcArr.clear();



		time++;





		return true;
	}

	bool Render()
	{
		BitBlt(hOffScreenDC, posDraw.x, posDraw.y, 1280, 960, bitmap.hMemDC, 0, 0, SRCCOPY);

		hero.Render();

		for (int inpc = 0; inpc < maxNpcCnt; inpc++)
		{
			if (!LNpcArr[inpc].dead)
			{
				LNpcArr[inpc].Render();
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
			if (!LNpcArr[inpc].dead)
			{
				LNpcArr[inpc].Release();
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