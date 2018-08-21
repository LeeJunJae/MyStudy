#include "RECTANGLE.h"



void RECTANGLE::InitMembers(const POINT & upLeft, const POINT & downRight)
{
	this->upLeft = upLeft;
	this->downRight = downRight;
}

void RECTANGLE::ShowRectInfo()
{
	cout << "( y:" << upLeft.GetY() << "x :" << upLeft.GetX() << ")"  << endl;
	cout << "( y:" << downRight.GetY() << "x :" << downRight.GetX() << ")" << endl;
}

RECTANGLE::RECTANGLE(const POINT & upLeft, const POINT & downRight)
{
	this->upLeft = upLeft;
	this->downRight = downRight;
}


RECTANGLE::~RECTANGLE()
{
}
