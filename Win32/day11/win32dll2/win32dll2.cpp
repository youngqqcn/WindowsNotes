// win32dll2.cpp : Defines the entry point for the DLL application.
//

#include "stdafx.h"
#include "win32dll2.h"

BOOL APIENTRY DllMain( HANDLE hModule, 
                       DWORD  ul_reason_for_call, 
                       LPVOID lpReserved
					 )
{
    switch (ul_reason_for_call)
	{
		case DLL_PROCESS_ATTACH:
		case DLL_THREAD_ATTACH:
		case DLL_THREAD_DETACH:
		case DLL_PROCESS_DETACH:
			break;
    }
    return TRUE;
}


// This is an example of an exported variable
WIN32DLL2_API int nWin32dll2=0;

// This is an example of an exported function.
WIN32DLL2_API int fnWin32dll2(void)
{
	return 42;
}

// This is the constructor of a class that has been exported.
// see win32dll2.h for the class definition
CWin32dll2::CWin32dll2()
{ 
	return; 
}

