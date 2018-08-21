#include "FruitSeller.h"



void FruitSeller::InitMembers(int applePrice, int numofApple, int money)
{
	this->applePrice = applePrice;
	this->numofApples = numofApple;
	this->money = money;
}

int FruitSeller::salesApple(int num)
{
	numofApples -= num;
	money += (num*applePrice);

	return num;
}

void FruitSeller::ShowSalesResult()
{
	std::cout << "남은 사과 : " << numofApples << std::endl;
	std::cout << "판매 수익 : " << money << std::endl;
}

int FruitSeller::GetPrice()
{
	return this->applePrice;
}

FruitSeller::FruitSeller()
{
}


FruitSeller::~FruitSeller()
{
}
