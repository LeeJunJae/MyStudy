#include <stdio.h>

int map[4][4] =
{
	0,0,0,1,
	1,1,0,0,
	0,0,0,0,
	0,1,1,0,
};

int buffer[4][4] =
{
	0,0,0,2,
	2,2,0,0,
	0,0,0,0,
	0,2,2,0,
};

int history[4][4] = 
{
	0,0,0,1,
	1,1,0,0,
	0,0,0,0,
	0,1,1,0,
};

int cnt = 0;

int IsCheck()
{
	for (int y = 0; y < 4; y++)
	{
		for (int x = 0; x < 4; x++)
		{
			if (buffer[y][x] == 0)
				return 1;
		}
	}

	return 0;
}

void PrintCross(int dy, int dx)
{
	
	for (int x = 0; x < 4; x++)
	{
		if (dx + x > 3 || buffer[dy][dx+x] == 2)
		{
			break;
		}
		buffer[dy][dx + x] = 1;		
	}

	for (int y = 0; y < 4; y++)
	{
		if (dy + y > 3 || buffer[dy+y][dx] == 2)
		{
			break;
		}

		buffer[dy + y][dx] = 1;
	}
	
}

void DFS(int level, int dy, int dx)
{
	

	buffer[dy][dx] = 1;
	cnt++;
	PrintCross(dy, dx);

	if (IsCheck() == 0)
	{
		//버퍼를 초기화

		return;
	}

	for (int y = 0; y < 4; y++)
	{
		for (int x = 0; x < 4; x++)
		{
			if (buffer[y][x] == 0)
			{
				DFS(level + 1,  y,  x);
			}
		}
	}

}


int main()
{
	DFS(0, 0, 0);


	return 0;
}



//
//int data[10] = { 0 };
//
//
//
//int DNum(int num)
//{
//	int sum = 0;
//	int divide = 1000;
//	int dNum = 0;
//	int idx = 0;
//
//
//	data[idx] = num;
//	idx++;
//	while (true)
//	{
//		if (num < 10)
//		{
//			data[idx] = num;
//			break;
//		}
//
//
//
//		dNum = num / divide;
//
//		if (dNum  != 0)
//		{
//			data[idx] = dNum;
//			idx++;
//
//			num -= dNum * divide;
//
//			divide /= 10;
//			dNum = 0;
//		}
//		else
//		{
//			divide /= 10;
//		}
//
//	}
//
//	for (int i = 0; i < 10; i++)
//	{
//		sum += data[i];
//	}
//
//
//
//	return sum;
//}
//
//
//
//int main()
//{
//	int inputNum = 91;
//
//	DNum(inputNum);
//
//
//
//	return 0;
//}