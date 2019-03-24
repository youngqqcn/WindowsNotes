// MFCDcView.h : interface of the CMFCDcView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MFCDCVIEW_H__01C58B55_D66F_4394_AE9E_6F4F35016146__INCLUDED_)
#define AFX_MFCDCVIEW_H__01C58B55_D66F_4394_AE9E_6F4F35016146__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CMFCDcView : public CView
{
protected: // create from serialization only
	CMFCDcView();
	DECLARE_DYNCREATE(CMFCDcView)

// Attributes
public:
	CMFCDcDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMFCDcView)
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
	virtual ~CMFCDcView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMFCDcView)
	afx_msg void OnCdc();
	afx_msg void OnWindowdc();
	afx_msg void OnClientdc();
	afx_msg void OnPaint();
	afx_msg void OnMetafiledc();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in MFCDcView.cpp
inline CMFCDcDoc* CMFCDcView::GetDocument()
   { return (CMFCDcDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MFCDCVIEW_H__01C58B55_D66F_4394_AE9E_6F4F35016146__INCLUDED_)
