#pragma once
#include <Windows.h>
#include "Std.h"

class Window
{
public:
	HWND      hWnd;
	HINSTANCE hInstance;
	RECT	  client;
	RECT      window;

private:
	DWORD Style;

public:
	void Set(DWORD style);
	void CenterWindow();

	bool SetWindow(HINSTANCE hInstance, const TCHAR* titleName = L"SAMPLE", UINT width = 800, UINT height = 600);
	bool Run();

public:
	virtual LRESULT MsgProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lPram);
	virtual bool    GameInit();
	virtual bool	GameRun();
	virtual bool	GameRelease();

	void MsgEvent(MSG msg);

public:
	Window();
	~Window();
};

