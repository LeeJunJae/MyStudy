#pragma once
#include "Std.h"

enum KeyState
{
	KEY_FREE = 0,
	KEY_PUSH,
	KEY_UP,
	KEY_HOLD,
};
class Input : public Singleton<Input>
{
	friend class Singleton<Input>;
	DWORD	KeyCheck(DWORD dwKey);
	DWORD   m_dwKeyState[256];
	DWORD   m_dwBeforeMouseState[3];
public:
	DWORD   m_dwMouseState[3];
	POINT   m_MousePos;
public:
	DWORD   Key(DWORD dwKey);
	void	MsgEvent(MSG msg);
	bool	Init();		// 초기화
	bool	Update();	// 계산
	bool	Render();	// 드로우
	bool	Release();	// 소멸, 삭제
protected:
	Input();
	virtual ~Input();
};

#define I_Input Input::GetInstance()
