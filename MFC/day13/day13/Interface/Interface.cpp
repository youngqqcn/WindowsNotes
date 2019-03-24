// Interface.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
using namespace std;

class IMath
{
public:
	virtual int Add(int nAdd1, int nAdd2) = 0;
	virtual int Sub(int nSub1, int nSub2) = 0;
};


class CImpMath1 : public IMath
{
public:
	virtual int Add(int nAdd1, int nAdd2)
	{
		return nAdd1 + nAdd2;
	}
	virtual int Sub(int nSub1, int nSub2)
	{
		return nSub1 - nSub2;
	}
};


IMath * CreateInstance()
{
	return new CImpMath1;
}




int main(int argc, char* argv[])
{
	IMath * piMath =  CreateInstance();
	std::cout <<	piMath->Add(100, 100)  << endl;


	printf("Hello World!\n");
	return 0;
}

