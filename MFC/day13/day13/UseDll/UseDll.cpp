// UseDll.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "../DllInterface/mymath.h"

typedef IMath *( *CREATEINSTANCE)();

IMath *CreateInst()
{
	//加载动态库
	HMODULE hDll = (HMODULE)LoadLibrary("DllInterface.dll");

	//获取创建接口的函数
	CREATEINSTANCE CreateInstance = (CREATEINSTANCE) GetProcAddress(hDll, "CreateInstance");
	
	//创建接口
	IMath *piMath = CreateInstance();

	return piMath;
}

int main(int argc, char* argv[])
{
	IMath *piMath = CreateInst();
	piMath->AddRef(); //增加引用计数

	printf("%d\n", piMath->Add(100, 100));

	piMath->Release(); //减少引用计数
	
	return 0;
}

