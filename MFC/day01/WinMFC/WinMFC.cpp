// WinMFC.cpp : Defines the entry point for the application.
//

#include "stdafx.h"



//框架窗口类
class CMyFrameWnd : public CFrameWnd
{
public:


	//窗口处理函数
	virtual LRESULT WindowProc(UINT message, WPARAM wParam, LPARAM lParam);
};





LRESULT CMyFrameWnd::WindowProc(UINT message, WPARAM wParam, LPARAM lParam)
{
	switch(message)
	{
	case WM_CREATE:
		AfxMessageBox("WM_CREATE");
		break;
	case WM_PAINT://绘图消息
		{
			PAINTSTRUCT ps = {0};
			HDC hDC = ::BeginPaint(m_hWnd, &ps);  //加"::" 表示使用全局(Win32的API)

			CHAR  szText[] = "hello world";
			TextOut(hDC, 100, 100, szText, strlen(szText));  //画文本

			::EndPaint(m_hWnd, &ps);
		}
		break;
	}

	return CFrameWnd::WindowProc(message, wParam, lParam); //使用父类的窗口处理函数
}



//应用程序类
class CMyApp : public CWinApp
{
public:
	CMyApp();
	virtual BOOL InitInstance();
};

//定义CMyApp的全局变量
CMyApp theApp;


CMyApp::CMyApp()
{



}



//初始化函数
BOOL CMyApp::InitInstance()
{
	//AfxMessageBox("Hello App");

	//创建窗口对象
	CMyFrameWnd  *pWnd = new CMyFrameWnd();

	//创建窗口
	pWnd->Create(NULL, "MyApp");

	//显示窗口
	pWnd->ShowWindow(SW_SHOW);


	//设置主窗口
	m_pMainWnd = pWnd;


	return TRUE; //如果返回FALSE , 就直接退出应用程序了
}








