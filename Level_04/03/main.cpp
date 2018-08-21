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
	int accID;     //���� ��ȣ
	int balance;   //�ܾ�
	char* cusName; //���̸�

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
		cout << "����ID : " << accID << endl;
		cout << "��  �� : " << cusName << endl;
		cout << "��  �� : " << balance << endl;
	}

	~Account()
	{
		delete[]cusName;
	}

};


Account* accArr[100];
int accNum = 0;


//�����Լ�
int main()
{
	int choice = 0;

	while (true)
	{
		ShowMenu();
		cout << "���� : ";
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


//�Լ� ������
void ShowMenu(void)
{
	cout << "-------MENU--------" << endl;
	cout << " 1.  ���°��� " << endl;
	cout << " 2.  ��    ��" << endl;
	cout << " 3.  ��    ��" << endl;
	cout << " 4.  �����������" << endl;
	cout << " 5.  ���α׷�����" << endl;
}

void MakeAccount(void)
{
	int  id;
	char name[NAME_LEN];
	int  balance;

	cout << "[���� ����]" << endl;
	cout << "����ID : ";  cin >> id;
	cout << "�̸� : ";  cin >> name;
	cout << "�Աݾ� : ";  cin >> balance;
	cout << endl;

	accArr[accNum] = new Account(id, balance, name);
	accNum++;
}

void DepositMoney(void)
{
	int money;
	int id;

	cout << "[��    ��]" << endl;
	cout << "����ID : "; cin >> id;
	cout << "�Աݾ� : "; cin >> money;

	for (int i = 0; i < accNum; i++)
	{
		if (accArr[i]->GetAccID() == id)
		{
			accArr[i]->Deposit(money);
			cout << "�Ա� �Ϸ�" << endl << endl;
			return;
		}
	}
}

void WithdrawMoney(void)
{
	int money;
	int id;

	cout << "[��    ��]" << endl;
	cout << "����ID : "; cin >> id;
	cout << "��ݾ� : "; cin >> money;

	for (int i = 0; i < accNum; i++)
	{
		if (accArr[i]->GetAccID() == id)
		{
			accArr[i]->Withdraw(money);
			cout << "��� �Ϸ�" << endl << endl;
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