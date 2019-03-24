// WaitableTimer.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


#define _WIN32_WINNT 0x0400   //版本

#include "windows.h"
HANDLE g_hTimer = NULL;


DWORD WINAPI TimerProc(LPVOID pParam)
{
	while(1)
	{
		WaitForSingleObject(g_hTimer, INFINITE);
		printf("hello world\n");
	}
	return 0;
}



void Create()
{
	//创建定时器
	g_hTimer = CreateWaitableTimer(NULL, FALSE, NULL);
	

	//设置定时器
	UINT64 uDueTime = -50000000;
	SetWaitableTimer(g_hTimer, (PLARGE_INTEGER)&uDueTime, 1000, NULL, NULL, FALSE);


	DWORD dwThreadID = 0;
	HANDLE hThread = CreateThread(NULL, 0, TimerProc, NULL, 0, &dwThreadID);


	WaitForSingleObject(hThread, INFINITE);
	//关闭定时器
	CloseHandle(g_hTimer);
}




int main(int argc, char* argv[])
{
	Create();

	printf("Hello World!\n");
	return 0;
}

