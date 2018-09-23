//#include <stdio.h>
//#include <string.h>
//
//
//
//char strA[20] = "ABCDE";
//char strB[20] = "BBCDE";
//
//char strAcopy[20];
//char strBcopy[20];
//
//void DivdeStr(char* str, char* dest)
//{
//	int idx = 0;
//	for (int i = 0; i < 10; i++)
//	{
//
//		for (int j = 0; j < 2; j++)
//		{
//			dest[idx++] = str[i+j];
//		}
//		
//	}
//
//
//}
//
//int IsSame(int idx)
//{
//	for (int i = 0; i < 2; i++)
//	{
//		if (strAcopy[idx + i] != strBcopy[idx + i])
//		{
//			return 0;
//		}
//	}
//
//	return 1;
//}
//
//int main()
//{
//	DivdeStr(strA, strAcopy);
//	DivdeStr(strB, strBcopy);
//
//	int same = 0;
//	
//
//	int idx = 0;
//
//	int len = strlen(strAcopy) / 2;
//	for (int i = 0; i < len; i++)
//	{
//		for(int j=0; j<2; j++)
//		{
//			if ( IsSame(idx) == 1)
//			{				
//				same++;
//				break;
//			}			
//						
//		}
//		idx += 2;
//	}
//
//	int sum = (2*len) - same;
//
//	float result;
//	result = (float)same / (float)sum;
//
//
//
//	return 0;
//}