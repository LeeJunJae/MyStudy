#include "Account_.h"
#include "AccountHandler.h"


enum SELECT_MENU
{
	MAKE = 1,
	DEPOSIT,
	WITHDRAW,
	INQUIRE,
	EXIT
};



int main()
{
	int choice = 0;
	AccountHandler accHandler;

	while (true)
	{
		accHandler.ShowMenu();
		cout << "¼±ÅÃ : ";
		cin >> choice;
		cout << endl;


		switch (choice)
		{
		case MAKE:
		{
			accHandler.MakeAccount();
		}
		break;

		case DEPOSIT:
		{
			accHandler.DepositMoney();
		}
		break;

		case WITHDRAW:
		{
			accHandler.WithdrawMoney();
		}
		break;

		case INQUIRE:
		{
			accHandler.ShowAllAccInfo();
		}
		break;

		case EXIT:
		{			
			return 0;
		}
		break;
		}

	}



	return 0;
}