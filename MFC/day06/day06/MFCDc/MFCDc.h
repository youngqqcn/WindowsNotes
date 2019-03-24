// MFCDc.h : main header file for the MFCDC application
//

#if !defined(AFX_MFCDC_H__7972D47C_C40F_4F81_90D1_CEB0826C9CB2__INCLUDED_)
#define AFX_MFCDC_H__7972D47C_C40F_4F81_90D1_CEB0826C9CB2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CMFCDcApp:
// See MFCDc.cpp for the implementation of this class
//

class CMFCDcApp : public CWinApp
{
public:
	CMFCDcApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMFCDcApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CMFCDcApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MFCDC_H__7972D47C_C40F_4F81_90D1_CEB0826C9CB2__INCLUDED_)
