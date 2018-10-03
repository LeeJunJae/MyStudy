#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>

using namespace std;

class Account
{
private:
	int accID;     //���� ��ȣ
	int balance;   //�ܾ�
	char* cusName; //���̸�

public:
	Account(int ID, int money, char* name);
	Account(const Account& pAcc);
	~Account();


	int GetAccID() const;
	void Deposit(int money);
	int Withdraw(int money);	
	void ShowAccInfo() const;
};

