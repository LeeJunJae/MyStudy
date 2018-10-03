#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>

using namespace std;

class Account
{
private:
	int accID;     //°èÁÂ ¹øÈ£
	int balance;   //ÀÜ¾×
	char* cusName; //°í°´ÀÌ¸§

public:
	Account(int ID, int money, char* name);
	Account(const Account& pAcc);
	~Account();


	int GetAccID() const;
	void Deposit(int money);
	int Withdraw(int money);	
	void ShowAccInfo() const;
};

