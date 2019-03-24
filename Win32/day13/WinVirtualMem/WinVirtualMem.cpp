// WinVirtualMem.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "windows.h"
#include "conio.h"
#include "stdlib.h"

void Status()
{
	MEMORYSTATUS status = {0};
	status.dwLength = sizeof(status);
	GlobalMemoryStatus(&status);
	
	//printf();
}



void Virtual()
{
	char *pmem =(char *)	VirtualAlloc(NULL, 1024*1024*1024, MEM_RESERVE   , PAGE_READWRITE);
	//char *pmem =(char *)malloc(1024 * 1024 * 1024);
	if(pmem)
	{
		
		//memset(pmem, 0, 1024*1024*1024);
		pmem =(char *)	VirtualAlloc(pmem, 1024*1024*1024, MEM_COMMIT   , PAGE_READWRITE);
		if(pmem)
		{
			printf("内存分配成功!\n");
			memset(pmem, 0, 1024 * 1024 * 1024);
		}
	}
	Status();
	getch();
	VirtualFree(pmem, 1024*1024*1024, MEM_RELEASE);
	if(pmem) free(pmem);
}



int main(int argc, char* argv[])
{
	Virtual();
	// Status();
	printf("Hello World!\n");
	return 0;
}

