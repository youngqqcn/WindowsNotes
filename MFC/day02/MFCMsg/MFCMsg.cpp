// MFCMsg.cpp : Defines the entry point for the application.
//

#include "stdafx.h"


class CMsgFrame : public CFrameWnd
{
public:
	virtual LRESULT WindowProc(UINT uMsg, WPARAM wParam, LPARAM lParam);

public:
	DECLARE_MESSAGE_MAP() 
	
	//#define DECLARE_MESSAGE_MAP() 
	//private: 
	//static const AFX_MSGMAP_ENTRY _messageEntries[]; 
	//protected: 
	//static AFX_DATA const AFX_MSGMAP messageMap; 
	//static const AFX_MSGMAP* PASCAL _GetBaseMessageMap(); 
	//virtual const AFX_MSGMAP* GetMessageMap() const; 
	
public:

	//消息处理函数
	afx_msg LRESULT OnPaint(WPARAM wParam, LPARAM lParam);


	//afx_msg LRESULT OnCreate(WPARAM wParam, LPARAM lParam);

	afx_msg int OnCreate();

};

//消息映射 宏实现
BEGIN_MESSAGE_MAP(CMsgFrame, CFrameWnd )
	//消息映射对应
	ON_MESSAGE(WM_PAINT, OnPaint)
	//ON_MESSAGE(WM_CREATE, OnCreate)
	ON_WM_CREATE()
END_MESSAGE_MAP()



/*	#define BEGIN_MESSAGE_MAP(theClass, baseClass)

	const AFX_MSGMAP* PASCAL theClass::_GetBaseMessageMap() \
		{ return &baseClass::messageMap; } \

	const AFX_MSGMAP* theClass::GetMessageMap() const \
		{ return &theClass::messageMap; } \

	AFX_COMDAT AFX_DATADEF const AFX_MSGMAP theClass::messageMap = \
	{ &theClass::_GetBaseMessageMap, &theClass::_messageEntries[0] }; \

	AFX_COMDAT const AFX_MSGMAP_ENTRY theClass::_messageEntries[] = \
	{ \
*/

/*
// for Windows messages
#define ON_MESSAGE(message, memberFxn) \
	{ message, 0, 0, 0, AfxSig_lwl, \
		(AFX_PMSG)(AFX_PMSGW)(LRESULT (AFX_MSG_CALL CWnd::*)(WPARAM, LPARAM))&memberFxn },
*/



/*
#define END_MESSAGE_MAP() \
		{0, 0, 0, 0, AfxSig_end, (AFX_PMSG)0 } \
	}; \
*/


/*
LRESULT CMsgFrame::OnCreate(WPARAM wParam, LPARAM lParam)
{
//	AfxMessageBox("OnCreate");
	return 0;
}
*/

int CMsgFrame:: OnCreate()
{
	AfxMessageBox("OnCreate");
	return 1;
}



LRESULT CMsgFrame::OnPaint(WPARAM wParam, LPARAM lParam)
{
	PAINTSTRUCT ps = {0};
	HDC hDC = ::BeginPaint(m_hWnd, &ps);


	TextOut(hDC, 100, 100, "Msg", 3);


	::EndPaint(m_hWnd, &ps);

	return 0;
}






LRESULT CMsgFrame::WindowProc(UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	//switch ... case


	return CFrameWnd::WindowProc(uMsg, wParam, lParam);
}




class CMsgApp : public CWinApp
{
public:
	virtual BOOL InitInstance();
};

CMsgApp theApp;


BOOL CMsgApp::InitInstance()
{

	CMsgFrame *pWnd = new CMsgFrame();
	pWnd->Create(NULL, "MsgApp");
	this->m_pMainWnd = pWnd;

	this->m_pMainWnd->ShowWindow(SW_SHOW);
	this->m_pMainWnd->UpdateWindow();

	return TRUE;
}



