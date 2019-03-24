// UseRegDll2.h : main header file for the USEREGDLL2 application
//

#if !defined(AFX_USEREGDLL2_H__215C7CC3_35AD_40D4_AA60_5737D45421E2__INCLUDED_)
#define AFX_USEREGDLL2_H__215C7CC3_35AD_40D4_AA60_5737D45421E2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CUseRegDll2App:
// See UseRegDll2.cpp for the implementation of this class
//

class CUseRegDll2App : public CWinApp
{
public:
	CUseRegDll2App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CUseRegDll2App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CUseRegDll2App)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_USEREGDLL2_H__215C7CC3_35AD_40D4_AA60_5737D45421E2__INCLUDED_)
