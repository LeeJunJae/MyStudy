#pragma once
#include "Window.h"
#include "Timer.h"

class Core : public Window

{

	Timer  timer;

public:

	bool	GameInit();

	bool	GameRun();

	bool	GameRelease();

public:

	Core();

	virtual ~Core();

};