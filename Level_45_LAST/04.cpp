//#include <stdio.h>
//#include <string.h>
//
//
//int num[4] = { 2,6,4,5 };
//char str[5] = "+-*/";
//int result = 0;
//int history[10];
//
//char resultArr[10];
//
//void DFS(int level)
//{
//
//	if (level == 4)
//	{
//		for (int i = 0; i < 4; i++)
//		{
//				switch (history[i])
//				{
//				case '+':
//					result += num[i];
//					break;
//
//				case '-':
//					result -= num[i];
//					break;
//
//				case '*':
//					result *= num[i];
//					break;
//
//				case '/':
//					result /= num[i];
//					break;				
//				}
//		}
//		printf("\n");
//
//		// 우선순위 만드는중 
//		//for (int i = 0; i < 4; i++)
//		//{
//		//	resultArr[2 * i] = num[i] + 48;
//		//	resultArr[1 + 2 * i] = history[i];
//		//}
//
//		//int resultOp = 0;
//		//char operatorfirst[5] = "*/+-";
//		//for (int i = 0; i < 4; i++)
//		//{
//		//	for (int j = 1; j < 8; j++)
//		//	{
//		//		resultOp = resultArr[0];
//		//		if (operatorfirst[i] == resultArr[j])
//		//		{
//		//			resultOp = resultArr[j - 1];
//
//		//				switch (resultArr[j])
//		//				{
//		//				case '+':
//		//					resultOp = resultArr[j-1] + resultArr[j + 1];
//
//		//					resultArr[j - 1] = resultOp;
//		//					resultArr[j ] = 0;
//		//					resultArr[j + 1] = resultOp;
//		//					break;
//
//		//				case '-':
//		//					resultOp = resultArr[j - 1] - resultArr[j + 1];
//		//					break;
//
//		//				case '*':
//		//					resultOp = resultArr[j - 1] * resultArr[j + 1];
//		//					break;
//
//		//				case '/':
//		//					resultOp = resultArr[j - 1] / resultArr[j + 1];;
//		//					break;
//		//				}
//		//		}
//		//	}
//		//}
//
//
//		return;
//	}
//
//	
//	
//
//
//	for (int i = 0; i < 4; i++)
//	{
//		history[level] = str[i];
//		DFS(level + 1);
//		history[level] = '\0';
//	}
//
//}
//
//
//int main()
//{
//	
//	DFS(0);
//
//
//	return 0;
//}
//
