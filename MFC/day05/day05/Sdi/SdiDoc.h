// SdiDoc.h : interface of the CSdiDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_SDIDOC_H__12068133_9813_438A_885F_C850D421491D__INCLUDED_)
#define AFX_SDIDOC_H__12068133_9813_438A_885F_C850D421491D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CSdiDoc : public CDocument
{
protected: // create from serialization only
	CSdiDoc();
	DECLARE_DYNCREATE(CSdiDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSdiDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CSdiDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CSdiDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SDIDOC_H__12068133_9813_438A_885F_C850D421491D__INCLUDED_)
