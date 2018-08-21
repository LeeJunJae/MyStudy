#pragma once
#include <iostream>

using namespace std;

class POINT
{
private:
	int y;
	int x;

public:
	bool InitMembers(int dy, int dx);
	int GetX();
	int GetY();
	void SetX(int dx);
	void SetY(int dy);

public:
	POINT();
	~POINT();
};

