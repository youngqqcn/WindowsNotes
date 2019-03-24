// MFCSdi.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "resource.h"



class CSdiDocument : public CDocument
{
	DECLARE_DYNCREATE(CSdiDocument)
public:
	
};
IMPLEMENT_DYNCREATE(CSdiDocument, CDocument )

class CSdiView : public CEditView
{
	DECLARE_DYNCREATE(CSdiView)
public:
};
IMPLEMENT_DYNCREATE(CSdiView, CEditView )


class CSdiFrame : public CFrameWnd
{
	DECLARE_DYNCREATE(CSdiFrame)
public:

};
IMPLEMENT_DYNCREATE(CSdiFrame, CFrameWnd )



class  CSdiApp : public CWinApp
{
public:
	virtual BOOL InitInstance();
};

CSdiApp  theApp;

BOOL CSdiApp::InitInstance()
{

	//创建文档模板对象
	CSingleDocTemplate *pTemp = NULL;
	pTemp = new CSingleDocTemplate(
			IDR_MAINFRM, 
			RUNTIME_CLASS(CSdiDocument),
			RUNTIME_CLASS(CSdiFrame),
			RUNTIME_CLASS(CSdiView));

	//保存文档模板
	AddDocTemplate(pTemp);


	//创建文档模板对象
	CSingleDocTemplate *pTemp2 = NULL;
	pTemp2 = new CSingleDocTemplate(
			IDR_MAINFRM2, 
			RUNTIME_CLASS(CSdiDocument),
			RUNTIME_CLASS(CSdiFrame),
			RUNTIME_CLASS(CSdiView));

	//保存文档模板
	AddDocTemplate(pTemp2);

	//新建文档
	OnFileNew();

	//显示窗口
	m_pMainWnd->ShowWindow(SW_SHOW);
	m_pMainWnd->UpdateWindow();

	return TRUE;
}










