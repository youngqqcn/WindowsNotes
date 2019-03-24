// UseRegDll2Dlg.h : header file
//

#if !defined(AFX_USEREGDLL2DLG_H__E856CD94_448B_42ED_93D0_FE1DDC9F3873__INCLUDED_)
#define AFX_USEREGDLL2DLG_H__E856CD94_448B_42ED_93D0_FE1DDC9F3873__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CUseRegDll2Dlg dialog

class CUseRegDll2Dlg : public CDialog
{
// Construction
public:
	CUseRegDll2Dlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CUseRegDll2Dlg)
	enum { IDD = IDD_USEREGDLL2_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CUseRegDll2Dlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CUseRegDll2Dlg)
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

#endif // !defined(AFX_USEREGDLL2DLG_H__E856CD94_448B_42ED_93D0_FE1DDC9F3873__INCLUDED_)
