// MFCMultiView.h : interface of the CMFCMultiView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MFCMULTIVIEW_H__3F57667D_9037_43E6_832D_1A08852003C7__INCLUDED_)
#define AFX_MFCMULTIVIEW_H__3F57667D_9037_43E6_832D_1A08852003C7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CMFCMultiView : public CView
{
protected: // create from serialization only
	CMFCMultiView();
	DECLARE_DYNCREATE(CMFCMultiView)

// Attributes
public:
	CMFCMultiDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMFCMultiView)
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
	virtual ~CMFCMultiView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMFCMultiView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in MFCMultiView.cpp
inline CMFCMultiDoc* CMFCMultiView::GetDocument()
   { return (CMFCMultiDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MFCMULTIVIEW_H__3F57667D_9037_43E6_832D_1A08852003C7__INCLUDED_)
