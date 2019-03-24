// MFCGdi.h : main header file for the MFCGDI application
//

#if !defined(AFX_MFCGDI_H__447F09D0_A3A3_4660_A914_BE7AEBBEDC11__INCLUDED_)
#define AFX_MFCGDI_H__447F09D0_A3A3_4660_A914_BE7AEBBEDC11__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CMFCGdiApp:
// See MFCGdi.cpp for the implementation of this class
//

class CMFCGdiApp : public CWinApp
{
public:
	CMFCGdiApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMFCGdiApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

public:
	//{{AFX_MSG(CMFCGdiApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MFCGDI_H__447F09D0_A3A3_4660_A914_BE7AEBBEDC11__INCLUDED_)
