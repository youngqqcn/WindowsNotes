// MFCDll.h : main header file for the MFCDLL DLL
//

#if !defined(AFX_MFCDLL_H__996AAD92_B777_47AC_B00F_DE919FDDBAE0__INCLUDED_)
#define AFX_MFCDLL_H__996AAD92_B777_47AC_B00F_DE919FDDBAE0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CMFCDllApp
// See MFCDll.cpp for the implementation of this class
//

class CMFCDllApp : public CWinApp
{
public:
	CMFCDllApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMFCDllApp)
	//}}AFX_VIRTUAL

	//{{AFX_MSG(CMFCDllApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MFCDLL_H__996AAD92_B777_47AC_B00F_DE919FDDBAE0__INCLUDED_)
