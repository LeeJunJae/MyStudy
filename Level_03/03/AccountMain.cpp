#include "Account.h"
#include <Windows.h>

namespace ACC
{
	enum MENUk
	{
		CREATE = 1, WITHDRAW, DEPOSIT, PRINTINFO,EXIT
	};
}

Account* arr[10];
int idx = 0;


void CreateAcc( char* name, int accNum)
{
	Account* acc = new Account;


	acc->SetName(name);
	acc->SetNum(accNum);


	arr[idx++] = acc;
}

void WithDraw()
{
	std::cout << "아이디 입력 :";
	int strNum = 0;
	std::cin >> strNum;

	for (int i = 0; i < 10; i++)
	{
		if (arr[i] != NULL)
		{
			if (arr[i]->getNum() == strNum)
			{
				int money = 0;
				std::cout << " 돈입력 : ";
				std::cin >> money;

				arr[i]->WithDraw(money);
			}
		}

		return;
	}	
}

void Deposit()
{
	std::cout << "아이디 입력 :";
	int strNum = 0;
	std::cin >> strNum;

	for (int i = 0; i < 10; i++)
	{
		if (arr[i] != NULL)
		{
			if (arr[i]->getNum() == strNum)
			{
				int money = 0;
				std::cout << " 돈입력 : ";
				std::cin >> money;

				arr[i]->Deposit(money);
			}
		}

		return;
	}
}

void PrintAllCs()
{
	for (int i = 0; i < 10; i++)
	{
		if (arr[i] != NULL)
		{
			arr[i]->PrintInfo();
		}		
	}
}



int main()
{
	while (true)
	{
		system("cls");


		int select = 0;

		std::cout << "________MENU_________" << std::endl;
		std::cout << "1. 계좌개설 " << std::endl;
		std::cout << "2. 입	   금 " << std::endl;
		std::cout << "3. 출    금 " << std::endl;
		std::cout << "4. 계좌정보출력 " << std::endl;
		std::cout << "5. 정    료 " << std::endl;

		std::cin >> select;



		switch (select)
		{
		case ACC::CREATE:
		{
			std::cout << "이름 입력 : ";
			char str[20] = { 0 };
			
			std::cin >> str;

			std::cout << "id입력 : ";
			int num = 0;
			std::cin >> num;

			CreateAcc(str, num);


		}
		break;

		case ACC::WITHDRAW:
		{
			WithDraw();
		}
		break;

		case ACC::DEPOSIT:
		{
			Deposit();
		}
		break;

		case ACC::PRINTINFO:
		{
			PrintAllCs();
			system("pause");
		}
		break;

		case ACC::EXIT:
		{
			break;
		}
		break;
		}
	}



	return 0;
}

