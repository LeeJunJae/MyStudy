#include "Scene.h"
#include "Input.h"


bool    SceneGame::Reset()
{
	nextSceneStart = false;
	for (int iObj = 0; iObj < g_MaxNpcCount; iObj++)
	{
		npcList[iObj].dead = false;
		npcList[iObj].Set(100 + rand() % 600, 100 + rand() % 400, 46, 62, 68, 79);
	}
	return true;
}



bool SceneGame::Init()
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
bool SceneGame::Update()
{
	if (I_Input.Key('0') == KEY_PUSH)
	{
		Hero.debugRect = !Hero.debugRect;
		for (int iObj = 0; iObj < g_MaxNpcCount; iObj++)
		{
			npcList[iObj].debugRect = !npcList[iObj].debugRect;
		}
	}

	backGround.Update();
	Hero.Update();
	for (int inpc = 0; inpc < g_MaxNpcCount; inpc++)
	{
		if (!npcList[inpc].dead)
		{
			npcList[inpc].Update();
		}
	}
	for (int inpc = 0; inpc < g_MaxNpcCount; inpc++)
	{
		if (Collision::SphereInSpher(npcList[inpc].rtCollision, Hero.rtCollision))
		{
			npcList[inpc].dead = true;
		}
	}
	bool bChangeScene = true;
	for (int inpc = 0; inpc < g_MaxNpcCount; inpc++)
	{
		if (I_Input.Key(VK_LBUTTON) && Collision::SphereInPt(npcList[inpc].rtCollision, I_Input.mousePos))
		{
			npcList[inpc].dead = true;
		}
		if (npcList[inpc].dead == false)
		{
			bChangeScene = false;
		}
	}
	/*if (bChangeScene == true)
	{
	NextSceneStart = true;
	}*/

	return true;
}
bool SceneGame::Render()
{
	backGround.Render();
	Hero.Render();
	for (int iObj = 0; iObj < npcList.size(); iObj++)
	{
		if (!npcList[iObj].dead)
		{
			npcList[iObj].Render();
		}
	}

	return true;
}
bool SceneGame::Release()
{
	backGround.Release();
	Hero.Release();
	for (int iObj = 0; iObj < npcList.size(); iObj++)
	{
		if (!npcList[iObj].dead)
		{
			npcList[iObj].Render();
		}
	}



	return true;
}

SceneGame::SceneGame()
{
	sceneID = 1;
}
SceneGame::~SceneGame()
{
}
