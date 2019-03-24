#ifndef _MATH_H_
#define _MATH_H_


#include "windows.h"
#include "stdio.h"


//export class  by  macro 

#ifdef _DLL_CLASS_DLL_   //this macro was defined in  "project Preprocessor"
#define DLLCLASS_EXT __declspec(dllexport) 
#else
#define DLLCLASS_EXT __declspec(dllimport) 
#endif //_DLL_CLASS_DLL_

BOOL WINAPI DllMain(
   HINSTANCE hinstDLL, // 指向自身的句柄
   DWORD fdwReason, // 调用原因
   LPVOID lpvReserved // 隐式加载和显式加载
)
{
	printf("fdsfd\n");
	return TRUE;
}

class  DLLCLASS_EXT CMath
{
public:
	int  Add(int a, int b);
};

#endif
