
// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the WIN32DLL2_EXPORTS
// symbol defined on the command line. this symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// WIN32DLL2_API functions as being imported from a DLL, wheras this DLL sees symbols
// defined with this macro as being exported.
#ifdef WIN32DLL2_EXPORTS
#define WIN32DLL2_API __declspec(dllexport)
#else
#define WIN32DLL2_API __declspec(dllimport)
#endif

// This class is exported from the win32dll2.dll
class WIN32DLL2_API CWin32dll2 {
public:
	CWin32dll2(void);
	// TODO: add your methods here.
};

extern WIN32DLL2_API int nWin32dll2;

WIN32DLL2_API int fnWin32dll2(void);

