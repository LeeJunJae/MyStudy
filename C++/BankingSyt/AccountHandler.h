#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "Account_.h"

const int NAME_LEN = 20;

class AccountHandler
{
private:
	Account * accArr[100];
	int accNum = 0;
	

public:
	AccountHandler();
	~AccountHandler();

	void ShowMenu(void);
	void MakeAccount(void);
	void DepositMoney(void);
	void WithdrawMoney(void);
	void ShowAllAccInfo(void);

};

