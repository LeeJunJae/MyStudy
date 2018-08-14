#include <stdio.h>


int arr[5][5] =
{
	0, 80, 10,  60, 200,
	80, 0, 1000, 30, 30,
	10,1000,0,   20, 1000,
	60, 30,   20,0, 1000,
	200,30,   1000,1000,0,
};


int course[5] = { 0, 80, 10 ,60 ,200 };

int main()
{

	int icourse = 0;
	int straight = 0;


	for (int y = 1; y < 5; y++) //°æ·Î
	{
		for (int x = 1; x < 5; x++) // µµÂøÁö
		{
			if (y != x)
			{
				icourse = course[y] + arr[y][x];
				straight = course[x];

				if (icourse < straight)
				{
					course[x] = icourse;
				}
			}
		}
	}


	return 0;
}