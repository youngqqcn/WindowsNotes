// UserRegDll.h : main header file for the USERREGDLL application
//

#if !defined(AFX_USERREGDLL_H__FBCACDFF_39E2_4BB2_9E4A_4F44192E6818__INCLUDED_)
#define AFX_USERREGDLL_H__FBCACDFF_39E2_4BB2_9E4A_4F44192E6818__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CUserRegDllApp:
// See UserRegDll.cpp for the implementation of this class
//

class CUserRegDllApp : public CWinApp
{
public:
	CUserRegDllApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CUserRegDllApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CUserRegDllApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_USERREGDLL_H__FBCACDFF_39E2_4BB2_9E4A_4F44192E6818__INCLUDED_)
