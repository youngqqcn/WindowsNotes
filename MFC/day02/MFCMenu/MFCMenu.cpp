// MFCMenu.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "resource.h"



class  CMenuApp : public CWinApp
{
	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL InitInstance();
	afx_msg void OnAbout();
};

BEGIN_MESSAGE_MAP(CMenuApp, CWinApp)
	ON_COMMAND(ID_ABOUT, OnAbout)
END_MESSAGE_MAP()



void CMenuApp::OnAbout()
{
	AfxMessageBox("aboout");
}


class CMenuFrame : public CFrameWnd
{
	DECLARE_MESSAGE_MAP()
public:

	afx_msg void OnExit();
};


BEGIN_MESSAGE_MAP(CMenuFrame, CFrameWnd)
	ON_COMMAND(ID_EXIT, OnExit)
END_MESSAGE_MAP()

CMenuApp theApp;


void CMenuFrame::OnExit()
{
	::PostQuitMessage(WM_QUIT);
}

BOOL CMenuApp::InitInstance()
{
	CMenuFrame *pWnd = new CMenuFrame();

	pWnd->Create(NULL, "MenuApp", WS_OVERLAPPEDWINDOW, CFrameWnd::rectDefault, NULL, MAKEINTRESOURCE(IDR_MAIN));
	m_pMainWnd = pWnd;
	m_pMainWnd->ShowWindow(TRUE);
	m_pMainWnd->UpdateWindow();


	return TRUE;
}


