#include "FruitSeller.h"
#include "FruitBuyer.h"



int main()
{
	FruitSeller seller;
	seller.InitMembers(100, 40, 0);

	FruitBuyer buyer;
	buyer.InitMembers(5000);

	buyer.BuyApples(seller, 20);

	std::cout << "���� �Ǹ���" << std::endl;
	seller.ShowSalesResult();

	std::cout << "���� ������" << std::endl;
	buyer.ShowBuyerState();

	return 0;
}