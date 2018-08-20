#pragma once
#include "Std.h"


class GameTimer
{
	DWORD frameCount;
	DWORD FPS;
	DWORD beforeTick;
	float secPerFrame;
	float gameTimer;
	float timer;
	TCHAR buffer[256];

public:
	bool	Init();		// 초기화
	bool	Update();	// 계산
	bool	Render();	// 드로우
	bool	Release();	// 소멸, 삭제

public:
	GameTimer();
	~GameTimer();
};

