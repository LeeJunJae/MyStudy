#include <iostream>

int history[5];


void bbq(int level)
{
	if (level == 3)
	{
		for (int i = 0; i < 3; i++)
		{
			if (history[i] == 1)
			{
				printf("½Â");
			}
			else
			{
				printf("ÆÐ");
			}
		}
		printf("\n");
	}



	for (int i = 0; i < 2; i++)
	{
		history[level] = i;
		bbq(level + 1);
		history[level] = 0;
	}
}



int main()
{
	bbq(0);

	return 0;
}