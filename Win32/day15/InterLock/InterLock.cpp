// InterLock.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdlib.h>
#include "windows.h"

LONG  g_iValue1 = 0;
LONG  g_iValue2 = 0;

DWORD WINAPI InterProc1(LPVOID lParam)
{
	for (long int i = 0; i < 20000000; i++)
	{
		g_iValue1++;
	}
	return 0;
}

DWORD WINAPI InterProc2(LPVOID lParam)
{
	for (long int i = 0; i < 20000000; i++)
	{
		//g_iValue2++;
		InterlockedIncrement(&g_iValue2); //使用原子锁的加法运算
	}
	return 0;
}


void Create()
{
	DWORD iThreadId = 0;
	//使用一个 proc 函数, 为什么每次都可以??
	HANDLE hThread1 = CreateThread(NULL, 0, InterProc1, NULL, 0, &iThreadId);
	HANDLE hThread2 = CreateThread(NULL, 0, InterProc1, NULL, 0, &iThreadId);
	HANDLE hThread3 = CreateThread(NULL, 0, InterProc2, NULL, 0, &iThreadId);
	HANDLE hThread4 = CreateThread(NULL, 0, InterProc2, NULL, 0, &iThreadId);

	HANDLE hArray[] = { hThread1, hThread2, hThread3, hThread4 };
	WaitForMultipleObjects(sizeof(hArray)/4, hArray, TRUE, INFINITE);

	printf("%d\n", g_iValue1);
	printf("%d\n", g_iValue2);

	return;
}



int main(int argc, char* argv[])
{
	Create();
	system("pause");
	return 0;
}

