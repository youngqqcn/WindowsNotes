// MFCSingle.h : main header file for the MFCSINGLE application
//

#if !defined(AFX_MFCSINGLE_H__CF816744_81EC_43E7_AFD9_2C576C6DC41D__INCLUDED_)
#define AFX_MFCSINGLE_H__CF816744_81EC_43E7_AFD9_2C576C6DC41D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CMFCSingleApp:
// See MFCSingle.cpp for the implementation of this class
//

class CMFCSingleApp : public CWinApp
{
public:
	CMFCSingleApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMFCSingleApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CMFCSingleApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MFCSINGLE_H__CF816744_81EC_43E7_AFD9_2C576C6DC41D__INCLUDED_)
