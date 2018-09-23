#include <vector>

using namespace std;


int main()
{
	int answer = 0;
	int N = 7;
	
	bool check[10] = { false, };
	for (int i = 2; i <= N; i++)
	{
		if (!check[i])
			answer += i;

		for (int j = i; j <= N; j += i)
		{
			check[j] = true;
		}
	}

	return 0;
}
//#include <stdio.h>
//
//int map[4][4] =
//{
//	0,0,0,1,
//	1,1,0,0,
//	0,0,0,0,
//	0,1,1,0,
//};
//
//int buffer[4][4] =
//{
//	0,0,0,2,
//	2,2,0,0,
//	0,0,0,0,
//	0,2,2,0,
//};
//
//int history[4][4] = 
//{
//	0,0,0,1,
//	1,1,0,0,
//	0,0,0,0,
//	0,1,1,0,
//};
//
//int cnt = 0;
//int max = 0;
//
//
//int IsCheck()
//{
//	for (int y = 0; y < 4; y++)
//	{
//		for (int x = 0; x < 4; x++)
//		{
//			if (buffer[y][x] == 0)
//				return 1;
//		}
//	}
//
//	return 0;
//}
//
//void PrintCross(int dy, int dx)
//{
//	
//	for (int x = 0; x < 4; x++)
//	{
//		if (dx + x > 3 || buffer[dy][dx+x] == 2)
//		{
//			break;
//		}
//
//		buffer[dy][dx + x] = 1;		
//	}
//
//	for (int x = 0; x < 4; x++)
//	{
//		if (dx - x < 0 || buffer[dy][dx - x] == 2)
//		{
//			break;
//		}
//
//		buffer[dy][dx - x] = 1;
//	}
//
//	for (int y = 0; y < 4; y++)
//	{
//		if (dy + y > 3 || buffer[dy+y][dx] == 2)
//		{
//			break;
//		}
//
//		buffer[dy + y][dx] = 1;
//	}	
//
//	for (int y = 0; y < 4; y++)
//	{
//		if (dx - y < 0 || buffer[dy - y][dx] == 2)
//		{
//			break;
//		}
//
//		buffer[dy - y][dx ] = 1;
//	}
//}
//
//void DeleteCross(int dy, int dx)
//{
//	for (int x = 0; x < 4; x++)
//	{
//		if (dx + x > 3 || buffer[dy][dx + x] == 2)
//		{
//			break;
//		}
//
//		buffer[dy][dx + x] = 0;
//	}
//
//	for (int x = 0; x < 4; x++)
//	{
//		if (dx - x < 0 || buffer[dy][dx - x] == 2)
//		{
//			break;
//		}
//
//		buffer[dy][dx - x] = 0;
//	}
//
//	for (int y = 0; y < 4; y++)
//	{
//		if (dy + y > 3 || buffer[dy + y][dx] == 2)
//		{
//			break;
//		}
//
//		buffer[dy + y][dx] = 0;
//	}
//
//	for (int y = 0; y < 4; y++)
//	{
//		if (dx - y < 0 || buffer[dy - y][dx] == 2)
//		{
//			break;
//		}
//
//		buffer[dy - y][dx] = 0;
//	}
//}
//
//void DFS(int level, int dy, int dx)
//{
//	
//
//	buffer[dy][dx] = 3;
//	history[dy][dx] = 1;
//	cnt++;
//	PrintCross(dy, dx);
//	//PrintCrossDFS(dy, dx);
//
//	if (IsCheck() == 0)
//	{
//		if (max < cnt)
//		{
//			max = cnt;
//		}
//		//버퍼를 초기화
//
//		buffer[dy][dx] = 0;
//		cnt--;
//		
//
//		return;
//	}
//
//	for (int y = 0; y < 4; y++)
//	{
//		for (int x = 0; x < 4; x++)
//		{
//			if (buffer[y][x] == 0)
//			{
//				DFS(level + 1,  y,  x);
//				//history[dy][dx] = 0;
//			}
//			//history[y][x] = 0;
//		}
//
//
//	}
//
//	buffer[dy][dx] = 0;
//	DeleteCross(dy, dx);
//	cnt--;
//
//}
//
//
//int main()
//{
//	DFS(0, 0, 0);
//
//
//	return 0;
//}
//
//
//
////
////int data[10] = { 0 };
////
////
////
////int DNum(int num)
////{
////	int sum = 0;
////	int divide = 1000;
////	int dNum = 0;
////	int idx = 0;
////
////
////	data[idx] = num;
////	idx++;
////	while (true)
////	{
////		if (num < 10)
////		{
////			data[idx] = num;
////			break;
////		}
////
////
////
////		dNum = num / divide;
////
////		if (dNum  != 0)
////		{
////			data[idx] = dNum;
////			idx++;
////
////			num -= dNum * divide;
////
////			divide /= 10;
////			dNum = 0;
////		}
////		else
////		{
////			divide /= 10;
////		}
////
////	}
////
////	for (int i = 0; i < 10; i++)
////	{
////		sum += data[i];
////	}
////
////
////
////	return sum;
////}
////
////
////
////int main()
////{
////	int inputNum = 91;
////
////	DNum(inputNum);
////
////
////
////	return 0;
////} // 1번문제