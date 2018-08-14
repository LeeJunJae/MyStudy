#pragma once
#include "Employee.h"


class Hourly : public Employee
{
public:
	int GetSalary();


public:
	Hourly(const char* name, char position, char workHour);
	~Hourly();



private:
	int workHour;
	char postion;
};

Hourly::Hourly(const char* name, char position, char workHour) : Employee(name, position, 0) //0번은 사원 index
{
	this->workHour = workHour;
	this->postion = position;
}

Hourly::~Hourly()
{
}


int Hourly::GetSalary()
{
	int salary = this->workHour * 10000;
	for (int i = 0; i < postion; i++)
	{
		salary *= 2;
	}
	return salary;
}