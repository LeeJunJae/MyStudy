
#include "Employee.h"



Employee::Employee(const char* name, char positon, char salaryType)
{
	employeeName = (char*)malloc(strlen(name) + 1);
	strcpy(employeeName, name);

	this->positon = positon;
	this->salaryType = salaryType;
}


Employee::~Employee()
{
	delete[] employeeName;
}


char* Employee::GetName()
{
	return employeeName;
}


 void Employee::GetPositon()
{
	const char *title[] = { "���", "�븮", "����", "����", "�ӿ�" };
	
	
	
	std::cout << title[positon];

}


 void Employee::GetSalaryType()
{
	const char *type[] = { "�ñ���", "������", "������" };
	
	
	std::cout << type[salaryType];
}

 int Employee::GetSalary()
 {
	 return 0;
 }