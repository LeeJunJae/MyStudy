#include "Calculator.h"



float Calculator::Add(float num1, float num2)
{
	this->plus++;
	float add = 0.0f;
	add = (num1 + num2);
	return add;
}

float Calculator::Sub(float num1, float num2)
{
	minus++;
	float minus = (num1 - num2);
	return minus;
}

float Calculator::Division(float num1, float num2)
{
	divide++;
	float div = (num1 / num2);
	return div;
}

float Calculator::Multi(float num1, float num2)
{
	times++;
	float time = (num1 * num2);
	return time;
}

void Calculator::showOpCount()
{
	cout << plus << minus << divide << times << endl;
}

Calculator::Calculator()
{
	plus = 0;	
	minus = 0;
	divide = 0;
	times = 0;
}


Calculator::~Calculator()
{
}
