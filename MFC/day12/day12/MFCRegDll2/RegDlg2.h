#if !defined(AFX_REGDLG2_H__0990641D_D654_4ABD_B2F4_5CEF68CE67D5__INCLUDED_)
#define AFX_REGDLG2_H__0990641D_D654_4ABD_B2F4_5CEF68CE67D5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// RegDlg2.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CRegDlg2 dialog

class CRegDlg2 : public CDialog
{
// Construction
public:
	CRegDlg2(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CRegDlg2)
	enum { IDD = _UNKNOWN_RESOURCE_ID_ };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRegDlg2)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CRegDlg2)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_REGDLG2_H__0990641D_D654_4ABD_B2F4_5CEF68CE67D5__INCLUDED_)
