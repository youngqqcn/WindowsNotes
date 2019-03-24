// RegisterMsg.cpp : Defines the entry point for the application.
//

#include "stdafx.h"


//×¢²áÏûÏ¢id
UINT g_iRegMsg = RegisterWindowMessage("MYREGMSG");

class CRegisterMsgFrame : public CFrameWnd
{
public:	
	DECLARE_MESSAGE_MAP() ;

public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnTest();
	afx_msg LRESULT OnRegMsg(WPARAM wParam, LPARAM lParam);
};


BEGIN_MESSAGE_MAP(CRegisterMsgFrame, CFrameWnd)
	ON_WM_CREATE()
	ON_COMMAND(1001, OnTest)
	ON_REGISTERED_MESSAGE(g_iRegMsg, OnRegMsg)
END_MESSAGE_MAP()


void CRegisterMsgFrame::OnTest()
{
	SendMessage(g_iRegMsg);
}


LRESULT CRegisterMsgFrame::OnRegMsg(WPARAM wParam, LPARAM lParam)
{
	AfxMessageBox("Register Msg");
	return 0;
}


int CRegisterMsgFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{

	CreateWindow("BUTTON", "Test", WS_CHILD|WS_VISIBLE, 50, 50, 200, 30, GetSafeHwnd(), (HMENU)1001, AfxGetApp()->m_hInstance, NULL);
	//CreateWindow("BUTTON", "Test01", WS_CHILD|WS_VISIBLE, 50, 50, 200, 30, GetSafeHwnd(), (HMENU)1001, AfxGetApp()->m_hInstance, NULL);
	

	return 0;
}

class CRegisterMsgApp : public CWinApp
{
public:
	virtual BOOL InitInstance();
};


CRegisterMsgApp theApp;



BOOL CRegisterMsgApp::InitInstance()
{
	CRegisterMsgFrame *pWnd = new CRegisterMsgFrame();
	pWnd->Create(NULL, "Register Msg");
	m_pMainWnd = pWnd;
	m_pMainWnd->ShowWindow(SW_SHOW);
	m_pMainWnd->UpdateWindow();

	return TRUE;
}















