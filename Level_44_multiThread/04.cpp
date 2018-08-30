#include <stdio.h>
#include <process.h>
#include <Windows.h>


int flag = 0;


unsigned int _stdcall THREAD1(void* arg)
{
	int time = 0;

	while (time < 3)
	{
		printf("%d", (rand() % 4) + 2);
		Sleep(1000);

		time++;
		printf("1¹ø");
	}

	return 0;
}

unsigned int _stdcall THREAD2(void* arg)
{
	int time = 0;

	while (time < 4)
	{
		printf("%d", (rand() % 15) + 5);
		Sleep(1000);

		time++;
		printf("2¹ø");
	}

	return 0;
}

unsigned int _stdcall THREAD3(void* arg)
{
	int time = 0;

	while (time < 5)
	{
		printf("%f", ((rand() % 8) + 2 ) * 0.1f );
		Sleep(500);

		time++;
		printf("3¹ø");
	}

	return 0;
}



unsigned int _stdcall THREAD(void* arg)
{
	HANDLE hThread1;
	hThread1 = (HANDLE)_beginthreadex(0, 0, THREAD1, 0, 0, 0);

	HANDLE hThread2;
	hThread2 = (HANDLE)_beginthreadex(0, 0, THREAD2, 0, 0, 0);

	HANDLE hThread3;
	hThread3 = (HANDLE)_beginthreadex(0, 0, THREAD3, 0, 0, 0);


	CloseHandle(hThread1);
	CloseHandle(hThread2);
	CloseHandle(hThread3);
	return 0;
}


int main()
{
	HANDLE hThread;
	hThread = (HANDLE)_beginthreadex(0, 0, THREAD, 0, 0, 0);

	
	while (true)
	{
		if (flag == 1)
			break;
	}

	//WaitForSingleObject(hThread, INFINITE);
	CloseHandle(hThread);

	return 0;
}