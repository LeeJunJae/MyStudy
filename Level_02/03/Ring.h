#pragma once
#include "Circle.h"

class Ring
{
private:
	Circle inCircle;
	Circle outCircle;

public :
	void InitMember(int InCircleY, int InCircleX, int inRadius, int outCircleY, int outCircleX, int outRadius);
	void PrintInfo();

public:
	Ring();
	~Ring();
};

