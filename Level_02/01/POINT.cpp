#include "POINT.h"



bool POINT::InitMembers(int dy, int dx)
{
	if ((dy <= 100 || dy >= 0) && (dx >=0 || dx<= 100))
	{
		this->y = dy;
		this->x = dx;

		return true;
	}
	else
	{
		cout << "벗어난 범위 값!!" << endl;
		return false;
	}
	
}

int POINT::GetX()
{
	return x;
}

int POINT::GetY()
{
	return y;
}

void POINT::SetX(int dx)
{
	this->x = dx;
}

void POINT::SetY(int dy)
{
	this->y = dy;
}

POINT::POINT()
{
}


POINT::~POINT()
{
}
