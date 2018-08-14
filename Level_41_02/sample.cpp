#include <stdio.h>


int map[6][6] = 
{
	0,3,5,1,
	1,1,1,5,
	1,50,20,10,
	1,50,5,0,
};

int costSum[4][4] = { 
	0,0,0,  16,
	0,0,0,  15,
	0,0,0,  10,
	56,55,5,0,
};
char direction[4][4] = 
{
	0,0,0,'D',
	0,0,0,'D',
	0,0,0,'D',
	'R','R','R',0,
};

int main()
{
	for (int y = 2; y >= 0; y--)		

	{
		for (int x = 2; x >= 0; x--)
		{
			if (costSum[y][x + 1] < costSum[y + 1][x])
			{
				costSum[y][x] = map[y][x] + costSum[y][x + 1];
			}
			else
			{
				costSum[y][x] = map[y][x] + costSum[y+1][x];
			}
		}
	}

	
	int posX = 0;
	int posY = 0;

	while (true)
	{
		if (costSum[posY + 1][posX ] < costSum[posY][posX+ 1])
		{
			direction[posY +1][posX] = 'D';
			posY++;
		}
		else
		{
			direction[posY][posX + 1 ] = 'R';
			posX++;
		}

		
	

		if (costSum[posY][posX] == 0)
		{
			break;
		}
			
	}

	return 0;
}