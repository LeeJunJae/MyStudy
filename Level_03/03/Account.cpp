#include "Account.h"



void Account::WithDraw(int money)
{
	this->money += money;
}

void Account::Deposit(int money)
{
	this->money -= money;
}

void Account::PrintInfo()
{
	std::cout << "ÀÌ¸§ : " << this->name << std::endl;
	std::cout << "°èÁÂ¹øÈ£ : " << this->account_num << std::endl;
	std::cout << "ÀÜ¾× : " << this->money << std::endl;
}

void Account::SetName(char * name)
{
	this->name = new char[strlen(name)];
	strcpy(this->name, name);
}

void Account::SetNum(int num)
{
	this->account_num = num;
}

int Account::getNum()
{
	return this->account_num;
}



Account::Account()
{
	this->name = NULL;
	this->money = 0;
	this->account_num = NULL;
}


Account::~Account()
{
}
