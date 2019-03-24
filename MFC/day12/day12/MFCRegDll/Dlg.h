#if !defined(AFX_DLG_H__3B959856_D8F6_4D1A_992D_23BE8A194FA1__INCLUDED_)
#define AFX_DLG_H__3B959856_D8F6_4D1A_992D_23BE8A194FA1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Dlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlg dialog
#include "resource.h"

class CDlg : public CDialog
{
// Construction
public:
	CDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDlg)
	enum { IDD = IDD_DIALOG1 };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlg)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLG_H__3B959856_D8F6_4D1A_992D_23BE8A194FA1__INCLUDED_)
