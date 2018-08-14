#include "Scene.h"
#include "Input.h"

bool	SceneEnd::Init()
{
	nextSceneStart = false;

	backGround.Init();
	backGround.Set(g_rtClient.right / 2, g_rtClient.bottom / 2, 0, 0, 800, 600);
	backGround.Load( L"../../data/RAINBOW.bmp");

	btnStart.Init();
	btnStart.Set( g_rtClient.right / 2, g_rtClient.bottom / 2, 0, 0, 100, 50);
	btnStart.Load( L"../../data/end.bmp");


	return true;
};
bool	SceneEnd::Update()
{
	backGround.Update();
	//for (int inpc = 0; inpc < g_iMaxNpcCount; inpc++)
	{
		if (I_Input.Key(VK_LBUTTON) && Collision::RectInpt( btnStart.rtCollision, I_Input.mousePos))
		{
			DestroyWindow(g_hWnd);
		}
	}
	btnStart.Frame();
	return true;
};
bool	SceneEnd::Render()
{
	backGround.Render();
	btnStart.Render();
	return true;
};
bool	SceneEnd::Release()
{
	backGround.Release();
	btnStart.Release();
	return true;
};
SceneEnd::SceneEnd()
{
	sceneID = 10;
}
SceneEnd::~SceneEnd()
{}