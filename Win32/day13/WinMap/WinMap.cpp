// WinMap.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "windows.h"


void Map()
{
	//创建文件
	HANDLE hFile = CreateFile("C:\\VC\\day13\\map.dat", GENERIC_READ|GENERIC_WRITE,
		0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);

	//创建文件映射
	HANDLE hMap = CreateFileMapping(hFile, NULL, 
		PAGE_READWRITE, 0, 1024 * 1024, NULL);


	//映射地址
	char *pszText = (char *)MapViewOfFile(hMap, FILE_MAP_ALL_ACCESS,  0, 0, 1024 * 1024);


	strcpy(pszText, "hello world hahahha I'm happy!\n");
	printf("%s\n", pszText);


	//卸载映射地址
	UnmapViewOfFile(pszText);



	//关闭文件映射 
	CloseHandle(hMap);

	
	//关闭文件
	CloseHandle(hFile);
}



int main(int argc, char* argv[])
{
	Map();
	printf("Hello World!\n");
	return 0;
}

