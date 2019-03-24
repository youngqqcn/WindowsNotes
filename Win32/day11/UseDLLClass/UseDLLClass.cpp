// UseDLLClass.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

//#pragma comment(lib, "../bin/dllclass.lib")

#include "CMath.h"

int main(int argc, char* argv[])
{
	//CMath math;
	//printf("%d\n", math.Add(100, 101));
	HANDLE hDll = LoadLibrary("../bin/dllclass.dll");

	printf("Hello World!\n");
	return 0;
}

