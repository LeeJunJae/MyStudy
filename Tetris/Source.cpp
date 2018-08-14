#include "header.h";

int main()
{
	while (true)
	{
		system("cls");
		PrintAll();


		mapInit();
		if (GetAsyncKeyState(VK_UP) & 0x8101)
		{

			RightSpinBlock();
			//IsStack검사
			//만약 중복이 RightSpinBlock() 3번 더 호출
			//만약 종복이 없으면 PrintAll();

		}
		if (GetAsyncKeyState(VK_DOWN) & 0x8101)
		{			
			dY++;
		}
		if (GetAsyncKeyState(VK_LEFT) & 0x8101)
		{
			if (IsStackWall(dY, dX - 1) == 0)
			{
				dX--;
			}
		}
		if (GetAsyncKeyState(VK_RIGHT) & 0x8101)
		{

			if (IsStackWall(dY, dX + 1) == 0)
			{
				dX++;
			}

		}
		Sleep(100);
	}

	return 0;
}
