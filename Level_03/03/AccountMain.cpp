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
	std::cout << "���̵� �Է� :";
	int strNum = 0;
	std::cin >> strNum;

	for (int i = 0; i < 10; i++)
	{
		if (arr[i] != NULL)
		{
			if (arr[i]->getNum() == strNum)
			{
				int money = 0;
				std::cout << " ���Է� : ";
				std::cin >> money;

				arr[i]->WithDraw(money);
			}
		}

		return;
	}	
}

void Deposit()
{
	std::cout << "���̵� �Է� :";
	int strNum = 0;
	std::cin >> strNum;

	for (int i = 0; i < 10; i++)
	{
		if (arr[i] != NULL)
		{
			if (arr[i]->getNum() == strNum)
			{
				int money = 0;
				std::cout << " ���Է� : ";
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
		std::cout << "1. ���°��� " << std::endl;
		std::cout << "2. ��	   �� " << std::endl;
		std::cout << "3. ��    �� " << std::endl;
		std::cout << "4. ����������� " << std::endl;
		std::cout << "5. ��    �� " << std::endl;

		std::cin >> select;



		switch (select)
		{
		case ACC::CREATE:
		{
			std::cout << "�̸� �Է� : ";
			char str[20] = { 0 };
			
			std::cin >> str;

			std::cout << "id�Է� : ";
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

