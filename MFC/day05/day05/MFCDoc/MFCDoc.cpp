// MFCDoc.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "resource.h"

class CMyDocument : public CDocument
{
public:
	CMyDocument();
	DECLARE_DYNCREATE(CMyDocument)
public:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnTest();


public:
	CString m_strText;
};
IMPLEMENT_DYNCREATE(CMyDocument, CDocument)

BEGIN_MESSAGE_MAP(CMyDocument, CDocument)
	ON_COMMAND(ID_TEST, OnTest)
END_MESSAGE_MAP()

void CMyDocument::OnTest()
{
	AfxMessageBox("test");
}



CMyDocument::CMyDocument()
{
	m_strText = "hello document";
}



class CDocView : public CEditView
{
public:
	DECLARE_DYNCREATE(CDocView)

//	DECLARE_MESSAGE_MAP()
public:
//	afx_msg void OnTest();
	virtual void OnInitialUpdate();
};
IMPLEMENT_DYNCREATE(CDocView, CEditView)

//BEGIN_MESSAGE_MAP(CDocView, CEditView)
//	ON_COMMAND(ID_TEST, OnTest)
//END_MESSAGE_MAP()

//void CDocView::OnTest()
//{
//	AfxMessageBox("test");
//}


void CDocView::OnInitialUpdate()
{
	CDocument *pDoc = GetDocument();//view中有document的指针
	if(FALSE == pDoc->IsKindOf(RUNTIME_CLASS(CMyDocument)))
	{
		return;
	}
	else
	{
		CMyDocument *pMyDoc = (CMyDocument *)pDoc;
		SetWindowText(pMyDoc->m_strText);
	}
}


class CDocFrame : public CFrameWnd
{
public:

};

class CDocApp : public CWinApp
{
public:
	virtual BOOL InitInstance();
};

CDocApp theApp;



BOOL  CDocApp ::InitInstance()
{
	CDocFrame *pWnd = new CDocFrame();

	CCreateContext context;
	context.m_pNewViewClass = RUNTIME_CLASS(CDocView);
	context.m_pCurrentDoc = new CMyDocument(); //增加文档类支持

	pWnd->LoadFrame(IDR_MAINFRM, WS_OVERLAPPEDWINDOW, NULL, &context);

	m_pMainWnd = pWnd;
	m_pMainWnd->ShowWindow(SW_SHOW);
	m_pMainWnd->UpdateWindow();

	pWnd->InitialUpdateFrame(NULL, TRUE); //更新所有frame

	return TRUE;
}