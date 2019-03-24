// MFCSingleView.cpp : implementation of the CMFCSingleView class
//

#include "stdafx.h"
#include "MFCSingle.h"

#include "MFCSingleDoc.h"
#include "MFCSingleView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMFCSingleView

IMPLEMENT_DYNCREATE(CMFCSingleView, CView)

BEGIN_MESSAGE_MAP(CMFCSingleView, CView)
	//{{AFX_MSG_MAP(CMFCSingleView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMFCSingleView construction/destruction

CMFCSingleView::CMFCSingleView()
{
	// TODO: add construction code here

}

CMFCSingleView::~CMFCSingleView()
{
}

BOOL CMFCSingleView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CMFCSingleView drawing

void CMFCSingleView::OnDraw(CDC* pDC)
{
	CMFCSingleDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CMFCSingleView printing

BOOL CMFCSingleView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMFCSingleView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMFCSingleView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CMFCSingleView diagnostics

#ifdef _DEBUG
void CMFCSingleView::AssertValid() const
{
	CView::AssertValid();
}

void CMFCSingleView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCSingleDoc* CMFCSingleView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCSingleDoc)));
	return (CMFCSingleDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMFCSingleView message handlers
