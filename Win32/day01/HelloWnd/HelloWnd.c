#include <windows.h>

HINSTANCE g_hInstance;

//2.窗口处理函数， 当窗口处理消息事件时， 系统调用这个函数
LRESULT CALLBACK WndProc(
		HWND hWnd, //窗口的句柄
		UINT nMsg, //消息的ID号
		WPARAM wParam, //消息所对应的参数
		LPARAM lParam //消息所对应的参数
	)
{
	switch(nMsg)
	{
	case WM_DESTROY: //窗口销毁的消息
		PostQuitMessage(0); //发送退出消息
		return 0;
	break;
	}


	//调用缺省的消息处理函数
	return DefWindowProc(hWnd, nMsg, wParam, lParam);
}

//3. 注册窗口类型
BOOL MyRegister(LPSTR pszClassName)
{
	ATOM nAtom;
	WNDCLASS wc = {0};
	wc.style = CS_VREDRAW | CS_HREDRAW;
	wc.lpfnWndProc = WndProc;
	wc.cbClsExtra  = 0;
	wc.cbWndExtra =  0;
	wc.hInstance  = g_hInstance;
	wc.hIcon = NULL;
	wc.hCursor = NULL;
	wc.hbrBackground = (HBRUSH)(COLOR_BTNFACE);
	wc.lpszMenuName = NULL;
	wc.lpszClassName = pszClassName;

	
	nAtom =RegisterClass(&wc);	
	if(0 == nAtom)
	{
		MessageBox(NULL, "Register Failed", "Error", MB_OK | MB_ICONWARNING);
		return FALSE;
	}
	else
	{
		MessageBox(NULL, "Register Successed", "Successed", MB_OK);
	}

	return TRUE;
}

HWND MyCreate(LPSTR pszClassName)
{
	HWND hWnd = CreateWindow(pszClassName,
			"HelloWnd",
			WS_OVERLAPPEDWINDOW,
			100, 100, 300, 500, NULL, NULL,
			g_hInstance, NULL
			);
	if(NULL == hWnd)
	{
		MessageBox(NULL, "Create Window Failed", "Error", MB_OK | MB_ICONWARNING);
		return NULL;
	}
	else
	{
		MessageBox(NULL, "Create Window Successed", "Successed", MB_OK);
	}
	return hWnd;
}

void DisplayWnd(HWND hWnd)
{
	ShowWindow(hWnd, SW_SHOW);
	UpdateWindow(hWnd);
}


void Message()
{
	MSG msg = {0};
	while(GetMessage(&msg, NULL, 0, 0)) //从消息队列获取消息
	{
		DispatchMessage(&msg); //派发消息
	}
}


//1. 入口函数 
int WINAPI WinMain(HINSTANCE hInstance,
		HINSTANCE hPrevInstance,
		LPSTR pszCmdLine,
		int nCmdShow
	)
{
	HWND hWnd = NULL;
	BOOL bRet  = FALSE;
	bRet = MyRegister("MyWnd"); // 注册的窗口类型是什么就应该传什么
	if(FALSE == bRet)
	{
		MessageBox(NULL, "Register Window Failed", "Failed", MB_OK);
		return - 1;
	}
	else
	{
		MessageBox(NULL, "Register Window Success", "Success", MB_OK);
	}


	g_hInstance = hInstance;
	
	hWnd = MyCreate("MyWnd");
	
	if(NULL == hWnd)
	{
		MessageBox(NULL, "Create Window Failed", "Failed", MB_OK);
	}

	DisplayWnd(hWnd);

	Message();

	return 0;
}