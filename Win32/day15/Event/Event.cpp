// Event.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "windows.h"
#include "conio.h"

HANDLE g_hEvent = NULL;


DWORD WINAPI ThreadSend(LPVOID pParam)
{
	while(1)
	{
		SetEvent(g_hEvent); //触发事件
		Sleep(1000);
		
	}
	return 0;
}



DWORD WINAPI ThreadRecv(LPVOID pParam)
{
	while(1)
	{

		//等候事件
		
		WaitForSingleObject(g_hEvent, INFINITE);
		printf("收到事件: %p\n", g_hEvent);
		ResetEvent(g_hEvent);
	}
	return 0;
}

void Create()
{
	DWORD iThreadId = 0;
	HANDLE hThreads[2] = {NULL};

	hThreads[1] = CreateThread(NULL, 0, ThreadRecv, NULL, 0, &iThreadId);
	hThreads[0] = CreateThread(NULL, 0, ThreadSend, NULL, 0, &iThreadId);

	WaitForMultipleObjects(2 , hThreads, TRUE,  INFINITE);

}




int main(int argc, char* argv[])
{
	g_hEvent = CreateEvent(NULL, TRUE, FALSE, NULL);
	ResetEvent(g_hEvent);


	Create();
	//printf("Hello World!\n");


	CloseHandle(g_hEvent);

	//getch();
	return 0;
}

