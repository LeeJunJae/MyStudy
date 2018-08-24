//#include <stdio.h>
//
//
//int data[4][4] =
//{
//	1,1,0,1,
//	1,1,0,1,
//	0,0,1,0,
//	0,0,0,1,
//};
//
//int AllSame(int startY, int startX, int endY, int endX)
//{
//	int startNum = data[startY][startX];
//		
//
//	for (int y = startY; y < endY; y++)
//	{
//		for (int x = startX ; x < endX; x++)
//		{
//			if (startNum != data[y][x])
//			{
//				return -1;
//			}
//		}
//	}
//
//	if (startNum == 1)
//	{
//		return 1;
//	}
//	else
//	{
//		return 0;
//	}
//
//}
//
//
//void BBQ(int level, int startY, int startX, int endY, int endX)
//{
//
//	if (AllSame(startY, startX, endY, endX ) == 1)
//	{
//		printf("1");
//		return;
//	}
//
//	if (AllSame(startY, startX, endY, endX) == 0)
//	{
//		printf("0");
//		return;
//	}
//
//	if (AllSame(startY, startX, endY, endX) == -1)
//	{
//		
//		BBQ(level+1, startY, startX, endY/2, endX/2	);
//
//		BBQ(level+1, startY, (startX+1)*2, endY/2 , endX );
//		
//		BBQ(level+1, startY+2, startX, endY , endX/2 );
//
//		BBQ(level+1, startY+2, startX+2, endY , endX );
//		
//		
//	}
//}

//int main()
//{
//	BBQ(0, 0, 0, 3, 3);
//
//
//	return 0;
//}
