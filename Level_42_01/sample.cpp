#include <stdio.h>


char data[3] = { 'A','B','C' };
char str[50] = { 'A','B','C' };
int parent[50] = { -1, -1, -1 };
int level[50] = { 1,1,1 };

int main()
{
	int iparent = 0;
	int head = 0;
	int tail = 3;


	while (true)
	{
		for (int iCnt = 0; iCnt < 3; iCnt++)
		{

			str[tail] = data[iCnt];
			level[tail] = level[head] + 1; //�θ𺸴� Level + 1
			parent[tail] = head; //� index�� ���� ����������� ����� = head�� ����

			tail++;
		}

		head++;
		if (level[head] == 3)
		{
			break;
		}
	}



	return 0;
}