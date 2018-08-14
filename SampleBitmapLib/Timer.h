#pragma once
#include "Std.h"
/*
 1) 1�������� ��� �ð�=m_fSecPerFrame
 2) 1���� ������ ī����
 3) ������ ����� �����ð�
*/
class Timer
{
	DWORD FrameCount;
	DWORD FPS;
	DWORD BeforeTick;
	float SecPerFrame;
	float GameTimer;
	float timer;
	TCHAR Buffer[256];
public:
	bool	Init();		// �ʱ�ȭ
	bool	Frame();	// ���
	bool	Render();	// ��ο�
	bool	Release();	// �Ҹ�, ����
public:
	Timer();
	virtual ~Timer();
};

