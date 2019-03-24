// MFCSplit.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "resource.h"


UINT iIndicators[] = {
		ID_SEPARATOR,
		ID_INDICATOR_NUM,
		ID_INDICATOR_CAPS,
		ID_INDICATOR_OVR
};




class   CMyView1 : public CView
{
public:
	virtual void OnInitialUpdate();


	DECLARE_DYNCREATE(CMyView1)  //动态创建声明
public:
	virtual void OnDraw(CDC *pDC);
};

IMPLEMENT_DYNCREATE(CMyView1, CView) //动态创建定义(实现)

void CMyView1::OnInitialUpdate()
{
//	AfxMessageBox("OnInitialUpdate");
}

void CMyView1::OnDraw(CDC *pDC)
{
	pDC->TextOut(50, 50, "这是一个view");
}


class   CMyView2 : public CHtmlView
{
public:
	virtual void OnInitialUpdate();


	DECLARE_DYNCREATE(CMyView2)  //动态创建声明
public:
	virtual void OnDraw(CDC *pDC);
};

IMPLEMENT_DYNCREATE(CMyView2, CView) //动态创建定义(实现)

void CMyView2::OnInitialUpdate()
{
//	AfxMessageBox("OnInitialUpdate");

	//打开html文件
	/*
	void Navigate(
    LPCTSTR URL,  
    DWORD dwFlags = 0,  
    LPCTSTR lpszTargetFrameName = NULL,  
    LPCTSTR lpszHeaders = NULL,  
    LPVOID lpvPostData = NULL,  
    DWORD dwPostDataLen = 0);*/


//	Navigate("http://www.baidu.com");
	//Navigate("C:\\");

}

void CMyView2::OnDraw(CDC *pDC)
{
	pDC->TextOut(50, 50, "view2");
}







class CSplitFrame : public CFrameWnd
{


public:
	virtual BOOL OnCreateClient(LPCREATESTRUCT lpCreateStruct, CCreateContext *pContext);
	DECLARE_MESSAGE_MAP()
public:

	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);

public:
	CToolBar m_wndToolBar;
	CStatusBar m_wndStatusBar;

	//切分串口
	CSplitterWnd m_wndSplitter;

	CSplitterWnd m_wndSplitterRight; //切分右侧窗口

};


BEGIN_MESSAGE_MAP(CSplitFrame, CFrameWnd)
	ON_WM_CREATE()
END_MESSAGE_MAP()


BOOL CSplitFrame::OnCreateClient(LPCREATESTRUCT lpCreateStruct, 
								CCreateContext *pContext)
{
#define STATIC_CREATE
#ifdef STATIC_CREATE	//静态切分
	m_wndSplitter.CreateStatic(this, 1, 2); //创建切分
	m_wndSplitterRight.CreateStatic(&m_wndSplitter/*父类*/, 2, 1, 
								WS_CHILD|WS_VISIBLE, 
								m_wndSplitter.IdFromRowCol(0, 1));

	//创建视图


	m_wndSplitter.CreateView(0, 0, RUNTIME_CLASS(CMyView1), CSize(200, 200), pContext);
	m_wndSplitterRight.CreateView(0, 0, RUNTIME_CLASS(CMyView2), CSize(200, 200), pContext);
	m_wndSplitterRight.CreateView(1, 0, RUNTIME_CLASS(CMyView2), CSize(200, 200), pContext);

	CMyView2 *pView1 = (CMyView2 *)m_wndSplitterRight.GetPane(0, 0);
	pView1->Navigate2("http://www.baidu.com");

	CMyView2 *pView2 = (CMyView2 *)m_wndSplitterRight.GetPane(1, 0);
	pView2->Navigate2("C:\\");

	m_wndSplitterRight.SetActivePane(1, 0);
#else //动态切分
	CCreateContext context;

	//获取CMyView1的运行时类信息
	context.m_pNewViewClass = RUNTIME_CLASS(CMyView1) ;

	//创建切分窗口
	m_wndSplitter.Create(this, 2, 2, CSize(50, 50), &context); // 大于 2x2时, MFC会警告, 但是能运行
#endif


	return TRUE;
}



int CSplitFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	CFrameWnd::OnCreate(lpCreateStruct);

#if 1
	m_wndToolBar.CreateEx(this);
	m_wndToolBar.LoadToolBar(IDR_MAINFRM);
	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&m_wndToolBar);

#endif

	//状态栏
	m_wndStatusBar.CreateEx(this);
	m_wndStatusBar.SetIndicators(iIndicators, sizeof(iIndicators)/sizeof(UINT));



	return 0;
}








class CSplitApp : public CWinApp
{
public:
	virtual BOOL InitInstance();
};


CSplitApp theApp;


BOOL CSplitApp::InitInstance()
{
	CSplitFrame *pWnd = new CSplitFrame();
	pWnd->LoadFrame(IDR_MAINFRM);
	m_pMainWnd = pWnd;
	m_pMainWnd->ShowWindow(SW_SHOW);
	m_pMainWnd->UpdateWindow();

	return TRUE;
}











