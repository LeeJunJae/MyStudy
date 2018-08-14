#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <string.h>
#include <iostream>


class Employee
{
private:
	char* employeeName;
	int   positon;
	int   salaryType;

public:
	 char* GetName();
	 void GetPositon();
	 void GetSalaryType();
	 virtual int GetSalary();

	Employee(const char* name, char positon, char salaryType);
	virtual ~Employee();
};

