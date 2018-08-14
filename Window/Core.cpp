#include "Core.h"

bool Core::GameInit()
{
	timer.Init();
	return true;
}

bool	Core::GameRun()
{
	timer.Update();
	timer.Render();
	return true;
}

bool	Core::GameRelease()
{
	timer.Release();
	return true;
}

Core::Core()
{

}

Core::~Core()

{

}