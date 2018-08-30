//#include <stdio.h>
//#include <process.h>
//#include <Windows.h>
//
//unsigned int _stdcall FIRSTTHREAD(void* arg)
//{
//	while (true)
//	{
//		printf("1");
//		Sleep(100);
//	}
//}
//
//unsigned int _stdcall SECONDTHREAD(void* arg)
//{
//	while (true)
//	{
//		printf("2");
//		Sleep(100);
//	}
//}
//
//
//int main()
//{
//	HANDLE SecondThread;
//	SecondThread = (HANDLE)_beginthreadex(0, 0, FIRSTTHREAD, 0, 0, 0);
//
//	HANDLE FirsThread;
//	FirsThread = (HANDLE)_beginthreadex(0, 0, SECONDTHREAD, 0, 0, 0);
//
//	while (true)
//	{
//		printf("3");
//		Sleep(100);
//	}
//
//	//WaitForSingleObject(hThread, INFINITE);
//	CloseHandle(FirsThread);
//	CloseHandle(SecondThread);
//
//	return 0;
//}