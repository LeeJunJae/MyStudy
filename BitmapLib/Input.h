#pragma once
#include "Std.h"
enum KeyState
{
	KEY_FREE = 0,
	KEY_PUSH,
	KEY_UP,
	KEY_HOLD,
};
class Input : public TSingleton<Input>
{
	friend class TSingleton<Input>;
	DWORD	KeyCheck(DWORD dwKey);
	DWORD  dwKeyState[256];
	DWORD  dwBeforeMouseState[3];
public:
	DWORD  dwMouseState[3];	
	POINT  mousePos;
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
