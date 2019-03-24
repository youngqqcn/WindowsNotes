// MFCMultiView.cpp : implementation of the CMFCMultiView class
//

#include "stdafx.h"
#include "MFCMulti.h"

#include "MFCMultiDoc.h"
#include "MFCMultiView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMFCMultiView

IMPLEMENT_DYNCREATE(CMFCMultiView, CView)

BEGIN_MESSAGE_MAP(CMFCMultiView, CView)
	//{{AFX_MSG_MAP(CMFCMultiView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMFCMultiView construction/destruction

CMFCMultiView::CMFCMultiView()
{
	// TODO: add construction code here

}

CMFCMultiView::~CMFCMultiView()
{
}

BOOL CMFCMultiView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CMFCMultiView drawing

void CMFCMultiView::OnDraw(CDC* pDC)
{
	CMFCMultiDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CMFCMultiView printing

BOOL CMFCMultiView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMFCMultiView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMFCMultiView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CMFCMultiView diagnostics

#ifdef _DEBUG
void CMFCMultiView::AssertValid() const
{
	CView::AssertValid();
}

void CMFCMultiView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCMultiDoc* CMFCMultiView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCMultiDoc)));
	return (CMFCMultiDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMFCMultiView message handlers
