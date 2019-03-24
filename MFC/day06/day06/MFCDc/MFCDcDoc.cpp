// MFCDcDoc.cpp : implementation of the CMFCDcDoc class
//

#include "stdafx.h"
#include "MFCDc.h"

#include "MFCDcDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMFCDcDoc

IMPLEMENT_DYNCREATE(CMFCDcDoc, CDocument)

BEGIN_MESSAGE_MAP(CMFCDcDoc, CDocument)
	//{{AFX_MSG_MAP(CMFCDcDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMFCDcDoc construction/destruction

CMFCDcDoc::CMFCDcDoc()
{
	// TODO: add one-time construction code here

}

CMFCDcDoc::~CMFCDcDoc()
{
}

BOOL CMFCDcDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CMFCDcDoc serialization

void CMFCDcDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CMFCDcDoc diagnostics

#ifdef _DEBUG
void CMFCDcDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMFCDcDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMFCDcDoc commands
