#pragma once
#include "Window.h"
#include "Timer.h"

class Core : public Window
{
public:
	Timer   Timer;
	HDC     hScreenDC;
	HDC     hOffScreenDC;
	HBITMAP hOffScreenBitmap;
	HBRUSH  hbrBack;
public:
	bool	GameInit();
	bool	GameRun();
	bool	GameRelease();
	bool	GameFrame();
	bool	GameRender();
	bool	GamePreRender();
	bool	GamePostRender();
public:
	virtual bool	Init(){return true;}
	virtual bool	Frame(){return true;}
	virtual bool	Render(){return true;}
	virtual bool	Release(){return true;}
public:
	Core();
	virtual ~Core();
};

