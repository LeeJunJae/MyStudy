#include <iostream>



class Employee
{
private:
	char name[100];

public:
	Employee(char* name)
	{
		strcpy(this->name, name);
		
	}

	void ShowYourName()
	{
		std::cout << "name : " << this->name << std::endl;
	}

};

class PermanentWorker : public Employee
{
private:
	int salary;	//±Þ¿©

public:
	PermanentWorker(char* name, int money) : Employee(name), salary(money)
	{
		//
	}

	int GetPay() const
	{
		return salary;
	}

	void ShowSalaryWinfo()
	{
		ShowYourName();
		std::cout << "salary : " << this->salary << std::endl;
	}
};

class EmployeeHandler
{
private:
	Employee* empList[20];
	int empNum;

public:
	EmployeeHandler() : empNum(0)
	{
		//
	}

	~EmployeeHandler() 
	{
		for (int i = 0; i < empNum; i++)
		{
			delete empList[i];
		}
	}

	void AddEmployee(Employee* emp)
	{
		empList[empNum++] = emp;
	}

	void ShowAllSalaryInfo() const
	{

	}

	void ShowTotalSalary() const
	{
		//
	}
};




int main()
{


	return 0;
}