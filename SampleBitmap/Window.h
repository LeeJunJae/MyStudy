#pragma once
#include "Std.h"
#include "Input.h"

class Window
{
public:
	HWND		hWnd;
	HINSTANCE	hInstance;
	RECT		m_rtClient;
	RECT		rtWindow;
private:
	DWORD		dwStyle;
public:
	void		Set(DWORD dwStyle);
	void		CenterWindow();
		bool		SetWindow(HINSTANCE	hInstance,
		const TCHAR* pTitleName = L"KGCA Sample",
		UINT iWidth=800, UINT iHeight=600);
	bool		Run();
public:
	virtual LRESULT	MsgProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
	virtual bool	GameInit();
	virtual bool	GameRun();
	virtual bool	GameRelease();
	void MsgEvent(MSG msg);
public:
	Window();
	virtual ~Window();
};

