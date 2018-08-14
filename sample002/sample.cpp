#include "Core.h"
#include "Bitmap.h"



struct Point
{
	float x, y;
};
class Sample : public Core
{
	Bitmap  m_bitmap;
	Point   m_pos;
public:
	bool Init()
	{
		m_pos.x = 100;
		m_pos.y = 100;
		m_bitmap.Load(L"../../data/test.bmp");
		return true;
	}
	bool Update()
	{
		if (I_Input.Key('W'))
		{
			m_pos.y += -1 * g_fSecPerFrame*300.0f;
		}
		if (I_Input.Key('S'))
		{
			m_pos.y += 1 * g_fSecPerFrame*300.0f;
		}
		if (I_Input.Key('A'))
		{
			m_pos.x += -1 * g_fSecPerFrame*300.0f;
		}
		if (I_Input.Key('D'))
		{
			m_pos.x += 1 * g_fSecPerFrame*300.0f;
		}
		return true;
	}
	bool Render()
	{
		BitBlt(hOffScreenDC, m_pos.x, m_pos.y, 800, 600, m_bitmap.hMemDC, 0, 0, SRCCOPY);
		return true;
	}
	bool Release()
	{
		return true;
	}
public:
	Sample() {}
	~Sample() {}
};
GAME_RUN("SampleInput", 800, 600)