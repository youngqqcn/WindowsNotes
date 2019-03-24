// WinCreate.cpp : 定义应用程序的入口点。
//

#include "stdafx.h"
#include "resource.h"

HINSTANCE g_hInst = NULL;


//父窗口的处理函数
LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lPrama)
{
	switch (uMsg)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	default:
		break;
	}
	return DefWindowProc(hWnd, uMsg, wParam, lPrama);
}


LRESULT CALLBACK ChildProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lPrama)
{
	switch (uMsg)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	default:
		break;
	}
	return DefWindowProc(hWnd, uMsg, wParam, lPrama);
}

BOOL RegisterWnd(LPSTR pszClassName, WNDPROC proc, int uBrush)
{
	WNDCLASSEX wce = { 0 };
	wce.cbSize = sizeof(wce);
	wce.style = CS_HREDRAW | CS_VREDRAW;
	wce.cbClsExtra = 0;
	wce.cbWndExtra = 0;
	wce.lpfnWndProc = proc;
	wce.hCursor = NULL;
	wce.hIcon = NULL;
	wce.hbrBackground = HBRUSH(uBrush);
	wce.hInstance = g_hInst;
	wce.lpszClassName = pszClassName;
	wce.lpszMenuName = NULL;
	wce.hIconSm = NULL;

	ATOM uAtom = RegisterClassEx(&wce);
	if (0 != uAtom)
		return TRUE;
	return FALSE;
}


BOOL RegisterWnd(LPSTR pszClassName)
{
	WNDCLASSEX wce = { 0 };
	wce.cbSize = sizeof(wce);
	wce.style = CS_HREDRAW | CS_VREDRAW;
	wce.cbClsExtra = 0;
	wce.cbWndExtra = 0;
	wce.lpfnWndProc = WndProc;
	wce.hCursor = NULL;
	wce.hIcon = NULL;
	wce.hbrBackground = HBRUSH(COLOR_WINDOW);
	wce.hInstance = g_hInst;
	wce.lpszClassName = pszClassName;
	wce.lpszMenuName = NULL;
	wce.hIconSm = NULL;

	ATOM uAtom = RegisterClassEx(&wce);
	if (0 != uAtom)
		return TRUE;
	return FALSE;
}


//创建窗口
HWND CreateWnd(LPSTR pszClassName)
{
	HMENU hMenu = LoadMenu(g_hInst, MAKEINTRESOURCE(IDR_MAIN));
	HWND hWnd = CreateWindow(
		pszClassName, 
		"MyWnd", 
		WS_OVERLAPPEDWINDOW, 
		CW_USEDEFAULT, CW_USEDEFAULT, 
		CW_USEDEFAULT, CW_USEDEFAULT,
		NULL, hMenu, g_hInst, NULL
	);

	return hWnd;
}




void DisplayWnd(HWND hWnd)
{
	ShowWindow(hWnd, SW_SHOW);
	UpdateWindow(hWnd);
}

void Message()
{
	MSG msg = { 0 };
	while (GetMessage(&msg, NULL, 0, 0))
	{
		DispatchMessage(&msg);
	}
}


int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow)
{
	g_hInst = hInstance;

	//父窗口
	RegisterWnd("MyWnd", WndProc, COLOR_BTNFACE + 1);
	HWND  hWnd = CreateWnd("MyWnd");
	
	MoveWindow(hWnd, 50, 50, 300, 500, TRUE);

	DisplayWnd(hWnd);
	Message();
   
	return 0;
}

