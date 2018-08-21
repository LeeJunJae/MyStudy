#pragma once
#include <iostream>

class FruitSeller
{
private:
	int applePrice;
	int numofApples;
	int money;

public:
	void InitMembers(int applePrice, int numofApple, int money);
	int salesApple(int numofApples);
	void ShowSalesResult() const;
	int GetPrice();

	FruitSeller();
	~FruitSeller();
};

