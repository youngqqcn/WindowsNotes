// MFCSingleDoc.cpp : implementation of the CMFCSingleDoc class
//

#include "stdafx.h"
#include "MFCSingle.h"

#include "MFCSingleDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMFCSingleDoc

IMPLEMENT_DYNCREATE(CMFCSingleDoc, CDocument)

BEGIN_MESSAGE_MAP(CMFCSingleDoc, CDocument)
	//{{AFX_MSG_MAP(CMFCSingleDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMFCSingleDoc construction/destruction

CMFCSingleDoc::CMFCSingleDoc()
{
	// TODO: add one-time construction code here

}

CMFCSingleDoc::~CMFCSingleDoc()
{
}

BOOL CMFCSingleDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CMFCSingleDoc serialization

void CMFCSingleDoc::Serialize(CArchive& ar)
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
// CMFCSingleDoc diagnostics

#ifdef _DEBUG
void CMFCSingleDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMFCSingleDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMFCSingleDoc commands
