#include <stdio.h>
#include "Employee.h"
#include "HowToPay.h"

int main(void)
{
	Employee* employee = new Hourly("���", 0, 10);
	
	employee->GetSalary();


	printf("chekc");






	return 0;
}