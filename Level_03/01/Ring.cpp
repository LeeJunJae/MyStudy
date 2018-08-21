#include "Ring.h"



void Ring::InitMember(int InCircleY, int InCircleX, int inRadius, int outCircleY, int outCircleX, int outRadius)
{
	POINT inPoint;
	inPoint.InitMembers(InCircleY, InCircleX);
	this->inCircle.InitMember(inPoint, inRadius);

	POINT outPoint;
	outPoint.InitMembers(outCircleY, outCircleX);
	this->outCircle.InitMember(outPoint, outRadius);
}

void Ring::PrintInfo()
{
	this->inCircle.PrintCircle();
	this->outCircle.PrintCircle();
}

Ring::Ring(int InCircleY, int InCircleX, int inRadius, int outCircleY, int outCircleX, int outRadius)
{
	POINT inPoint;
	inPoint.InitMembers(InCircleY, InCircleX);
	this->inCircle.InitMember(inPoint, inRadius);

	POINT outPoint;
	outPoint.InitMembers(outCircleY, outCircleX);
	this->outCircle.InitMember(outPoint, outRadius);
}


Ring::~Ring()
{
}
