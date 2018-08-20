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
			level[tail] = level[head] + 1; //부모보다 Level + 1
			parent[tail] = head; //어떤 index로 부터 만들어졌는지 적어둠 = head를 적음

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