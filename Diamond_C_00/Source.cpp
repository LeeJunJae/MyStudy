#include <stdio.h>

int inputNum = 0;

int main()
{
	printf ("����� ���̾Ƹ���� ũ�⸦ �����ϼ��� : ");
	scanf_s("%d", &inputNum);

	//���̾Ƹ���� ���κ� ���
	for (int upLine = 0; upLine < inputNum; upLine++)
	{
		//����� ���
		for (int i = 0; i < (inputNum-1) - upLine; i++)
		{
			printf("-");
		}
		//�����
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
	// ���̾Ƹ���� �Ʒ��κ� ���
	for (int downLine = 0; downLine < inputNum-1 ; downLine++)
	{
		//����� ���
		for (int i = 0; i < downLine+1 ; i++)
		{
			printf("-");
		}
		//�� ���
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