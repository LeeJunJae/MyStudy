#include "FruitSeller.h"
#include "FruitBuyer.h"



int main()
{
	FruitSeller seller;
	seller.InitMembers(100, 40, 0);

	FruitBuyer buyer;
	buyer.InitMembers(5000);

	buyer.BuyApples(seller, 20);

	std::cout << "과일 판매자" << std::endl;
	seller.ShowSalesResult();

	std::cout << "과일 구매자" << std::endl;
	buyer.ShowBuyerState();

	return 0;
}