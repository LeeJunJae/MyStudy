#include "Core.h"
//#include "Object.h"
#include "Scene.h"

class Sample : public Core
{
	std::shared_ptr<Scene> pGameScene;
	std::shared_ptr<Scene> pLobbyScene;
	std::shared_ptr<Scene> pEndScene;

	Scene* pCurrentScene;
	int level;

public:
	bool	Init()
	{
		level = 1;
		pGameScene = std::make_shared<SceneGame>();
		pEndScene = std::make_shared<SceneEnd>();
		pLobbyScene = std::make_shared<SceneLobby>();
		pCurrentScene = pLobbyScene.get();

		pGameScene->Init();
		pLobbyScene->Init();
		pEndScene->Init();

		return true;
	}
	bool	Update()
	{
		switch (pCurrentScene->sceneID)
		{
		case 0:
		{
			if (pCurrentScene->nextSceneStart == true)
			{
				pCurrentScene->nextSceneStart = false;
				pCurrentScene = pGameScene.get();
			}
		}break;
		case 1:
		{
			if (pCurrentScene->nextSceneStart == true)
			{
				if (++level > 2)
				{
					pCurrentScene = pEndScene.get();
					pCurrentScene->maxNpcCount= 10;
					pCurrentScene->ReSet();
					level = 0;
				}
				else
				{
					pCurrentScene = pGameScene.get();
					pCurrentScene->maxNpcCount = level * 10;
					pCurrentScene->ReSet();
				}
			}
		}
		}
		pCurrentScene->Update();
		return true;
	}
	bool	Render() {

		pCurrentScene->Render();
		return true;
	}
	bool	Release() {
		pGameScene->Release();
		pLobbyScene->Release();
		pEndScene->Release();
		return true;
	}
public:
	Sample() {}
	virtual ~Sample() {}

};


GAME_RUN("SampleInput", 800, 600)