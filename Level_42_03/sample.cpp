#include <stdio.h>



int data[3] = { 1,2,3 };

int intArr[50] = { 1,2,3 };
int parent[50] = { -1, -1, -1 };
int level[50] = { 1,1,1 };

int startY = 0;
int srartX = 0;

int Arr[5][3] =
{
	1,2,3,
	1,2,3,
	1,2,3,
	1,2,3,
	1,2,3,
};

int history[10];

int direct[3][2] =
{
	1,-1,
	1,0,
	1,1,
};
int cnt = 0;

void BBQ(int level, int dy, int dx)
{
	if (level == 5)
	{
	/*	if (history[0] == Arr[startY][srartX])
		{

			for (int i = 0; i < 4; i++)
			{
				printf("%d", history[i]);
			}
			printf("\n");

			cnt++;

		}
*/


		for (int i = 0; i <5; i++)
		{
			printf("%d", history[i]);
		}
		printf("\n");

		cnt++;
		
		return;
	}

	


	for (int i = 0; i < 3; i++)
	{
		int newY = direct[i][0] + dy;
		int newX = direct[i][1] + dx;



		if (newX >= 0 && newX <= 2)
		{
			history[level] = Arr[newY][newX];
			//intArr[newY][newX] = 

			BBQ(level + 1, newY, newX);

			history[level] = 0;
		}
	}



}

int main()
{

	BBQ(0, 0, 1);






	//int iparent = 0;
	//int head = 0;
	//int tail = 3;


	//while (true)
	//{
	//	for (int icnt = 0; icnt < 5; icnt++)
	//	{
	//		data[tail] = data[icnt];
	//		level[tail] = level[head] + 1; //부모보다 level + 1
	//		parent[tail] = head; //어떤 index로 부터 만들어졌는지 적어둠 = head를 적음

	//		tail++;
	//	}

	//	head++;

	//	if (level[head] == 3)
	//	{



	//		break;
	//	}
	//}



	return 0;
}