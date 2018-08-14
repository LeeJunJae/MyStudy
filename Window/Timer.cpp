#include "Timer.h"



bool Timer::Init()
{
	//__imp_timeGetTime ¿ÜºÎ ±âÈ£ : winmm.lib
	dwBeforeTick = timeGetTime(); // 1/1000
	return true;
}

bool Timer::Update()
{
	DWORD dwCurrentTick = timeGetTime();
	DWORD dwElapseTick = dwCurrentTick - dwBeforeTick;
	secPerFrame = dwElapseTick / 1000.0f;
	gameTimer += secPerFrame;
	timer += secPerFrame;

	if (timer >= 1.0f)
	{
		dwFPS = dwFrameCount;
		dwFrameCount = 0;
		timer -= 1.0f;
		_stprintf_s(Buffer,	L"FPS:%d TIME:%10.4f SPF:%10.4f",dwFPS, gameTimer, secPerFrame);

		//OutputDebugString(m_csBuffer);

	}
	dwFrameCount++;
	dwBeforeTick = dwCurrentTick;

	return true;
}

bool	Timer::Render()

{

	HDC hdc = GetDC(g_hWnd);

	TextOut(hdc, 0, 0, Buffer, wcslen(Buffer));

	ReleaseDC(g_hWnd, hdc);

	return true;

}

bool	Timer::Release()

{

	return true;

}



Timer::Timer()

{

	gameTimer = 0.0f;

	dwFrameCount = 0;

	dwFPS = 0;

	dwBeforeTick = 0;

	secPerFrame = 0.0f;

	gameTimer = 0.0f;

	timer = 0.0f;

}





Timer::~Timer()

{

}