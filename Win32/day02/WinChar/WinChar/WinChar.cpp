// WinChar.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include <stdlib.h>


void Wide2Multi()
{
	WCHAR *pwszText = L"wide2multi";
	int iLen = WideCharToMultiByte(CP_ACP, 0, pwszText, wcslen(pwszText), NULL, 0, NULL, NULL);

	char *pszText = (char *)malloc(iLen);

	WideCharToMultiByte(CP_ACP, 0, pwszText, wcslen(pwszText), pszText, iLen, NULL, NULL);


	MessageBoxA(NULL, pszText, "Multi", MB_OK);

	free(pszText);
}



void Multi2Wide()
{
	CHAR *pszText = "Multi2Wide";
	
	//1.先获取转换后的长度
	int iLen = MultiByteToWideChar(CP_ACP/*ascii code page*/, 0, pszText, strlen(pszText), NULL/* 返回结果*/, 0 );
	WCHAR *pwszText  = (WCHAR *)malloc(iLen * sizeof(WCHAR));
	memset(pwszText, 0, sizeof(pwszText));
	//2.然后才获取返回植
	MultiByteToWideChar(CP_ACP/*ascii code page*/, 0, pszText, strlen(pszText), pwszText/* 返回结果*/, iLen);
	

	MessageBoxW(NULL, pwszText, L"Wide", MB_OK);
	free(pwszText);
}



int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow)
{
 	// TODO: Place code here.
	Multi2Wide();
	//Wide2Multi();
	return 0;
}



