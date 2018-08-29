#include <stdio.h>
#include <process.h>
#include <Windows.h>

unsigned int _stdcall THREAD(void* arg)
{
	while (true)
	{
		printf("@");
	}
}


int main()
{
	HANDLE hThread;
	hThread = (HANDLE)_beginthreadex(0, 0, THREAD, 0, 0, 0);

	while (true)
	{
		printf("0");
	}

	//WaitForSingleObject(hThread, INFINITE);
	CloseHandle(hThread);

	return 0;
}