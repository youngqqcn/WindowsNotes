// WinVolumn.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdio.h"
#include "windows.h"
#include "string.h"
#include <stdlib.h>

void ShowVolumn()
{
	DWORD iDrives = GetLogicalDrives();
	char buf[1024] = {0};
	memset(buf, 0, sizeof(buf));
	itoa(iDrives, buf, 2);
	//printf("%02x\n", iDrives);
	printf("%s\n", buf);


	//»ñÈ¡ÅÌ·ûµÄ×Ö·û´®
	char szText[256] = {0};
	GetLogicalDriveStrings(260, szText);
	//printf("%s\n", szText);
	char *pszText = szText;
	while(pszText[0])
	{
		printf("Dirves:%s\n", pszText);
		pszText = strlen(pszText) + 1 + pszText;
	}
}




int main(int argc, char* argv[])
{
	ShowVolumn();
	printf("Hello World!\n");
	return 0;
}

