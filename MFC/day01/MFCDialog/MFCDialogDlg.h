// MFCDialogDlg.h : header file
//

#if !defined(AFX_MFCDIALOGDLG_H__AC0A2EF1_2207_4451_90F7_57E08361F581__INCLUDED_)
#define AFX_MFCDIALOGDLG_H__AC0A2EF1_2207_4451_90F7_57E08361F581__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CMFCDialogDlg dialog

class CMFCDialogDlg : public CDialog
{
// Construction
public:
	CMFCDialogDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CMFCDialogDlg)
	enum { IDD = IDD_MFCDIALOG_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMFCDialogDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMFCDialogDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MFCDIALOGDLG_H__AC0A2EF1_2207_4451_90F7_57E08361F581__INCLUDED_)
