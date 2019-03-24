// MFCDcDoc.h : interface of the CMFCDcDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MFCDCDOC_H__0D43B723_1D6A_40BE_B04F_07785390C676__INCLUDED_)
#define AFX_MFCDCDOC_H__0D43B723_1D6A_40BE_B04F_07785390C676__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CMFCDcDoc : public CDocument
{
protected: // create from serialization only
	CMFCDcDoc();
	DECLARE_DYNCREATE(CMFCDcDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMFCDcDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMFCDcDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMFCDcDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MFCDCDOC_H__0D43B723_1D6A_40BE_B04F_07785390C676__INCLUDED_)
