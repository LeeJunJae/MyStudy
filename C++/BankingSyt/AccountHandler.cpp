#include "AccountHandler.h"



AccountHandler::AccountHandler()
{
	accNum = 0;
}


AccountHandler::~AccountHandler()
{
	for (int i = 0; i < accNum; i++)
	{
		delete accArr[i];
	}
}

void AccountHandler::ShowMenu(void)
{
	cout << "-------MENU--------" << endl;
	cout << " 1.  계좌개설 " << endl;
	cout << " 2.  입    금" << endl;
	cout << " 3.  출    금" << endl;
	cout << " 4.  계좌정보출력" << endl;
	cout << " 5.  프로그램종료" << endl;
}

void AccountHandler::MakeAccount(void)
{
	int  id;
	char name[NAME_LEN];
	int  balance;

	cout << "[계좌 개설]" << endl;
	cout << "계좌ID : ";  cin >> id;
	cout << "이름 : ";    cin >> name;
	cout << "입금액 : ";  cin >> balance;
	cout << endl;

	accArr[accNum] = new Account(id, balance, name);
	accNum++;
}

void AccountHandler::DepositMoney(void)
{
	int money;
	int id;

	cout << "[입    금]" << endl;
	cout << "계좌ID : "; cin >> id;
	cout << "입금액 : "; cin >> money;

	for (int i = 0; i < accNum; i++)
	{
		if (accArr[i]->GetAccID() == id)
		{
			accArr[i]->Deposit(money);
			cout << "입금 완료" << endl << endl;
			return;
		}
	}
}

void AccountHandler::WithdrawMoney(void)
{
	int money;
	int id;

	cout << "[출    금]" << endl;
	cout << "계좌ID : "; cin >> id;
	cout << "출금액 : "; cin >> money;

	for (int i = 0; i < accNum; i++)
	{
		if (accArr[i]->GetAccID() == id)
		{
			accArr[i]->Withdraw(money);
			cout << "출금 완료" << endl << endl;
			return;
		}
	}
}

void AccountHandler::ShowAllAccInfo(void)
{
	for (int i = 0; i < accNum; i++)
	{
		accArr[i]->ShowAccInfo();
		cout << endl;
	}
}

