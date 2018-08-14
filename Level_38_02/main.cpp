#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 



char str[30] = { "1+1+(5-1)-5+4+6+(5+1)" };

int check()
{
	for (int i = 0; i < 30; i++)
	{
		if (str[i] == 0)
		{
			break;
		}


		if (str[i] != '+' || str[i] != '-')
		{
			if ((str[i] / 1) < 10)
			{
				return 0;
			}

			if ((str[i] == '(' || str[i] == ')') && (str[i + 1] == '(' || str[i + 1] == ')'))
			{
				return 0;
			}

			if (str[i] == '(' )
			{
				if (str[i - 1] != '+')
				{
					return 0;
				}
			}
		}
	}

	return 1;
}

int main()
{
	if (check() == 1)
	{
		printf("pass");
	}


	return 0;
}