//#include <stdio.h>
//
//int data[7] = { 4,1,2,6,7,3,5 };
//
//int pivot = data[0];
//
//int Cycle(int start, int end)
//{
//	int a, b;
//	int p = start;
//	int temp;
//
//	a = start + 1;
//	b = end;
//
//	while (1)
//	{
//		for (; a <= end; a++)
//		{
//			if (data[a] > data[p])
//				break;
//		}
//
//		for (; b >= start + 1; b--)
//		{
//			if (data[b] < data[p])
//				break;
//		}
//
//		if (a >= b)
//			break;
//		else
//		{
//			temp = data[a];
//			data[a] = data[b];
//			data[b] = temp;
//		}
//	}
//
//	temp = data[p];
//	data[p] = data[b];
//	data[b] = temp;
//
//	return b;
//}
//
//void Quick(int level, int start, int end)
//{
//	if (start >= end)
//	{
//		return;
//	}
//
//	if (end - start == 1)
//	{
//		int temp;
//		if (data[start] > data[end])
//		{
//			temp = data[start];
//			data[start] = data[end];
//			data[end] = temp;
//
//			return;
//		}
//	}
//
//
//	int p = Cycle(start, end);
//
//	Quick(level + 1, start, p - 1);
//	Quick(level + 1, p + 1, end);
//}
//
//int main()
//{
//	Quick(0, 0, 6);
//
//	return 0;
//}