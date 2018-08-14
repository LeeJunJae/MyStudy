#include <stdio.h>

int inputNum = 0;

int main()
{
	printf ("출력할 다이아몬드의 크기를 결정하세요 : ");
	scanf_s("%d", &inputNum);

	//다이아몬드의 윗부분 출력
	for (int upLine = 0; upLine < inputNum; upLine++)
	{
		//빈공간 출력
		for (int i = 0; i < (inputNum-1) - upLine; i++)
		{
			printf("-");
		}
		//별출력
		for (int j = 0; j < (upLine*2) + 1 ; j++)
		{
			if (j % 2 == 1)
			{
				printf("-");
			}
			else
			{
				printf("*");
			}			
		}		
		printf("\n");
	}
	// 다이아몬드의 아랫부분 출력
	for (int downLine = 0; downLine < inputNum-1 ; downLine++)
	{
		//빈공간 출력
		for (int i = 0; i < downLine+1 ; i++)
		{
			printf("-");
		}
		//별 출력
		for (int j = 0; j < (2*inputNum-3) -(2*downLine) ; j++) //(2 * (num - 2) + 1) - 2 * i
		{
			if (j % 2 == 1)
			{
				printf("-");
			}
			else
			{
				printf("*");
			}			
		}
		printf("\n");
	}

	return 0;
}