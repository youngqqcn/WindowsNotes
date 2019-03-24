// MFCMultiDoc.cpp : implementation of the CMFCMultiDoc class
//

#include "stdafx.h"
#include "MFCMulti.h"

#include "MFCMultiDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMFCMultiDoc

IMPLEMENT_DYNCREATE(CMFCMultiDoc, CDocument)

BEGIN_MESSAGE_MAP(CMFCMultiDoc, CDocument)
	//{{AFX_MSG_MAP(CMFCMultiDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMFCMultiDoc construction/destruction

CMFCMultiDoc::CMFCMultiDoc()
{
	// TODO: add one-time construction code here

}

CMFCMultiDoc::~CMFCMultiDoc()
{
}

BOOL CMFCMultiDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CMFCMultiDoc serialization

void CMFCMultiDoc::Serialize(CArchive& ar)
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
// CMFCMultiDoc diagnostics

#ifdef _DEBUG
void CMFCMultiDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMFCMultiDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMFCMultiDoc commands
