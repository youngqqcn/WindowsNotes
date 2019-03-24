// ThreadBase.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "windows.h"
#include "stdlib.h"

//线程处理函数
DWORD  WINAPI ThreadProc1(LPVOID pParam)
{
	for(int i = 0; i < 5; i++)
	{	
		printf("Thread Proc%d %d\n", (DWORD)pParam / 100, (DWORD)pParam);
		Sleep(1000);
	}

	return 0;
}


void Create()
{
	//创建线程
	DWORD iThreadID;
	DWORD iValue1 = 100;
	DWORD iValue2 = 200;
	HANDLE hThead = CreateThread(NULL, 0, ThreadProc1, LPVOID(iValue1), 0, &iThreadID);
		
	WaitForSingleObject(hThead, INFINITE); //等待线程结束
	CloseHandle(hThead);

	HANDLE hThead2 = CreateThread(NULL, 0, ThreadProc1, LPVOID(iValue2), 0, &iThreadID);
	//HANDLE hThead2= CreateThread(NULL, 0, ThreadProc1, LPVOID(iValue2), CREATE_SUSPENDED, &iThreadID);



	//

}




int main(int argc, char* argv[])
{
	Create();
	system("pause");
	//printf("Hello World!\n");
	return 0;
}

