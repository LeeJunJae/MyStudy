#pragma once
#include "Std.h"

/*

1) 1프레임의 경과 시간=m_fSecPerFrame

2) 1초의 프레임 카운터

3) 게임이 실행된 누적시간

*/

class Timer
{

	DWORD dwFrameCount;
	DWORD dwFPS;
	DWORD dwBeforeTick;
	float secPerFrame;
	float gameTimer;
	float timer;
	TCHAR Buffer[256];

public:

	bool	Init();		// 초기화
	bool	Update();	// 계산
	bool	Render();	// 드로우
	bool	Release();	// 소멸, 삭제

public:

	Timer();
	virtual ~Timer();

};