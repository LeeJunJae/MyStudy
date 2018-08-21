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
	std::cout << "구매한 사과 : " << numofApples << std::endl;
	std::cout << "남은 돈 : " << myMoney << std::endl;
}

FruitBuyer::FruitBuyer()
{
}


FruitBuyer::~FruitBuyer()
{
}
