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

	virtual int GetPay() const = 0;				//순수가상함수	
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

class SalesWorker : public PermanentWorker // 영업직
{
private:
	int		salesResult; // 월 판매실적
	double	bonusRatio; // 상여금 비율
public:
	void AddSalesResult(int value)
	{
		salesResult += value;
	}
	int GetPay() const
	{
		return PermanentWorker::GetPay() + (int)(salesResult * bonusRatio);   //permenetwroker의 getpay 호출
	}
public:
	SalesWorker(const char* name, int money, double ratio) : PermanentWorker(name, money), salesResult(0), bonusRatio(ratio) {};

};

class TemporaryWorker : public Employee //임시직
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

