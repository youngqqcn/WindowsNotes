// SdiDoc.cpp : implementation of the CSdiDoc class
//

#include "stdafx.h"
#include "Sdi.h"

#include "SdiDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSdiDoc

IMPLEMENT_DYNCREATE(CSdiDoc, CDocument)

BEGIN_MESSAGE_MAP(CSdiDoc, CDocument)
	//{{AFX_MSG_MAP(CSdiDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSdiDoc construction/destruction

CSdiDoc::CSdiDoc()
{
	// TODO: add one-time construction code here

}

CSdiDoc::~CSdiDoc()
{
}

BOOL CSdiDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CSdiDoc serialization

void CSdiDoc::Serialize(CArchive& ar)
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
// CSdiDoc diagnostics

#ifdef _DEBUG
void CSdiDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CSdiDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CSdiDoc commands
