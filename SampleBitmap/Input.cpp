#include "Input.h"

DWORD Input::KeyCheck(DWORD dwKey)
{
	// GetKeyState() // 동기적
	// GetAsyncKeyState()//비동기적
	SHORT sKey = GetAsyncKeyState(dwKey);	
	// 0x8000 : 이전X ~ 지금O
	// 0x8001 : 이전O ~ 지금O
	// 0x0000 : 이전X ~ 지금X
	// 0x0001 : 이전O ~ 지금X
	if (sKey & 0x8000)
	{
		if (dwKeyState[dwKey] == KEY_FREE ||
			dwKeyState[dwKey] == KEY_UP)
		{
			dwKeyState[dwKey] = KEY_PUSH;
		}
		else
		{
			dwKeyState[dwKey] = KEY_HOLD;
		}
	}
	else
	{
		if(dwKeyState[dwKey] == KEY_PUSH ||
			dwKeyState[dwKey] == KEY_HOLD)
		{
			dwKeyState[dwKey] = KEY_UP;
		}
		else
		{
			dwKeyState[dwKey] = KEY_FREE;
		}
	}
	return dwKeyState[dwKey];
}

bool	Input::Init() 
{	
	ZeroMemory(m_dwKeyState, sizeof(DWORD) * 256);
	ZeroMemory(dwMouseState, sizeof(DWORD) * 3);
	ZeroMemory(dwBeforeMouseState, sizeof(DWORD) * 3);
	return true;
}
bool	Input::Update() 
{
	GetCursorPos(&mousePos); //  화면좌표
	ScreenToClient(g_hWnd, &mousePos);
	
	for (int iKey = 0; iKey < 255; iKey++)
	{
		dwKeyState[iKey] = KeyCheck(iKey);
	}
	for (int iButton = 0; iButton < 3; iButton++)
	{
		if (dwBeforeMouseState[iButton] == KEY_PUSH)
		{
			if (dwMouseState[iButton] == KEY_PUSH)
			{
				dwMouseState[iButton] = KEY_HOLD;
			}
		}
		if (dwBeforeMouseState[iButton] == KEY_UP)
		{
			if (dwMouseState[iButton] == KEY_UP)
			{
				dwMouseState[iButton] = KEY_FREE;
			}
		}
		dwBeforeMouseState[iButton] = dwMouseState[iButton];
	}
	return true;
}
bool	Input::Render() {
	
	return true;
}
DWORD   Input::Key(DWORD dwKey)
{
	return m_dwKeyState[dwKey];
}
bool	Input::Release() {
	return true;
}
void	Input::MsgEvent(MSG msg)
{	
	switch (msg.message)
	{
	case WM_LBUTTONDOWN:
	{
		dwMouseState[0] = KEY_PUSH;
	}break;
	case WM_LBUTTONUP:
	{
		dwMouseState[0] = KEY_UP;
	}break;
	case WM_RBUTTONDOWN:
	{
		dwMouseState[1] = KEY_PUSH;
	}break;
	case WM_RBUTTONUP:
	{
		dwMouseState[1] = KEY_UP;
	}break;
	case WM_MBUTTONDOWN:
	{
		dwMouseState[2] = KEY_PUSH;
	}break;
	case WM_MBUTTONUP:
	{
		dwMouseState[2] = KEY_UP;
	}break;
	}
}
Input::Input()
{
}


Input::~Input()
{
}
