// Sdi.h : main header file for the SDI application
//

#if !defined(AFX_SDI_H__7B77FEDC_A3F3_4E5A_9F90_F16668A7120F__INCLUDED_)
#define AFX_SDI_H__7B77FEDC_A3F3_4E5A_9F90_F16668A7120F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CSdiApp:
// See Sdi.cpp for the implementation of this class
//

class CSdiApp : public CWinApp
{
public:
	CSdiApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSdiApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CSdiApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SDI_H__7B77FEDC_A3F3_4E5A_9F90_F16668A7120F__INCLUDED_)
