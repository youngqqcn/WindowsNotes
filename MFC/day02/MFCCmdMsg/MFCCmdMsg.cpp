// MFCMsg.cpp : Defines the entry point for the application.
//

#include "stdafx.h"


class CMsgFrame : public CFrameWnd
{
public:
	virtual LRESULT WindowProc(UINT uMsg, WPARAM wParam, LPARAM lParam);

public:
	DECLARE_MESSAGE_MAP() ;

public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnTest01();
	afx_msg void OnTest02_04(UINT uID);
	afx_msg void OnEnChange();  //虽然是 走 WM_COMMAND 消息, 但是分为 notify 消息
};

//消息映射 宏实现
BEGIN_MESSAGE_MAP(CMsgFrame, CFrameWnd )
	ON_WM_CREATE()
	ON_COMMAND(1001, OnTest01)
	ON_COMMAND_RANGE(1001, 1004, OnTest02_04)
	ON_EN_CHANGE(1005, OnEnChange)
END_MESSAGE_MAP()



void CMsgFrame::OnEnChange()
{
	CWnd *pWnd =  GetDlgItem(1005);
	CString strText;
	pWnd->GetWindowText(strText);
	AfxMessageBox(strText);


}

int CMsgFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	CreateWindow("BUTTON", "Test01", WS_CHILD|WS_VISIBLE, 50, 50, 200, 30, GetSafeHwnd(), (HMENU)1001, AfxGetApp()->m_hInstance, NULL);

	CreateWindow("BUTTON", "Test02", WS_CHILD|WS_VISIBLE, 50, 100, 200, 30, GetSafeHwnd(), (HMENU)1002, AfxGetApp()->m_hInstance, NULL);

	CreateWindow("BUTTON", "Test03", WS_CHILD|WS_VISIBLE, 50, 150, 200, 30, GetSafeHwnd(), (HMENU)1003, AfxGetApp()->m_hInstance, NULL);

	CreateWindow("BUTTON", "Test04", WS_CHILD|WS_VISIBLE, 50, 200, 200, 30, GetSafeHwnd(), (HMENU)1004, AfxGetApp()->m_hInstance, NULL);

	CreateWindow("EDIT", "",  WS_CHILD|WS_VISIBLE|WS_BORDER,300, 30, 200, 200, GetSafeHwnd(), (HMENU)1005, AfxGetApp()->m_hInstance, NULL);


	return 0;
}

void CMsgFrame::OnTest02_04(UINT uID)
{
	CString strInfo;
	strInfo.Format("%d", uID);
	AfxMessageBox(strInfo);
}

void CMsgFrame::OnTest01()
{
	AfxMessageBox("OnTest01");
}



LRESULT CMsgFrame::WindowProc(UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	//switch ... case


	return CFrameWnd::WindowProc(uMsg, wParam, lParam);
}




class CMsgApp : public CWinApp
{
public:
	virtual BOOL InitInstance();
};

CMsgApp theApp;


BOOL CMsgApp::InitInstance()
{

	CMsgFrame *pWnd = new CMsgFrame();
	pWnd->Create(NULL, "MsgApp");
	this->m_pMainWnd = pWnd;

	this->m_pMainWnd->ShowWindow(SW_SHOW);
	this->m_pMainWnd->UpdateWindow();

	return TRUE;
}



