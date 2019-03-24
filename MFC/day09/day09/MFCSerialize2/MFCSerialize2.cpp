// MFCSerialize2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "MFCSerialize2.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// The one and only application object

CWinApp theApp;

using namespace std;


//1.继承CObject
class CAnimal : public CObject
{
public:
	//2.添加序列宏
	DECLARE_SERIAL(CAnimal)

public:
	virtual void Serialize(CArchive &ar);


public:
	int			m_nLeg;
	CString		m_strName;
	int			m_nHand;
};
//3.实现宏
IMPLEMENT_SERIAL(CAnimal, CObject, VERSIONABLE_SCHEMA | 0)


void CAnimal::Serialize(CArchive &ar)
{
	CObject::Serialize(ar); //调用父类的序列化函数

	UINT uSchema = ar.GetObjectSchema() ;
	if(0 == uSchema ) //判断版本号
	{
		if(ar.IsLoading()) //读
		{
			ar >> m_nLeg;
			ar >> m_strName;
		}
		else if(ar.IsStoring()) //写
		{
			ar << m_nLeg;
			ar << m_strName;
		}
	}
	else //if(1 == uSchema)
	{
		if(ar.IsLoading()) //读
		{
			ar >> m_nLeg;
			ar >> m_strName;
			ar >> m_nHand;
		}
		else if(ar.IsStoring()) //写
		{
			ar << m_nLeg;
			ar << m_strName;
			ar << m_nHand;
		}
	}

}

void TestStore()
{
	CFile file;
	file.Open("C:\\obj.dat", CFile::modeCreate | CFile::modeWrite);

	//定义存储的ar
	CArchive ar(&file, CArchive::store);

	CAnimal *pAnimal  = new CAnimal();
	pAnimal->m_nLeg = 9;
	pAnimal->m_strName = "青青";
	pAnimal->m_nHand = 5555;
	

	//animal.Serialize(ar);

	ar << pAnimal;

	ar.Close();

	file.Close();
}

void TestLoad()
{
	CFile file;
	file.Open("C:\\obj.dat",  CFile::modeRead);

	//定义存储的ar
	CArchive ar(&file, CArchive::load);

	CAnimal animal;


	//读取对象内数据
	//animal.Serialize(ar);


	//读取对象
	CAnimal *pAnimal = NULL;
	ar >> pAnimal;

	cout << pAnimal->m_nLeg << endl;
	cout << (LPCTSTR)pAnimal->m_strName << endl;
	cout << pAnimal->m_nHand << endl;
	ar.Close();

	file.Close();
}



int _tmain(int argc, TCHAR* argv[], TCHAR* envp[])
{
	TestStore();
	TestLoad();
	return 0;
}


