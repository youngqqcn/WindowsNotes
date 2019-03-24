#include <windows.h>

HINSTANCE g_hInst = NULL;

LRESULT CALLBACK WndProc(HWND hWnd, UINT nMsg, WPARAM wParam, LPARAM lParam)
{
	switch(nMsg)
	{
	case WM_DESTROY:
		PostQuitMessage(WM_QUIT);
		return 0;
	}


	return DefWindowProc(hWnd, nMsg, wParam, lParam);
}



BOOL RegisterWnd(LPSTR pszClassName)
{
	WNDCLASSEX wce = {0};
	wce.cbSize = sizeof(wce);
	wce.cbClsExtra = 0;
	wce.cbWndExtra = 0;
	wce.hbrBackground = HBRUSH(COLOR_BTNFACE + 1);
	wce.hCursor = NULL;
	wce.hIcon = NULL;
	wce.hIconSm = NULL;
	wce.hInstance = g_hInst;
	wce.lpfnWndProc = WndProc;  //窗口处理函数
	wce.lpszClassName = pszClassName;
	wce.lpszMenuName = NULL;
	wce.style = CS_VREDRAW | CS_HREDRAW;

	ATOM nAtom = RegisterClassEx(&wce);
	if(0 == nAtom)
		return FALSE;

	return TRUE;
}


HWND CreateWnd(LPSTR pszClassName)
{
	return CreateWindowEx(0, pszClassName, "MyWnd", WS_OVERLAPPEDWINDOW, CW_USEDEFAULT,
						CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, g_hInst, NULL);
}



void DisplayWnd(HWND hWnd)
{
	ShowWindow(hWnd, SW_SHOW);
	UpdateWindow(hWnd);
}


/*

BOOL GetMessage(  
	LPMSG lpMsg,  //存放获取到的消息数据
	HWND hWnd,    //获取指定窗口句柄的消息
	UINT wMsgFilterMin,  //消息过滤的起始消息
	UINT wMsgFilterMax );  //消息过滤的终止消息
	获取到消息时返回TRUE
	当获取到 WM_QUIT消息时返回FALSE



void PostQuitMessage(  int nExitCode ); 




BOOL TranslateMessage(  const MSG* lpMsg );  
 //将键盘消息转换为字符消息
     1.首先是否是键盘按键消息
	       如果是:  将根据按键,产生一个字符消息, 再下一个GetMessage执行时会受到这个消息
	       如果不是: 不做任何处理



LONG DispatchMessage(  const MSG* lpmsg );
//根据消息数据内窗口句柄, 找到这个窗口的处理函数, 调用处理函数, 进行消息处理
//如果MSG中国, HWND窗口句柄为空, DispatchMessage不做任何处理


 LRESULT DefWindowProc(  
  HWND hWnd,  
  UINT Msg,  
  WPARAM wParam, 
  LPARAM lParam ); 
//使用系统默认处理函数处理消息




typedef struct tagMSG {     // msg  
   HWND hwnd;   //指定消息所属的窗口句柄
   UINT message;   //消息
   WPARAM wParam;  //消息所带的值
   LPARAM lParam;  ///消息所带的值
   DWORD time;     
   POINT pt;  //鼠标所在位置
} MSG;



 常用消息:
	1.WM_DESTROY   //窗口销毁时的消息,   (可以做退出处理)
	2.WM_CREATE    //窗口创建后, 窗口处理函数收到的第一条消息,  (可以做初始化数据,创建子窗口)
	3.WM_SIZE   //当窗口大小发生变化时,会收到的消息   (可以用于调整窗口布局)
	4.WM_SYSCOMMAND  //系统命令消息,  当点击菜单选项和按钮时会收到此消息.(可以在这个消息中提示用户保存数据)
	5.WM_PAINT   //绘图消息, 
	6.键盘消息
	7.鼠标消息
	8.WM_TIMER  //定时器消息


 */




void Message()
{
	MSG msg = {0};
	while(GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
}



int WINAPI WinMain(
				   HINSTANCE hInst,
				   HINSTANCE hPrevInst,
				   LPSTR lpCmdLine,
				   int nCmdShow)
{
	g_hInst = hInst;

	RegisterWnd("MyWnd1");
	HWND hWnd1 =  CreateWnd("MyWnd1");
	DisplayWnd(hWnd1);
	Message();


	return 0;
}