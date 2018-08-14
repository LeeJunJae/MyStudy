#include "Timer.h"
float g_fSecPerFrame = 0.0f;
bool	Timer::Init()
{
	//__imp_timeGetTime 외부 기호 : winmm.lib
	BeforeTick = timeGetTime(); // 1/1000
	return true;
}
bool	Timer::Frame()
{
	DWORD dwCurrentTick = timeGetTime();
	DWORD dwElapseTick = dwCurrentTick - BeforeTick;
	SecPerFrame = dwElapseTick / 1000.0f;
	g_fSecPerFrame = SecPerFrame;
	GameTimer += SecPerFrame;

	timer += SecPerFrame;
	if (timer >= 1.0f)
	{
		FPS = FrameCount;
		FrameCount = 0;
		timer -= 1.0f;
		_stprintf_s(Buffer, 
			L"FPS:%d TIME:%10.4f SPF:%10.4f", 
			FPS, GameTimer, SecPerFrame);
		//OutputDebugString(m_csBuffer);
	}
	FrameCount++;

	BeforeTick = dwCurrentTick;
	return true;
}
bool	Timer::Render()
{
	SetBkColor(g_hOffScreenDC, RGB(255, 0, 0));
	SetTextColor(g_hOffScreenDC, RGB(0, 0, 255));
	//SetBkMode(g_hOffScreenDC, TRANSPARENT);
	TextOut(g_hOffScreenDC, 0,0, Buffer, wcslen(Buffer));
	return true;
}
bool	Timer::Release()
{
	return true;
}

Timer::Timer()
{
	GameTimer = 0.0f;
	FrameCount = 0;
	FPS = 0;
	BeforeTick = 0;
	SecPerFrame = 0.0f;
	GameTimer = 0.0f;
	timer = 0.0f;
}


Timer::~Timer()
{
}
