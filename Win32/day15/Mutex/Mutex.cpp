// Mutex.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "windows.h"

HANDLE g_hMutex = NULL;

DWORD WINAPI ThreadProc1(LPVOID pParam)
{
	while(1)
	{
		//µÈºò»¥³âÁ¿
		WaitForSingleObject(g_hMutex, INFINITE);
		printf("ThreadProc1---------\n");
		Sleep(500);

		//ÊÍ·Å»¥³âÁ¿
		ReleaseMutex(g_hMutex);
	}
	return 0;
}

DWORD WINAPI ThreadProc2(LPVOID pParam)
{
	while(1)
	{
		//µÈºò»¥³âÁ¿
		WaitForSingleObject(g_hMutex, INFINITE);
		printf("ThreadProc2---------\n");
		Sleep(500);

		//ÊÍ·Å»¥³âÁ¿
		ReleaseMutex(g_hMutex);
	}
	return 0;
}


DWORD WINAPI ThreadProc3(LPVOID pParam)
{
	while(1)
	{
		//µÈºò»¥³âÁ¿
		WaitForSingleObject(g_hMutex, INFINITE);
		printf("ThreadProc3---------\n");
		Sleep(500);

		//ÊÍ·Å»¥³âÁ¿
		ReleaseMutex(g_hMutex);
	}
	return 0;
}



void Create()
{
	DWORD iThreadID = 0;
	HANDLE hThreads[3] = {NULL};
	hThreads[0] = CreateThread(NULL, 0, ThreadProc1, NULL, 0, &iThreadID);
	hThreads[1] = CreateThread(NULL, 0, ThreadProc2, NULL, 0, &iThreadID);
	hThreads[2] = CreateThread(NULL, 0, ThreadProc3, NULL, 0, &iThreadID);
//	hThreads[1] = CreateThread(NULL, 0, ThreadProc2, NULL, 0, &iThreadID);



	WaitForMultipleObjects(sizeof(hThreads)/sizeof(hThreads[0]), hThreads, TRUE, INFINITE);
}



int main(int argc, char* argv[])
{
	g_hMutex	= CreateMutex(NULL, FALSE, NULL);


	Create();
	//printf("Hello World!\n");

	CloseHandle(g_hMutex);
	return 0;
}

