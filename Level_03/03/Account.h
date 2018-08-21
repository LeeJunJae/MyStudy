#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>



class Account
{
private:
	char* name;
	int account_num;	
	int   money;

public:
	void WithDraw(int money);
	void Deposit(int money);
	void PrintInfo();

	void SetName(char* name);
	void SetNum(int num);	

	int getNum();
public:
	Account();
	~Account();
};

