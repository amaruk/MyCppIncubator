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
    // argv[0]是程序自身的名字
    for (int i = 0; i != argc; i++)
    { cout << argv[i] << " "; }
    cout << endl;

	CppPrimer cppPrimerIns = CppPrimer();
	//cppPrimerIns.displayArithTypes();
	//cppPrimerIns.varInitTest();
	//cppPrimerIns.ptrRefTest();
	//cppPrimerIns.stringTest();
	//cppPrimerIns.vectorTest();
	//cppPrimerIns.iteratorTest();
	//cppPrimerIns.arrayTest();
    //cppPrimerIns.exceptionTest();
    //cppPrimerIns.functionTest();
    cppPrimerIns.assertTest();

	// 系统调用 "Press any key to continue..."
	//system("pause");

    // 允许main没有return语句直接结束，编译器插入返回0的return语句表示执行成功
    return 0;
}

