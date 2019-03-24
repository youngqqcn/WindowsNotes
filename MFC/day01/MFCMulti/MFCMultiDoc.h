// MFCMultiDoc.h : interface of the CMFCMultiDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MFCMULTIDOC_H__FFD27E24_8FB1_4DF8_BD74_E0EB13B0C74C__INCLUDED_)
#define AFX_MFCMULTIDOC_H__FFD27E24_8FB1_4DF8_BD74_E0EB13B0C74C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CMFCMultiDoc : public CDocument
{
protected: // create from serialization only
	CMFCMultiDoc();
	DECLARE_DYNCREATE(CMFCMultiDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMFCMultiDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMFCMultiDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMFCMultiDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MFCMULTIDOC_H__FFD27E24_8FB1_4DF8_BD74_E0EB13B0C74C__INCLUDED_)
