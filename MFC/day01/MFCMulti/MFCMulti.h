// MFCMulti.h : main header file for the MFCMULTI application
//

#if !defined(AFX_MFCMULTI_H__4FA84723_88C1_4404_BD8E_C134C97EF0D5__INCLUDED_)
#define AFX_MFCMULTI_H__4FA84723_88C1_4404_BD8E_C134C97EF0D5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CMFCMultiApp:
// See MFCMulti.cpp for the implementation of this class
//

class CMFCMultiApp : public CWinApp
{
public:
	CMFCMultiApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMFCMultiApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CMFCMultiApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MFCMULTI_H__4FA84723_88C1_4404_BD8E_C134C97EF0D5__INCLUDED_)
