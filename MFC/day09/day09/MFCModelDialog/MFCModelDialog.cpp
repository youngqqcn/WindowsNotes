// MFCModelDialog.cpp : Defines the entry point for the application.
//

#include "stdafx.h"

#include "resource.h"


class CModelDlg : public CDialog
{
public:
	CModelDlg();

	virtual BOOL OnInitDialog();

	afx_msg void OnPaint();
	afx_msg void OnOk();

public:
	DECLARE_MESSAGE_MAP()
};
BEGIN_MESSAGE_MAP(CModelDlg, CDialog )
	ON_WM_PAINT()
	ON_COMMAND(IDOK, OnOk)
END_MESSAGE_MAP()

void  CModelDlg::OnPaint()
{
	CPaintDC dc(this);
	dc.Rectangle(10, 10, 100, 100);
}

void  CModelDlg::OnOk()
{
	AfxMessageBox("Ok");
	CDialog::OnOK();
}

CModelDlg::CModelDlg() : CDialog(IDD_DIALOG1)
{
}

BOOL CModelDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	AfxMessageBox("Hello");
	return TRUE;
}


class CDlgApp : public CWinApp
{
public:
	virtual BOOL InitInstance();
};



CDlgApp  theApp;


BOOL CDlgApp::InitInstance()
{
	/*
	CModelDlg *pWnd = new CModelDlg();
	m_pMainWnd = pWnd;
	m_pMainWnd->ShowWindow(SW_SHOW);
	m_pMainWnd->UpdateWindow();
	*/
	CModelDlg dlg;
	dlg.DoModal();

	//m_pMainWnd = &dlg;
	return TRUE;
}








