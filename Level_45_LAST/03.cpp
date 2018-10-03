#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

char strA[10] = "ABCDE";
char strB[10] = "BBCDE";

char aSentence[4][3];
char bSentence[4][3];

void DivideSentence(char* data, char* dSentence)
{
	strcpy(dSentence, data);	
}


int main()
{
	for (int i = 0; i < strlen(strA) - 1; i++)
	{		
		DivideSentence(aSentence[i], strA);
	}
	

	return 0;
}