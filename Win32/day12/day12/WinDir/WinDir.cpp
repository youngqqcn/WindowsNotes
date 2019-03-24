// WinDir.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "windows.h"



void ShowDirectory()
{
	//获取windows 目录
	CHAR szWindow[MAX_PATH] = {0};
	GetWindowsDirectory(szWindow, MAX_PATH);
	printf("WindowsDirectory: %s\n", szWindow);

	//获取system目录
	CHAR szSystem[MAX_PATH] = {0};
	GetSystemDirectory(szSystem, MAX_PATH);
	printf("SystemDirectory: %s\n", szSystem);


	//获取临时文件目录
	CHAR szTemp[MAX_PATH] = {0};
	GetTempPath(MAX_PATH, szTemp);
	printf("szTempDirectory: %s\n", szTemp);


	//设置当前目录
	SetCurrentDirectory("C:\\");

	//获取当前目录
	CHAR szCur[MAX_PATH] = {0};
	GetCurrentDirectory(MAX_PATH, szCur);
	printf("CurDirectory: %s\n", szCur);

}







int main(int argc, char* argv[])
{
	ShowDirectory();
	printf("Hello World!\n");
	return 0;
}

