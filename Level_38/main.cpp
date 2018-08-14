#include <iostream>


int map[4][4] =
{
	0,1,0,2,
	0,1,0,1,
	0,1,0,1,
	0,0,0,1,
};

int direct[4][2] = 
{
	0,1,
	0,-1,
	1,0,
	-1,0,
};


int Possible(int dy, int dx)
{
	if (dy < 0 || dy >= 4 || dx < 0 || dx >= 4)
		return 0;
	if (map[dy][dx] == 1)
		return 0;


	return 1;
}


void DFS(int level, int nowY,int nowX)
{
	if (map[nowY][nowX] == 2)
	{
		printf("%d회의 이동만에 사과를 먹을수 있습니다.", level);

		return;
	}

	int dy, dx;
	map[nowY][nowX] = 1;


	for (int i = 0; i < 4; i++)
	{
		dy = direct[i][0] + nowY;
		dx = direct[i][1] + nowX;


		if (Possible(dy, dx) == 1)
		{
			DFS(level + 1, dy, dx);
		}
	}


}

int main()
{
	DFS(0, 0, 0);


	return 0;
}