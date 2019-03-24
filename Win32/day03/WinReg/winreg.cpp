#include <windows.h>
#include <stdio.h>

HINSTANCE g_hInst  = NULL;

//
LRESULT CALLBACK WndProc(HWND hWnd, UINT nMsg, WPARAM wParam, LPARAM lParam)
{
	//OutputDebugString("hello");
	switch(nMsg)
	{
	case WM_DESTROY:
		PostQuitMessage(WM_QUIT);
		return 0;
	}

	return DefWindowProc(hWnd, nMsg, wParam, lParam);
}


//创建窗口
HWND CreateButton()
{
	HWND hWnd = CreateWindow("EDIT", "Button", WS_OVERLAPPEDWINDOW, 
		0, 0, 500, 500, NULL, NULL, g_hInst, NULL);


	return hWnd;
}


//显示窗口
void DisplayWnd(HWND hWnd)
{
	ShowWindow(hWnd, SW_SHOW);
	UpdateWindow(hWnd);
}


//消息循环
void Message()
{
	MSG msg = {0};
	while(GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
}


/*
typedef struct {
    UINT cbSize;         //结构体的大小
    UINT style;
    WNDPROC lpfnWndProc;
    int cbClsExtra;
    int cbWndExtra;
    HINSTANCE hInstance;
    HICON hIcon;
    HCURSOR hCursor;
    HBRUSH hbrBackground;
    LPCTSTR lpszMenuName;
    LPCTSTR lpszClassName;
    HICON hIconSm;       //小图标
} WNDCLASSEX, *PWNDCLASSEX;

style参数:
	CS_HREDRAW   窗口水平水平变化, 重新绘制窗口
	CS_VREDRAW     窗口垂直水平变化, 重新绘制窗口
	CS_GLOBALCLASS  创建应用程序全局窗口类
	CS_DBLCLKS    窗口可以接收鼠标双击消息
	CS_CLASSDC   所有这种类型的窗口使用同一个DC绘图
	CS_OWNDC     每个窗口有自己的DC
	CS_PARENTDC   使用父窗口的DC
	CS_NOCLOSE   禁用关闭命令

cbClsExtra参数:
	cbClsExtra用于在窗口类中添加信息的内存的大小
	DWORD SetClassLong(   HWND hWnd,   int nIndex,   LONG dwNewLong);  //将信息保存到内存中
	DWORD GetClassLong(   HWND hWnd,   int nIndex); //将信息从内存中获取

cbWndExtra参数:
	在窗口的数据信息中添加自己的信息
	LONG SetWindowLong(   HWND hWnd,   int nIndex,   LONG dwNewLong);  
	LONG GetWindowLong(   HWND hWnd,   int nIndex); 



窗口类的相关函数:

//注册窗口类
ATOM RegisterClassEx(CONST WNDCLASSEX *lpwcx);

//注销窗口类
BOOL UnregisterClass(   LPCTSTR lpClassName,   HINSTANCE hInstance); 

//获取注册信息
 BOOL GetClassInfoEx(
	HINSTANCE hinst,
    LPCTSTR lpszClass,
    LPWNDCLASSEX lpwcx
);



创建窗口是如何定位窗口类:
   1.查找应用程序局部的窗口类
   2.如果找到名称一致的窗口类, 会比较HINSTANCE句柄
          如果一致:就使用找到的窗口类信息创建窗口信息
		  如果不同, 继续查找
   3.如果未找到名称一致的窗口类, 会继续在应用程序全局窗口类中查找
          如果找到: 直接创建窗口
		  如果未找到: 去系统全局窗口类中查找, 如果找到,则创建窗口; 如果未找到,返回失败.

 
  查找顺序: 应用局部窗口类-->应用程序全局类-->系统全局窗口类



创建窗口相关函数:
HWND CreateWindow(   
	LPCTSTR lpClassName,   
	LPCTSTR lpWindowName, 
	DWORD dwStyle,   
	int x,   
	int y,   
	int nWidth,   
	int nHeight, 
	HWND hWndParent,  
	HMENU hMenu,   
	HANDLE hInstance,   
	PVOID lpParam ); 

HWND CreateWindowEx(  
		DWORD dwExStyle,  
		LPCTSTR lpClassName, 
		LPCTSTR lpWindowName,   
		DWORD dwStyle,   
		int x,  
		int y,   
		int nWidth, 
		int nHeight,   
		HWND hWndParent,  
		HMENU hMenu,  
		HINSTANCE hInstance, 
		LPVOID lpParam ); 




*/


BOOL RegisterWnd(LPSTR pszClassName)
{
	WNDCLASSEX wce = {0};
	wce.cbSize		= sizeof(wce);
	wce.style		= CS_HREDRAW | CS_VREDRAW;   //CS_GLOBALCLASS全局
	wce.lpfnWndProc	= WndProc;
	wce.cbClsExtra	= 100;    //保存窗口类信息
	wce.cbWndExtra	= 100;     //存窗口的信息
	wce.hCursor		= NULL;
	wce.hIcon		= NULL;
	wce.hbrBackground = HBRUSH(COLOR_BTNFACE + 1);
	wce.lpszClassName = pszClassName;
	wce.hInstance		= g_hInst;

	ATOM nAtom =   RegisterClassEx(&wce); 
	if(0 == nAtom)
		return FALSE;
	
	return TRUE;
}


//设置附加信息
void SetExtra(HWND hWnd)
{
	SetClassLong(hWnd, 0, 100);
	SetWindowLong(hWnd, 0, 200);
}


void GetExtra(HWND hWnd)
{
	DWORD nClss = GetClassLong(hWnd, 0);
	DWORD nWnd = GetWindowLong(hWnd, 0);


	CHAR szText[1024] = {0};
	sprintf(szText, "%d   %d", nClss, nWnd);

	MessageBox(hWnd, szText, "tip", MB_OK);
}



HWND CreateWnd(LPSTR pszClassName)
{

	HWND hWnd = CreateWindow(pszClassName, "MyWnd", WS_OVERLAPPEDWINDOW, 0, 0, 
		1000, 500, NULL, NULL, g_hInst, NULL);
	return hWnd;
}


int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR pszCmdLine, int nShowCmd)
{
	g_hInst = hInst;
	//HWND hWnd =  CreateButton();
	//DisplayWnd(hWnd);


	RegisterWnd("MyWnd1");
	HWND hMyWnd1 = CreateWnd("MyWnd1");
	HWND hMyWnd2 = CreateWnd("MyWnd1");
	SetExtra(hMyWnd1);
	GetExtra(hMyWnd1);

	//SetExtra(hMyWnd2);
	GetExtra(hMyWnd2);

	DisplayWnd(hMyWnd1);
	Message();

	return 0;
}