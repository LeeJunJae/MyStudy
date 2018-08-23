#pragma once
#include "NPCObject.h"
#include "GameTimer.h"

class CockMgr 
{
public:
	
	std::vector<NPCObject*> npcList;

	float currentTime;
	float startTime;  


	

	//DWORD frameCount;
	//DWORD FPS;
	//DWORD beforeTick;
	//float secPerFrame;
	//float gameTimer;
	//float timer;
	//TCHAR buffer[256];


public:

	bool Init();
	bool Update();
	bool Render();
	bool Release();


	bool CreateCock();


public:
	CockMgr();
	~CockMgr();
};

