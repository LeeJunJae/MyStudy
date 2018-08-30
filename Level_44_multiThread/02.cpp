//#include <stdio.h>
//#include <process.h>
//#include <Windows.h>
//
//
//int flag = 0;
//unsigned int _stdcall THREAD(void* arg)
//{
//	int num = 1;
//	int sum = 0;
//	while (num > 100000)
//	{
//		
//		sum += num;
//		num++;
//	}
//
//
//	printf("쓰레드 종료");
//	return 0;
//}
//
//
//int main()
//{
//	HANDLE hThread;
//	hThread = (HANDLE)_beginthreadex(0, 0, THREAD, 0, 0, 0);
//
//	int time = 0;
//	while (time < 5)
//	{
//		printf("#");
//		Sleep(100);
//		time++;
//	}
//
//	//WaitForSingleObject(hThread, INFINITE);
//	CloseHandle(hThread);
//
//	return 0;
//}