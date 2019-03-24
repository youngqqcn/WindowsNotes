#ifndef _MATH_H_
#define _MATH_H_

#include "stdafx.h"

// {50FBC698-597C-4edf-93EC-6E5EC065E79F}
static const GUID IMath1 = 
{ 0x50fbc698, 0x597c, 0x4edf, { 0x93, 0xec, 0x6e, 0x5e, 0xc0, 0x65, 0xe7, 0x9f } };

struct IMath
{
public:
	virtual int Add(int nAdd1, int nAdd2) = 0;
	virtual int Sub(int nSub1, int nSub2) = 0;


	virtual int AddRef() = 0;
	virtual int Release() = 0;


	
	int QueryInterface(GUID iid, void **ppiInterface);

};


#endif