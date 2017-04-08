// projectMyCppIncubator.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "CppPrimer.h"
#include <iostream>
using std::cout;
using std::endl;
using std::cin;


int main(int argc, char *argv[])
{
	cout << "Hello, my C++ incubator" << endl;

	CppPrimer cppPrimerIns = CppPrimer();
	//cppPrimerIns.displayArithTypes();
	//cppPrimerIns.varInitTest();
	//cppPrimerIns.ptrRefTest();
	//cppPrimerIns.stringTest();
	//cppPrimerIns.vectorTest();
	//cppPrimerIns.iteratorTest();
	//cppPrimerIns.arrayTest();
    cppPrimerIns.exceptionTest();

	// 系统调用 "Press any key to continue..."
	//system("pause");

    return 0;
}

