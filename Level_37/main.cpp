#include <iostream>


int map[5][5] = {
	0,0,0,0,0,
	1,1,1,0,1,
	0,0,0,0,1,
	0,1,0,1,1,
	0,1,0,0,2,
};

int direct[4][2] = {
	0,-1,
	-1,0,
	0,1,
	1,0,
};

int IsPossible(int dy, int dx)
{
	if (dx < 0 || dx > 4 || dy < 0 || dy > 4) return 0;

	if (map[dy][dx] == 1) return 0;

	return 1;
}
void DFS(int level, int nowY, int nowX)
{
	if (map[nowY][nowX] == 2)
	{
		return;
	}



	int dx, dy;
	map[nowY][nowX] = 1;

	for (int i = 0; i < 4; i++)
	{		
		dy = direct[i][0] + nowY;
		dx = direct[i][1] + nowX;

		if (IsPossible(dy, dx) == 1)
		{
			DFS(level + 1, dy, dx);
		}
	}

}


int main()
{

	DFS(0, 0,0);

	return 0;
}