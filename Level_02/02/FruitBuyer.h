#pragma once
#include "FruitSeller.h"


class FruitBuyer
{
private:
	int myMoney;
	int numofApples;

public:
	void InitMembers(int money);
	void BuyApples(FruitSeller &seller, int num);
	void ShowBuyerState() const;
	

	FruitBuyer();
	~FruitBuyer();
};

