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
    // argv[0]�ǳ������������
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
    cppPrimerIns.functionTest();

	// ϵͳ���� "Press any key to continue..."
	//system("pause");

    // ����mainû��return���ֱ�ӽ��������������뷵��0��return����ʾִ�гɹ�
    return 0;
}

