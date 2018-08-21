#pragma once
#include "POINT.h"


class RECTANGLE
{
private:
	POINT upLeft;
	POINT downRight;

public:
	void InitMembers(const POINT& upLeft, const POINT& dowRight);
	void ShowRectInfo();


public:
	RECTANGLE();
	~RECTANGLE();
};

