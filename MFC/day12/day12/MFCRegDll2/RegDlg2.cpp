// RegDlg2.cpp : implementation file
//

#include "stdafx.h"
#include "MFCRegDll2.h"
#include "RegDlg2.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CRegDlg2 dialog


CRegDlg2::CRegDlg2(CWnd* pParent /*=NULL*/)
	: CDialog(CRegDlg2::IDD, pParent)
{
	//{{AFX_DATA_INIT(CRegDlg2)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CRegDlg2::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CRegDlg2)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CRegDlg2, CDialog)
	//{{AFX_MSG_MAP(CRegDlg2)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRegDlg2 message handlers
