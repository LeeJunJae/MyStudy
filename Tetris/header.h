#pragma once
#pragma once
#include <Windows.h>
#include <stdio.h>
#include <stdlib.h>


int minX = 10;
int maxX = 0;
int minY = 10;
int maxY = 0;

int dY = 5;
int dX = 2;

int map[22][12] =
{
	9,9,9,9,9,9,9,9,9,9,9,9,
	9,0,0,0,0,0,0,0,0,0,0,9,
	9,0,0,0,0,0,0,0,0,0,0,9,
	9,0,0,0,0,0,0,0,0,0,0,9,
	9,0,0,0,0,0,0,0,0,0,0,9,
	9,0,0,0,0,0,0,0,0,0,0,9,
	9,0,0,0,0,0,0,0,0,0,0,9,
	9,0,0,0,0,0,0,0,0,0,0,9,
	9,0,0,0,0,0,0,0,0,0,0,9,
	9,0,0,0,0,0,0,0,0,0,0,9,
	9,0,0,0,0,0,0,0,0,0,0,9,
	9,0,0,0,0,0,0,0,0,0,0,9,
	9,0,0,0,0,0,0,0,0,0,0,9,
	9,0,0,0,0,0,0,0,0,0,0,9,
	9,0,0,0,0,0,0,0,0,0,0,9,
	9,0,0,0,0,0,0,0,0,0,0,9,
	9,0,0,0,0,0,0,0,0,0,0,9,
	9,0,0,0,0,0,0,0,0,0,0,9,
	9,0,0,0,0,0,0,0,0,0,0,9,
	9,0,0,0,0,0,0,0,0,0,0,9,
	9,0,0,0,0,0,0,0,0,0,0,9,
	9,5,5,5,5,5,5,5,5,5,5,9,
};

int block[4][4] =
{
	1,1,1,0,
	0,0,1,0,
	0,0,0,0,
	0,0,0,0,
};
int tempBlock[4][4] =
{
	0
};

void InitBlock();
void InittempBlock();
void PrintAll();
void SpinBlock();
void DeriveXY();
void MoveOriginPoint();
int  IsStackWall(int dy, int dx);


void PrintAll()
{
	//ystem("cls");
	int offsetY = 0;
	int offsetX = 0;

	for (int y = 0; y < 22; y++)
	{

		for (int x = 0; x < 12; x++)
		{
			offsetX = x - dX;
			offsetY = y - dY;
			if (y >= dY && y < dY + 4
				&& x >= dX && x < dX + 4
				&& block[offsetY][offsetX] == 1)
			{
				printf("*");
			}
			else
			{
				if (map[y][x] == 0 || map[y][x] == 1)
				{
					printf("_");
				}
				else
				{
					printf("#", map[y][x]);
				}

			}
		}
		printf("\n");
		offsetY = 0;
	}
}

void SpinBlock()
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			tempBlock[j][3 - i] = block[i][j];
		}
	}

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			block[i][j] = tempBlock[i][j];
			tempBlock[i][j] = 0;
		}
	}
}

void DeriveXY()
{
	minX = 10;
	maxX = 0;
	minY = 10;
	maxY = 0;

	for (int idxY = 0; idxY < 4; idxY++)
	{
		for (int idxX = 0; idxX < 4; idxX++)
		{
			if (block[idxY][idxX] == 1)
			{
				if (minX > idxX) minX = idxX;
				if (maxX < idxX) maxX = idxX;
				if (minY > idxY) minY = idxY;
				if (maxY < idxY) maxY = idxY;
			}
		}
	}
}

void MoveOriginPoint()
{
	int idxY = 0;
	int idxX = 0;
	for (int Y = minY; Y <= maxY; Y++)
	{
		idxX = 0;
		for (int X = minX; X <= maxX; X++)
		{
			//if(map[][])
			tempBlock[idxY][idxX] = block[Y][X];
			idxX++;
		}
		idxY++;
	}

	idxY = 0;
	idxX = 0;

	InitBlock();

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			block[i][j] = tempBlock[i][j];
		}
	}
}

void InitBlock()
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			block[i][j] = 0;
		}
	}
}
void InittempBlock()
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			tempBlock[i][j] = 0;
		}
	}
}



int IsStackWall(int dy, int dx)
{

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (block[i][j] == 1)
			{
				map[dy + i][dx + j] += 1;
			}
		}
	}

	for (int i = 0; i < 22; i++)
	{
		for (int j = 0; j < 12; j++)
		{
			if (map[i][j] == 10)
			{


				return 1;
			}
		}
	}

	return 0;

}

void mapInit()
{
	for (int i = 0; i < 22; i++)
	{
		for (int j = 0; j < 12; j++)
		{
			if (map[i][j] == 10)
			{
				map[i][j] = 9;
			}

			if (map[i][j] == 1)
			{
				map[i][j] = 0;
			}

			if (map[i][j] == 5)
			{
				map[i][j] = 5;
			}
		}
	}
}

void RightSpinBlock()
{
	SpinBlock();
	DeriveXY();
	MoveOriginPoint();
	InittempBlock();
}
