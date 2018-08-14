#include "Scene.h"
#include "Input.h"


bool	SceneLobby::Init()
{
	nextSceneStart = false;

	backGround.Init();
	backGround.Set(g_rtClient.right / 2,
		g_rtClient.bottom / 2, 0, 0, 800, 600);
	backGround.Load(
		L"../../data/bk.bmp");

	btnStart.Init();
	btnStart.Set(
		g_rtClient.right / 2,
		g_rtClient.bottom / 2,
		0, 0, 334, 82);
	btnStart.Load(
		L"../../data/main_start_nor.bmp");


	return true;
};
bool	SceneLobby::Update()
{
	backGround.Update();
	//for (int inpc = 0; inpc < g_iMaxNpcCount; inpc++)
	{
		if (I_Input.Key(VK_LBUTTON) && Collision::RectInpt( btnStart.rtCollision, I_Input.mousePos))
		{
			nextSceneStart = true;
		}
	}
	btnStart.Update();
	return true;
};
bool	SceneLobby::Render()
{
	backGround.Render();
	btnStart.Render();
	return true;
};
bool	SceneLobby::Release()
{
	backGround.Release();
	btnStart.Release();
	return true;
};
SceneLobby::SceneLobby()
{
	sceneID = 0;
}
SceneLobby::~SceneLobby()
{}