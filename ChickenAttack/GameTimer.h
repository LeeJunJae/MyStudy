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
	bool	Init();		// �ʱ�ȭ
	bool	Update();	// ���
	bool	Render();	// ��ο�
	bool	Release();	// �Ҹ�, ����

public:
	GameTimer();
	~GameTimer();
};

