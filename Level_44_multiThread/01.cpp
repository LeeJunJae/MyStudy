//#include <stdio.h>
//#include <process.h>
//#include <Windows.h>
//
//unsigned int _stdcall FIRSTTHREAD(void* arg)
//{
//	while (true)
//	{
//		printf("\n########\n");
//		Sleep(100);
//	}
//}
//
//unsigned int _stdcall SECONDTHREAD(void* arg)
//{
//	while (true)
//	{
//		printf("\n@@@@@@@@\n");
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
//		for (int i = 0; i < 26; i++)
//		{
//			printf("%C+", 'A' + i);
//		}
//	}
//
//	//WaitForSingleObject(hThread, INFINITE);
//	CloseHandle(FirsThread);
//	CloseHandle(SecondThread);
//
//	return 0;
//}