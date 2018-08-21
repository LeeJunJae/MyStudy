#include "FruitBuyer.h"
#include "FruitSeller.h"


void FruitBuyer::InitMembers(int money)
{
	this->myMoney = money;
	this->numofApples = 0;
}

void FruitBuyer::BuyApples(FruitSeller &seller, int num)
{
	if (num < 0)
	{
		std::cout << "0���� ���� ���ڴ� �Է��Ҽ� �����ϴ�.";
		return;
	}
	numofApples += seller.salesApple(num);
	myMoney -= (num * seller.GetPrice());
}

void FruitBuyer::ShowBuyerState() const
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
