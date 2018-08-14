#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>	// printf
#include <stdlib.h> // malloc, free
#include <conio.h>	//_getche();	


void DraqBuffer()
{
	FILE* fp;
	fp = fopen("sample.cpp", "r");
	char buffer[255] = { 0 };
	fseek(fp, 0, SEEK_END);

	int iTotalSize = ftell(fp);


	char* buffer = (char*)malloc(iTotalSize);
	fseek(fp, 0, SEEK_SET);

	
	

	fclose(fp);
}


void DrawText()
{
	FILE* fp;
	fp = fopen("sample.cpp", "r");
	char buffer[255] = { 0 };
	int iLine = 0;


	while (!feof(fp))
	{
		printf("%05d : ", ftell(fp));
		for (int i = 0; i < 10; i++)
		{
			buffer[i] = fgetc(fp);

			if (feof(fp))
			{
				break;
			}
		}



		for (int i = 0; i < 10; i++)
		{
			if (buffer[i] == '\t' || buffer[i] == '\r' || buffer[i] == '\n')
			{
				buffer[i] = '.';
			}

			printf("%c : ", buffer[i]);
		}
		//fgets(buffer, sizeof(char) * 255, fp);
		//printf("\n%s", buffer);
	    iLine++;
		if (iLine % 10 == 0)
		{
			printf("\n 아무키나 누르세요.");
			_getch();
		}

	}
	fclose(fp);
}

int main()
{
	DrawText();


	return 0;
}