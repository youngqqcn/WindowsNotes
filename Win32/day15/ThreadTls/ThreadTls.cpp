// ThreadTls.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "stdio.h"
#include "stdlib.h"
#include <windows.h>

//__declspec(thread) char *g_pszText = NULL;   //每个线程单独有一个

char *g_pszText = NULL; //多个线程共用一个, 会导致后来者覆盖前面的内容 



//定义索引号
DWORD g_iTlsIndex = 0;



void Print()
{
//	printf("%s\n", g_pszText);

	//3.从TLS索引中获取值
	CHAR *pszText = (CHAR *)TlsGetValue(g_iTlsIndex);
	printf("Tls: %s\n", pszText);
}

DWORD WINAPI ThreadProc(LPVOID lParam)
{
	char *pszText = (char *)lParam;
	g_pszText = (CHAR *)malloc(strlen(pszText) + 1);
	memset(g_pszText, 0, strlen(pszText) + 1);
	strcpy(g_pszText, (CHAR *)lParam);


	//2.将值保存到TLS索引当中
	TlsSetValue(g_iTlsIndex, g_pszText);

	while(1)
	{
		Print();
		Sleep(1000);
	}
}

void Create()
{
	HANDLE hThread = NULL;
	DWORD iThreadID = 0;

	CHAR szText[]  = "Thread Proc1---------";

	hThread = CreateThread(NULL, 0, ThreadProc, szText, 0, &iThreadID);
	

	CHAR szText2[]  = "Thread Proc2---------";
	HANDLE hThread2 = CreateThread(NULL, 0, ThreadProc, szText2, 0, &iThreadID);
	WaitForSingleObject(hThread, INFINITE);
	WaitForSingleObject(hThread2, INFINITE);
}



int main(int argc, char* argv[])
{

	//1.创建TLS创建索引号
	g_iTlsIndex = TlsAlloc();

	Create();

	//释放索引号
	TlsFree(g_iTlsIndex);
	printf("Hello World!\n");
	return 0;
}

