#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

class Printer
{
private:
	char str[20];

public:
	void SetString(const char* input);
	void ShowString();

	Printer();
	~Printer();
};
