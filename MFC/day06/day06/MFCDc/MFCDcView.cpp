// MFCDcView.cpp : implementation of the CMFCDcView class
//

#include "stdafx.h"
#include "MFCDc.h"

#include "MFCDcDoc.h"
#include "MFCDcView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMFCDcView

IMPLEMENT_DYNCREATE(CMFCDcView, CView)

BEGIN_MESSAGE_MAP(CMFCDcView, CView)
	//{{AFX_MSG_MAP(CMFCDcView)
	ON_COMMAND(ID_CDC, OnCdc)
	ON_COMMAND(ID_WINDOWDC, OnWindowdc)
	ON_COMMAND(ID_CLIENTDC, OnClientdc)
	ON_WM_PAINT()
	ON_COMMAND(ID_METAFILEDC, OnMetafiledc)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMFCDcView construction/destruction

CMFCDcView::CMFCDcView()
{
}

CMFCDcView::~CMFCDcView()
{
}

BOOL CMFCDcView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CMFCDcView drawing

void CMFCDcView::OnDraw(CDC* pDC)
{
	CMFCDcDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CMFCDcView printing

BOOL CMFCDcView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMFCDcView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMFCDcView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CMFCDcView diagnostics

#ifdef _DEBUG
void CMFCDcView::AssertValid() const
{
	CView::AssertValid();
}

void CMFCDcView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCDcDoc* CMFCDcView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCDcDoc)));
	return (CMFCDcDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMFCDcView message handlers

void CMFCDcView::OnCdc() 
{
#if 1
	CDC dc;
	dc.CreateDC("DISPLAY", NULL, NULL, NULL);//创建显示器DC
	dc.Rectangle(50, 50 ,500, 500);
	
	dc.DeleteDC();//删除DC
#endif
}

void CMFCDcView::OnWindowdc() 
{
	CWindowDC dc(this);
	dc.Rectangle(50, 50, 500, 500);
	

}

void CMFCDcView::OnClientdc() 
{
	CClientDC dc(this);
	dc.Rectangle(50, 50, 500, 500);
	
	//获取客户区DC
	CDC *pDc = GetDC();	
	ReleaseDC(pDc);
}

void CMFCDcView::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	
	// TODO: Add your message handler code here
	dc.FillSolidRect(50, 50, 100, 100, RGB(0, 255, 0));
	// Do not call CView::OnPaint() for painting messages
}

void CMFCDcView::OnMetafiledc() 
{
	// TODO: Add your command handler code here
	CMetaFileDC dc;
	dc.Create("C:\\meta.data");

	//绘图
	dc.FillSolidRect(0, 0, 100, 100, RGB(0, 0, 255));

	//关闭dc
	HMETAFILE hMetaFile = dc.Close();

	//显示MetaFile
	CClientDC dc1(this);
	dc1.PlayMetaFile(hMetaFile);

	//删除MetaFile句柄
	DeleteMetaFile(hMetaFile);
}
