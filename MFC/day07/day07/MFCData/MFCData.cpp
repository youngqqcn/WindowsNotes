// MFCData.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "MFCData.h"
#include <afxtempl.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// The one and only application object

CWinApp theApp;

using namespace std;


class CAnimal 
{
public:
	int iLegs;
};


void Arr()
{
	CArray<int , int> arInt;
	arInt.Add(100);
	cout << arInt[0] << endl;

	CArray<CAnimal, CAnimal&> arAnimal;
	
}








void StrArr()
{
	CStringArray arStrs;
	arStrs.Add("Test1");
	arStrs.Add("Test2");

	cout << arStrs[0].GetBuffer(0) << endl;
}







int _tmain(int argc, TCHAR* argv[], TCHAR* envp[])
{
	//StrArr();
	Arr();

	return 0;
}


