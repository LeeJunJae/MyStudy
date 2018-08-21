#include "Circle.h"



void Circle::InitMember(POINT& point, int radius)
{
	this->point = point;
	this->radius = radius;
}

void Circle::PrintCircle()
{
	this->point.PrintPoint();
	cout << "radius : " << this->radius << endl;
}

Circle::Circle()
{
}


Circle::~Circle()
{
}
