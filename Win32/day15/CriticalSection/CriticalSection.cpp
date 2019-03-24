// CriticalSection.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "windows.h"
#include "conio.h"

CRITICAL_SECTION  g_cs = {0};

void Print()
{
	EnterCriticalSection(&g_cs);
	printf("fdsfsdf........\n");
	LeaveCriticalSection(&g_cs);
}

DWORD WINAPI PrintProc(LPVOID pParam)
{
	while(1)
	{
		Print();
		Sleep(1);
	}
	return 0;
}


void Create()
{
	DWORD iThreadID = 0;
	HANDLE hThreads[2] = {0};

	hThreads[0] = CreateThread(NULL, 0, PrintProc, NULL, 0, &iThreadID);
	hThreads[1] = CreateThread(NULL, 0, PrintProc, NULL, 0, &iThreadID);

	WaitForMultipleObjects(2, hThreads, TRUE, INFINITE);
}



int main(int argc, char* argv[])
{
	InitializeCriticalSection(&g_cs);

	Create();
	printf("Hello World!\n");

	DeleteCriticalSection(&g_cs);
	return 0;
}

