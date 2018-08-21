#pragma once
#include <iostream>

using namespace std;

class Calculator
{
private:
	float plus;
	float minus;
	float divide;
	float times;

public:
	float Add(float num1, float num2);
	float Sub(float num1, float num2);
	float Division(float num1, float num2);
	float Multi(float num1, float num2);

	void showOpCount();
	

public:
	Calculator();
	~Calculator();
};

