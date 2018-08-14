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
	bool	Init();		// �ʱ�ȭ
	bool	Update();	// ���
	bool	Render();	// ��ο�
	bool	Release();	// �Ҹ�, ����
protected:
	Input();
	virtual ~Input();
};
#define I_Input Input::GetInstance()
