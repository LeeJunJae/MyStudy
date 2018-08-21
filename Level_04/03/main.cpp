#define  _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstringt.h>
using namespace std;

const int NAME_LEN = 20;

void ShowMenu(void);
void MakeAccount(void);
void DepositMoney(void);
void WithdrawMoney(void);
void ShowAllAccInfo(void);

enum SELECT_MENU
{
	MAKE = 1,
	DEPOSIT,
	WITHDRAW,
	INQUIRE,
	EXIT
};

class Account
{
private:
	int accID;     //계좌 번호
	int balance;   //잔액
	char* cusName; //고객이름

public:
	Account(int ID, int money, char* name) : accID(ID), balance(money)
	{
		cusName = new char[strlen(name) + 1];
		strcpy(cusName, name);
	}

	Account(const Account& pAcc)
	{
		this->accID = pAcc.accID;
		this->accID = pAcc.balance;

		this->cusName = new char[strlen(pAcc.cusName)+1];
		strcpy(this->cusName, pAcc.cusName);
	}

	int GetAccID() const
	{
		return accID;
	}

	void Deposit(int money)
	{
		balance += money;
	}

	int Withdraw(int money)
	{
		if (balance < money)
		{
			return 0;
		}

		balance -= money;
		return money;
	}

	void ShowAccInfo() const
	{
		cout << "계좌ID : " << accID << endl;
		cout << "이  름 : " << cusName << endl;
		cout << "잔  액 : " << balance << endl;
	}

	~Account()
	{
		delete[]cusName;
	}

};


Account* accArr[100];
int accNum = 0;


//메인함수
int main()
{
	int choice = 0;

	while (true)
	{
		ShowMenu();
		cout << "선택 : ";
		cin >> choice;
		cout << endl;


		switch (choice)
		{
		case MAKE:
		{
			MakeAccount();
		}
		break;

		case DEPOSIT:
		{
			DepositMoney();
		}
		break;

		case WITHDRAW:
		{
			WithdrawMoney();
		}
		break;

		case INQUIRE:
		{
			ShowAllAccInfo();
		}
		break;

		case EXIT:
		{
			for (int i = 0; i < accNum; i++)
			{
				delete[] accArr[i];
			}
			return 0;
		}
		break;
		}

	}
}


//함수 구현부
void ShowMenu(void)
{
	cout << "-------MENU--------" << endl;
	cout << " 1.  계좌개설 " << endl;
	cout << " 2.  입    금" << endl;
	cout << " 3.  출    금" << endl;
	cout << " 4.  계좌정보출력" << endl;
	cout << " 5.  프로그램종료" << endl;
}

void MakeAccount(void)
{
	int  id;
	char name[NAME_LEN];
	int  balance;

	cout << "[계좌 개설]" << endl;
	cout << "계좌ID : ";  cin >> id;
	cout << "이름 : ";  cin >> name;
	cout << "입금액 : ";  cin >> balance;
	cout << endl;

	accArr[accNum] = new Account(id, balance, name);
	accNum++;
}

void DepositMoney(void)
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

void WithdrawMoney(void)
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

void ShowAllAccInfo(void)
{
	for (int i = 0; i < accNum; i++)
	{
		accArr[i]->ShowAccInfo();
		cout << endl;
	}
}