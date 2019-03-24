// MFCSerialize.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "MFCSerialize.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// The one and only application object

CWinApp theApp;

using namespace std;


//序列存储
void Store()
{
	//打开文件
	CFile file;
	file.Open("C:\\serial.dat", CFile::modeCreate|CFile::modeWrite);

	DWORD nNum = 10001;
	CString str = "hello world";
	//CHAR szText[]  = "hello serial";
	CArchive ar(&file, CArchive::store);
	BYTE b = 99;
	ar << nNum;
	ar << str;
	ar << b ;
	//ar << szText;
	ar.Close();


	//关闭文件
	file.Close();
}

void Load()
{
	CFile file;
	file.Open("C:\\serial.dat", CFile::modeRead);
	
	CArchive ar(&file, CArchive::load);

	DWORD nNum = 0;
	CString str;
	CHAR szText[126] = {0};
	memset(szText, 0, sizeof(szText));

	BYTE b;
	ar >> nNum;
	ar >> str;
	ar >> b;

	//ar >> szText;

	cout << nNum << endl;
	cout << str.GetBuffer(0) << endl;
	cout << b << endl;

	ar.Close();

	file.Close();
}



int _tmain(int argc, TCHAR* argv[], TCHAR* envp[])
{
	Store();
	Load();

	return 0;
}


