
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
	const char *title[] = { "사원", "대리", "과장", "부장", "임원" };
	
	
	
	std::cout << title[positon];

}


 void Employee::GetSalaryType()
{
	const char *type[] = { "시급제", "월급제", "연봉제" };
	
	
	std::cout << type[salaryType];
}

 int Employee::GetSalary()
 {
	 return 0;
 }