#include <stdio.h>
#include <iostream>


char data[5] = { 'A','B','C','D','E'};
char str[200] = { 'A','B','C','D','E' };
int parent[200] = { -1, -1, -1, -1 ,-1 };
int level[200] = { 1,1,1,1,1 };

char history[3] = { 0 };

int IsSame()
{
	
	
	if (history[0] == history[1] || history[1] == history[2] || history[0] == history[2])
	{		
		
		return 1;
	}

		

	

	return 0;
}


int main()
{
	

	int iparent = 0;
	int head = 0;
	int tail = 5;


	while (true)
	{
		for (int iCnt = 0; iCnt < 5; iCnt++)
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


	/*printf("%C", str[tail]);
	int idx = parent[tail];
	printf("%C", str[idx]);
	int i*/
	
	tail--;
	int idx = tail;
	while (true)
	{
		if (idx == 0)
		{
			break;
		}

		if (idx == -1)
		{
			tail -= 1;
			idx = tail;
			
		}


		for (int i = 0; i < 3; i++)
		{
			history[i] = str[idx];
			idx = parent[idx];

			if (IsSame() == 0)
			{
				for (int j = 0; j < 3; j++)
				{
					printf("%c", history[j]);
					//std::cout << history[j];

				}
				printf("\n");
			}
		}

		for (int j = 0; j < 3; j++)
		{
			history[j] = 0;
		}

		/*if (IsSame() == 0)
		{
			printf("%S", history);
			printf("\n");
		}*/
		
	}

	for (int i = 0; i < 5; i++)
	{
		printf("%C", 'A' + i);
		printf("\n");
	}


	return 0;
}