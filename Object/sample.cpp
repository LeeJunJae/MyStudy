#include "Core.h"
#include "BgObject.h"
#include "NPCObject.h"

#include <vector>
using namespace std;
#define g_MaxNpcCount 10

class Sample : public Core
{
	backObject backGround;
	Object Hero;
	vector<NPCObject> npcList;

public:
	bool Init()
	{
		npcList.resize(g_MaxNpcCount);
		backGround.Init();
		backGround.Set(0, 0, 0, 0, 800, 600);
		backGround.Load(L"../../data/bk.bmp");

		//Hero.Init();
		Hero.Set(300, 300, 90, 2, 42, 58);
		Hero.Load(L"../../data/bitmap1.bmp", L"../../data/bitmap2.bmp");

		//npc.Init();
		for (int iObj = 0; iObj < npcList.size(); iObj++)
		{
			npcList[iObj].Set(rand() % 800, rand() % 600, 46, 62, 68, 79);
			npcList[iObj].Load(L"../../data/bitmap1.bmp", L"../../data/bitmap2.bmp");
		}
		return true;
	}
	bool Update()
	{
		if (I_Input.Key('0') == KEY_PUSH)
		{
			Hero.debugRect = !Hero.debugRect;
			for (int i = 0; i < npcList.size(); i++)
			{
				npcList[i].debugRect = !npcList[i].debugRect;
			}
		}

		backGround.Update();
		Hero.Update();
		for (int iObj = 0; iObj < npcList.size(); iObj++)
		{
			npcList[iObj].Update();
		}

		for (int inpc = 0; inpc < g_MaxNpcCount; inpc++)
		{
			if (Collision::RectInRect(npcList[inpc].rtDraw, Hero.rtDraw))
			{
				npcList[inpc].dead = true;
			}
		}


		return true;
	}
	bool Render()
	{
		backGround.Render();
		Hero.Render();
		for (int iObj = 0; iObj < npcList.size(); iObj++)
		{
			if(!npcList[iObj].dead )
			npcList[iObj].Render();
		}

		return true;
	}
	bool Release()
	{
		backGround.Release();
		Hero.Release();
		for (int iObj = 0; iObj < npcList.size(); iObj++)
		{
			npcList[iObj].Release();
		}



		return true;
	}
public:
	Sample() {}
	~Sample() {}
};
GAME_RUN("SampleInput", 800, 600)