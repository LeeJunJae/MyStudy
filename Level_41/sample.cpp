#include <stdio.h>


int map[7][7] = { 0 };
int posY = 3;
int posX = 3;

int direct[8][2] =
{
	-1,-2,
	-2,-1,
	-2,1,
	-1,2,

	1,2,
	2,1,
	2,-1,
	1,-2,
};
int count = 1;
int check = 1;

void newDestination(int dy, int dx)
{
	for (int i = 0; i < 8; i++)
	{
		int newY = dy + direct[i][0];
		int newX = dx + direct[i][1];

		if (newY < 0 || newY > 6 || newX < 0 || newX > 6 || map[newY][newX] != 0)
		{
			//
		}
		else
		{
			map[newY][newX] = count;			
		}
		
	}

	
}

int main()
{
	map[posY][posX] = 9; //말 
	//map[1][5] = 8; //당근

		for (int i = 0; i < 8; i++)
		{
			int newY = posY + direct[i][0];
			int newX = posX + direct[i][1];

			map[newY][newX] = count;

			int posY = 3;
			int posX = 3;

		}

		count++;


		while (true)
		{
			if (map[1][5] != 0)
			{
				break;
			}
			
			for (int y = 0; y < 7; y++)
			{
				for (int x = 0; x < 7; x++)
				{
					if (map[y][x] == check )
					{

						newDestination(y, x);
					}
				}
			}

			count++;
			check++;
		}
		printf("%d  번만에 당근먹음", map[1][5]);


	return 0;
}