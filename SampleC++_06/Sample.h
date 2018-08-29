#pragma once
using namespace std;


class Employee
{
private:
	char *name;
public:
	Employee(const char* name)
	{
		this->name = new char[strlen(name) + 1];
		strcpy(this->name, name);
	}

	virtual int GetPay() const = 0;				//���������Լ�	
	virtual void ShowSalaryInfo() const = 0;

	virtual void ShowYourName() const
	{
		cout << "name : " << this->name << endl;
	}
};

class PermanentWorker : public Employee
{
private:
	int salary;
public:
	int GetPay() const
	{
		return salary;
	}
	void ShowSalaryInfo() const
	{
		ShowYourName();
		cout << "salary : " << GetPay() << endl << endl;
	}
public:
	PermanentWorker(const char* name, int money) : Employee(name), salary(money) {};
};

class SalesWorker : public PermanentWorker // ������
{
private:
	int		salesResult; // �� �ǸŽ���
	double	bonusRatio; // �󿩱� ����
public:
	void AddSalesResult(int value)
	{
		salesResult += value;
	}
	int GetPay() const
	{
		return PermanentWorker::GetPay() + (int)(salesResult * bonusRatio);   //permenetwroker�� getpay ȣ��
	}
public:
	SalesWorker(const char* name, int money, double ratio) : PermanentWorker(name, money), salesResult(0), bonusRatio(ratio) {};

};

class TemporaryWorker : public Employee //�ӽ���
{
private:
	int workTime;
	int payPerHour;
public:
	void AddWorkTime(int time)
	{
		workTime += time;
	}
	int GetPay() const
	{
		return workTime * payPerHour;
	}
	void ShowSalaryInfo() const
	{
		ShowYourName();
		cout << "salary : " << GetPay() << endl << endl;
	}

public:
	TemporaryWorker(const char* name, int pay) : Employee(name), workTime(0), payPerHour(pay) {};
	~TemporaryWorker() {};
};

