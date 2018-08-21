#include "FruitBuyer.h"
#include "FruitSeller.h"


void FruitBuyer::InitMembers(int money)
{
	this->myMoney = money;
	this->numofApples = 0;
}

void FruitBuyer::BuyApples(FruitSeller &seller, int num)
{
	numofApples += seller.salesApple(num);
	myMoney -= (num * seller.GetPrice());
}

void FruitBuyer::ShowBuyerState()
{
	std::cout << "������ ��� : " << numofApples << std::endl;
	std::cout << "���� �� : " << myMoney << std::endl;
}

FruitBuyer::FruitBuyer()
{
}


FruitBuyer::~FruitBuyer()
{
}
