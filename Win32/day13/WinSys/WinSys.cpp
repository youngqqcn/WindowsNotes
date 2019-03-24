// WinSys.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "windows.h"


void ShowSys()
{
	SYSTEM_INFO info = {0};
	GetSystemInfo(&info);

	printf("内存页的大小:%d\n", info.dwPageSize);
	printf("可用的最小内存:%d\n", info.lpMinimumApplicationAddress);
	printf("内存分配粒度:%d\n", info.dwAllocationGranularity);

}





int main(int argc, char* argv[])
{
	ShowSys();

	printf("Hello World!\n");
	return 0;
}

