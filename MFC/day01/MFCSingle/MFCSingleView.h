// MFCSingleView.h : interface of the CMFCSingleView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MFCSINGLEVIEW_H__364F0393_5D86_43D7_9430_3482B38E0F3A__INCLUDED_)
#define AFX_MFCSINGLEVIEW_H__364F0393_5D86_43D7_9430_3482B38E0F3A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CMFCSingleView : public CView
{
protected: // create from serialization only
	CMFCSingleView();
	DECLARE_DYNCREATE(CMFCSingleView)

// Attributes
public:
	CMFCSingleDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMFCSingleView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMFCSingleView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMFCSingleView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in MFCSingleView.cpp
inline CMFCSingleDoc* CMFCSingleView::GetDocument()
   { return (CMFCSingleDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MFCSINGLEVIEW_H__364F0393_5D86_43D7_9430_3482B38E0F3A__INCLUDED_)
