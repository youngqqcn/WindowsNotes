// Semaphore.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "windows.h"

HANDLE g_hSemaphore = NULL;


DWORD WINAPI ThreadSend(LPVOID pParam)
{
	while(1)
	{
		ReleaseSemaphore(g_hSemaphore, 5, NULL); //释放信号量
	}

}

DWORD WINAPI ThreadRecv(LPVOID pParam)
{
	while(1)
	{
		WaitForSingleObject(g_hSemaphore, INFINITE);
		printf("hahahahhah-------\n");
		Sleep(1000);
	}

	
	return 0;
}


void Create()
{
	DWORD iThreadID = 0;
	HANDLE hThreads[2] = {0};
	hThreads[0] = CreateThread(NULL, 0, ThreadSend, NULL, 0, &iThreadID);
	hThreads[1] = CreateThread(NULL, 0, ThreadRecv, NULL, 0, &iThreadID);


	WaitForMultipleObjects(2, hThreads, TRUE, INFINITE);
}






int main(int argc, char* argv[])
{
	g_hSemaphore= CreateSemaphore(NULL, 5, 10, NULL); //创建信号量

	
	Create(); //创建线程

	//ReleaseSemaphore(g_hSemaphore); //释放信号量

	CloseHandle(g_hSemaphore); //关闭信号量
	printf("Hello World!\n");
	return 0;
}

