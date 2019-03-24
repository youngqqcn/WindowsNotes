// ProcInfo.cpp : Defines the entry point for the console application.
//
//2018-09-02  yqq  
//win32学习 之  进程 

#include "stdafx.h"
#include "windows.h"





void EnvString()
{
	//获取所有环境信息
	LPSTR pszEnv = (LPSTR)GetEnvironmentStrings();
	LPSTR pszTmp = pszEnv;
	while(pszTmp[0])
	{
		printf("%s\n", pszTmp);
		pszTmp += strlen(pszTmp) + 1 ;
	}

	//释放环境信息字符串
	FreeEnvironmentStrings(pszEnv);
}


void EnvVar(char *pszVarName)
{
	//设置环境变量的值
	SetEnvironmentVariable(pszVarName, "C:\\");
	char szValue[1024] = {0};
	GetEnvironmentVariable(pszVarName, szValue, sizeof(szValue));
	printf("%s\n", szValue);

}







int main(int argc, char* argv[])
{
	//EnvString();
	EnvVar("MYQQQQQ");
	printf("Hello World!\n");
	return 0;
}

