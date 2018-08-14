#pragma once
#include "backObject.h"
#include "NPCObject.h"
#include "Button.h"

const int g_iMaxLevel = 10;
const int g_MaxNpcCount = 100;

class Scene
{
public:
	int sceneID;
	backObject backGround;
	bool nextSceneStart;
	int maxNpcCount;

public:
	virtual bool Init() { return true; };
	virtual bool Update() { return true; };
	virtual bool Render() { return true; };
	virtual bool Release() { return true; };
	virtual bool ReSet() { return true; };
	virtual bool IsDead() { return true; };

public:
	Scene()
	{
		nextSceneStart = false;
		maxNpcCount = 10;
	};

	virtual ~Scene() {};
};

class SceneLobby : public Scene
{
public:
	Button btnStart;

public:
	bool	Init();
	bool	Update();
	bool	Render();
	bool	Release();
	bool    Reset() { return true; };
	bool	IsDead() { return btnStart.dead; };
public:
	SceneLobby();
	virtual ~SceneLobby();
};

class SceneEnd : public Scene
{
public:
	Button btnStart;

public:
	bool	Init();
	bool	Update();
	bool	Render();
	bool	Release();
	bool    Reset() { return true; };
	bool	IsDead() { return btnStart.dead; };
public:
	SceneEnd();
	virtual ~SceneEnd();
};

class SceneGame : public Scene
{
public:
	Object Hero;
	std::vector<NPCObject> npcList;

public:
	bool	Init();
	bool	Update();
	bool	Render();
	bool	Release();
	bool    Reset();
public:
	SceneGame();
	virtual ~SceneGame();
};