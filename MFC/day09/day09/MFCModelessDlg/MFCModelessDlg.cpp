// MFCModelessDlg.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "resource.h"


class CModelessDlg : public CDialog
{
public:
	//CModelessDlg();
	virtual void OnOK();
};

void CModelessDlg::OnOK()
{
	DestroyWindow();
}


class CDlgApp : public CWinApp
{
public:
	virtual BOOL InitInstance();

};


CDlgApp theApp;



BOOL CDlgApp::InitInstance()
{

	CModelessDlg *pDlg  = new CModelessDlg();
	pDlg->Create(IDD_DIALOG1);
	m_pMainWnd = pDlg;
	m_pMainWnd->ShowWindow(SW_SHOW);
	m_pMainWnd->UpdateWindow();

	return TRUE;
}








