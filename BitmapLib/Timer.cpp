#include "Timer.h"

float g_fSecPerFrame = 0.0f;


bool	Timer::Init()
{
	//__imp_timeGetTime 외부 기호 : winmm.lib
	beforeTick = timeGetTime(); // 1/1000
	return true;
}


bool	Timer::Update()
{
	DWORD dwCurrentTick = timeGetTime();
	DWORD dwElapseTick  = dwCurrentTick - beforeTick;
	secPerFrame    = dwElapseTick / 1000.0f;
	g_fSecPerFrame = secPerFrame;
	gameTimer     += secPerFrame;

	timer += secPerFrame;
	
	if (timer >= 1.0f)
	{
		FPS = frameCount;
		frameCount = 0;
		timer -= 1.0f;
		_stprintf_s(Buffer, 
			L"FPS:%d TIME:%10.4f SPF:%10.4f", 
			FPS, gameTimer, secPerFrame);
		//OutputDebugString(m_csBuffer);
	}
	frameCount++;

	beforeTick = dwCurrentTick;

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
	gameTimer   = 0.0f;
	frameCount  = 0;
	FPS         = 0;
	beforeTick  = 0;
	secPerFrame = 0.0f;
	gameTimer   = 0.0f;
	timer       = 0.0f;
}


Timer::~Timer()
{

}
