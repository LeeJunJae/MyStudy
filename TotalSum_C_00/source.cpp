#include <stdio.h>




int main()
{
	int num      = 0;
	int totalSum = 0;


	//////////////�����////////////////////
	for (int num = 0; num < 100; num++) 
	{
		totalSum += num + 1;
	}
	printf("%d\n", totalSum);


	totalSum = 0;	
	while (num <= 100)
	{
		totalSum += num;
		num++;
	}
	printf("%d\n", totalSum);


	totalSum = 0;
	num      = 0;
	do
	{
		totalSum += num;
		num++;
	}while (num <= 100);
	printf("%d\n", totalSum);


	////////////Ȧ��,¦���� �����//////////
	int oddNum  = 0;
	int evenNum = 0;
	for (int num = 0; num < 100; num++)
	{
		if (num % 2 == 0)
		{
			evenNum += num;
		}
		else
		{
			oddNum += num;
		}
	}
	printf("Ȧ�� : %d , ¦�� : %d \n", oddNum, evenNum);



	return 0;
}