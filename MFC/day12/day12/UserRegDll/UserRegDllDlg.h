// UserRegDllDlg.h : header file
//

#if !defined(AFX_USERREGDLLDLG_H__B6EAF11C_EDCA_4DD6_B3D6_6D180E2892E8__INCLUDED_)
#define AFX_USERREGDLLDLG_H__B6EAF11C_EDCA_4DD6_B3D6_6D180E2892E8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CUserRegDllDlg dialog

class CUserRegDllDlg : public CDialog
{
// Construction
public:
	CUserRegDllDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CUserRegDllDlg)
	enum { IDD = IDD_USERREGDLL_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CUserRegDllDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CUserRegDllDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButton1();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_USERREGDLLDLG_H__B6EAF11C_EDCA_4DD6_B3D6_6D180E2892E8__INCLUDED_)
