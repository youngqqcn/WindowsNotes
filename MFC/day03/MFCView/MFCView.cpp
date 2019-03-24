// MFCToolBar.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "resource.h"



class CViewApp : public CWinApp
{
public:
	virtual  BOOL  InitInstance();
};


class CMyView : public CView
{
	DECLARE_MESSAGE_MAP()
public:
	virtual void OnDraw(CDC *pDC);

	afx_msg void OnPaint();
	afx_msg void OnTest();
};

BEGIN_MESSAGE_MAP(CMyView, CView)
	ON_WM_PAINT()
	ON_COMMAND(ID_TEST1, OnTest)
END_MESSAGE_MAP()



void CMyView::OnDraw(CDC *pDC)
{
	pDC->TextOut(100, 100, "Hello View");
	
}




void CMyView::OnTest()
{
	AfxMessageBox("测试成功");	
}

/*
HDC BeginPaint(
	HWND hwnd, // 窗口的句柄
	LPPAINTSTRUCT lpPaint // 绘制信息
);
*/

void CMyView::OnPaint()
{
	PAINTSTRUCT ps = {0};
	HDC hDC = ::BeginPaint(m_hWnd, &ps);


	TextOut(hDC, 100, 100, "View Hello" , 10);

	::EndPaint(m_hWnd, &ps);
}






class CViewFrame : public CFrameWnd
{
	DECLARE_MESSAGE_MAP()
public:
	CViewFrame();
	BOOL OnCmdMsg(UINT iID, int iCode, void *pExtra, AFX_CMDHANDLERINFO *lpHandlerInfo);
public:
	int OnCreate(LPCREATESTRUCT lpCreateStruct);

public:
	CMyView *m_pwndView;
};

BEGIN_MESSAGE_MAP(CViewFrame, CFrameWnd)
	ON_WM_CREATE()
END_MESSAGE_MAP()


CViewFrame::CViewFrame()
{
	m_pwndView = NULL;
}


BOOL CViewFrame::OnCmdMsg(UINT iID, int iCode, void *pExtra, AFX_CMDHANDLERINFO *lpHandlerInfo)
{
#if 1
	if(NULL != m_pwndView)
	{
		if(TRUE == m_pwndView->OnCmdMsg(iID, iCode, pExtra, lpHandlerInfo))
		{
			return TRUE;
		}
	}

#endif
	return CFrameWnd::OnCmdMsg(iID, iCode, pExtra, lpHandlerInfo);
}

int CViewFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	CFrameWnd::OnCreate(lpCreateStruct);

	m_pwndView = new CMyView();
	m_pwndView->Create(NULL, "Vieeeew", WS_CHILD|WS_VISIBLE|WS_BORDER, CRect(100, 100, 200, 200), this, AFX_IDW_PANE_FIRST /*填满客户区*/);

	SetActiveView(m_pwndView); //就不必自己写消息派发了


	ModifyStyle(WS_EX_CLIENTEDGE,  0 );
	return 0;
}





CViewApp theApp;


BOOL CViewApp::InitInstance()
{

	CViewFrame *pWnd = new CViewFrame();
	pWnd->Create(NULL, "View使用", WS_OVERLAPPEDWINDOW, CFrameWnd::rectDefault, NULL, MAKEINTRESOURCE(IDR_MENU1));
	m_pMainWnd = pWnd;
	m_pMainWnd->ShowWindow(SW_SHOW);
	m_pMainWnd->UpdateWindow();

	return TRUE;
}


















