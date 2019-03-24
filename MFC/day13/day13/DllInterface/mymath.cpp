#include "stdafx.h"

#include "mymath.h"


class CMyMath : public IMath
{
	
public:
	virtual int Add(int nAdd1, int nAdd2) ;
	virtual int Sub(int nSub1, int nSub2) ;


	virtual int AddRef() ;
	virtual int Release() ;

	CMyMath();

public:
	LONG m_nRef;
};

CMyMath::CMyMath()
{
	m_nRef = 0;
}


int CMyMath :: Add(int nAdd1, int nAdd2)
{
	return nAdd1 + nAdd2;
}

int CMyMath::Sub(int nSub1, int nSub2)
{
	return nSub1 - nSub2;
}



int CMyMath::AddRef()
{
	InterlockedIncrement(&m_nRef);
	return m_nRef;
}


int CMyMath::Release()
{
	InterlockedDecrement(&m_nRef);
	if(0 == m_nRef)
	{
		delete this;
	}
	return m_nRef;
}

IMath * CreateInstance()
{
	return new CMyMath();
}

