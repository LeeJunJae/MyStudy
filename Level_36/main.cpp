#include <iostream>


int arr[6][6] =
{
	0,1,1,0,0,0,
	0,0,0,1,1,0,
	0,0,0,0,1,0,
	0,0,0,0,0,0,
	0,0,0,0,0,0,
	0,0,0,0,0,0,
};

char data[10] = { "ABCDEF" };
char history[4] = { 'A' };
char tree[20]; 

int idxX = 0;
int idxY = 0;


int sameCheck(int level);

void Recursion(int level)
{ 
	if (level == 2 )
	{
		for (int i = 0; i < 3; i++)
		{
			printf("%C", history[i]);
		}
		printf("\n");

		
		return;
	}

	

	for (int i = 0 ; i < 2; i++)
	{	
		
		for (int j = 0; j < 6; j++)
		{
			if (arr[idxY][j] == 1)
			{
				int temp = j;
				arr[idxY][j] = 0;
				idxY = temp;
				
				
				break;
			}				
		}

		
		history[level + 1] = 'A' + idxY;
		if (sameCheck(level) == 1)
		{
			return;
		}
		
		
		Recursion(level + 1);			
		history[level + 1] = NULL;			
		idxY = history[level] - 'A';	
		
	}

}

int sameCheck(int level)
{

	for (int j = 0; j < level+1; j++)
	{
		if (history[j] == history[j + 1])
		{
			return 1;
		}
	}

	return 0;

}

int main()
{
	Recursion(0);


	return 0;
}