#pragma once
#include "POINT.h"

class Circle
{
private:
	POINT point;
	int radius;

public:
	void InitMember(POINT& point, int radius);
	void PrintCircle();

public:
	Circle();
	~Circle();
};

