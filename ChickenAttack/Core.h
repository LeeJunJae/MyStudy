#pragma once
#include "Window.h"
#include "Input.h"
#include "GameTimer.h"
#include "Std.h"



class Core : public Window
{
public:
	HDC     hScreenDC;
	HDC     hOffScreenDC;
	HBITMAP hOffScreenBitmap;
	HBRUSH  hbrBack;

	GameTimer timer;

public:
	bool	GameInit();
	bool	GameRun();
	bool	GameRelease();
	bool	GameUpdate();
	bool	GameRender();
	bool	GamePreRender();
	bool	GamePostRender();

public:
	virtual bool	Init() { return true; }
	virtual bool	Update() { return true; }
	virtual bool	Render() { return true; }
	virtual bool	Release() { return true; }

public:
	Core();
	virtual ~Core();
};

