#include <stdio.h>


int data[6][2] = 
{
	1,6,
	3,8,
	8,9,
	2,4,
	4,6,
	7,9,
};


int buffer[6][2] = { 0 };
int min = 99;
int startIdx = 1;
int count = 0;

void findmin(int start)
{
	for (int i = start-1; i < 6; i++)
	{
		if (start >= data[i][0])
		{
			start = i+1;
			break;
		}
	}


	for (int i = start-1; i < 6; i++)
	{
		if (min > data[i][1])
		{
			min = data[i][1];
			//data[i][1] = 99;
			
			startIdx = min;
		
		}
	}
	count++;
	min = 99;
}

void function(int time)
{
	//for (int i = 0; i < 6; i++)
	//{
	//	if (min > data[i][1])
	//	{
	//		min = data[i][1];
	//	}
	//}

	//for (int i = 0; i < 6; i++)
	//{
	//	if (data[i][0] >= min)
	//	{
	//		for(int j=i; j<i; j++)
	//		{
	//		}
	//	}
	//}

	findmin(startIdx);

	while (true)
	{
		
		
		findmin(startIdx);
		

		if (startIdx == 9)
		{
			break;
		}
	}
	



}



int main()
{
	for (int y = 0; y < 5; y++)
	{
		for (int x = 0; x < 5; x++)
		{
			if (data[x][0] > data[x + 1][0])
			{
				int tempA = data[x][0];
				data[x][0] = data[x + 1][0];
				data[x + 1][0] = tempA;

				int tempB = data[x][1];
				data[x][1] = data[x + 1][1];
				data[x + 1][1] = tempB;


			}			
		}
	}

	
	function(0);


	return 0;
}