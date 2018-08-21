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
	int GetX() const;
	int GetY() const;
	void SetX(int dx);
	void SetY(int dy);

	void PrintPoint();

public:
	POINT();
	~POINT();
};

