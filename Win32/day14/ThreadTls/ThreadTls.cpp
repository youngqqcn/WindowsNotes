// ThreadTls.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "windows.h"
#include <stdio.h>
#include <stdlib.h>

//CHAR *g_pszText = NULL;   //会被覆盖

__declspec(thread) CHAR *g_pszText = NULL;  //每个线程都有一个 g_pszText



void Print()
{
	printf("%s\n", g_pszText);
}


DWORD WINAPI  PrintProc(LPVOID pParam)
{
	CHAR *pszText = (CHAR *)pParam;
	g_pszText = (CHAR *)malloc(100);
	memset(g_pszText, 0, 100);

	strcpy(g_pszText, pszText);


	while(1)
	{
		Print();
		Sleep(1000);
	}

	if(g_pszText)
		free(g_pszText);
}

void Create()
{
	CHAR szText[] = "thead1...........";
	DWORD dwThreadID = 0;

	HANDLE hThread1 = CreateThread(NULL, 0, PrintProc, szText, 0, &dwThreadID);


	CHAR szText2[] = "-----thread2-------";
	HANDLE hThread2 = CreateThread(NULL, 0, PrintProc, szText2, 0, &dwThreadID);


	CHAR szText3[] = "-----thread3-------";
	HANDLE hThread3 = CreateThread(NULL, 0, PrintProc, szText3, 0, &dwThreadID);




	system("pause"); //注意	
}


int main(int argc, char* argv[])
{
	Create();

	//system("pause");  //注意

	printf("Hello World!\n");
	return 0;
}

