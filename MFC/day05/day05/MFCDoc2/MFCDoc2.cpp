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
	//ON_COMMAND(ID_NEW, OnTest)
END_MESSAGE_MAP()

void CMyDocument::OnTest()
{
	AfxMessageBox("test  document");
}



CMyDocument::CMyDocument()
{
	m_strText = "hello document";
}



class CDocView : public CEditView
{
public:
	DECLARE_DYNCREATE(CDocView)

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnTest();
	virtual void OnInitialUpdate();
};
IMPLEMENT_DYNCREATE(CDocView, CEditView)

BEGIN_MESSAGE_MAP(CDocView, CEditView)
	//ON_COMMAND(ID_NEW, OnTest)
END_MESSAGE_MAP()

void CDocView::OnTest()
{
	AfxMessageBox("test  DocView");
}


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
	DECLARE_MESSAGE_MAP()
	afx_msg void OnTest();
};

BEGIN_MESSAGE_MAP(CDocFrame, CFrameWnd)
	//ON_COMMAND(ID_NEW, OnTest)
END_MESSAGE_MAP()

void CDocFrame::OnTest()
{
	AfxMessageBox("test  DocFrame");
}


class CDocApp : public CWinApp
{
	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL InitInstance();
	afx_msg void OnTest();
};
BEGIN_MESSAGE_MAP(CDocApp, CWinApp)
	ON_COMMAND(ID_NEW, OnTest)
END_MESSAGE_MAP()

void CDocApp::OnTest()
{
	AfxMessageBox("test  DocApp");
}



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