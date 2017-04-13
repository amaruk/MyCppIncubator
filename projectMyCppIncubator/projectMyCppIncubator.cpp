// projectMyCppIncubator.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "CppPrimer.h"
#include "CppPrimerFriend.h"
#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::cin;
using std::string;

int main(int argc, char *argv[])
{
    // argv[0]�ǳ������������
    for (int i = 0; i != argc; i++)
    { cout << argv[i] << " "; }
    cout << endl;

	class CppPrimer cppPrimerIns = CppPrimer(); // ���������ʱ������ǰ�ɲ���class��struct�ؼ���
    //outsideClassFunc(cppPrimerIns);
    //outsideClassFunc(123);
	//cppPrimerIns.displayArithTypes();
	//cppPrimerIns.varInitTest();
	//cppPrimerIns.ptrRefTest();
	//cppPrimerIns.stringTest();
	//cppPrimerIns.vectorTest();
	//cppPrimerIns.iteratorTest();
	//cppPrimerIns.arrayTest();
    //cppPrimerIns.exceptionTest();
    //cppPrimerIns.exceptionTest();
    //cppPrimerIns.functionTest();
    //cppPrimerIns.assertTest();
    //cppPrimerIns.constMemFunction(1).constMemFunction(2); // �ǳ���������÷ǳ����汾
    const CppPrimer cppPrimerConstIns = CppPrimer();
    //cppPrimerConstIns.constMemFunction(3).constMemFunction(4); // ����������ó����汾
    CppPrimer cppPrimerStrIns = CppPrimer(CppPrimer::CppPrimerStrUsing("Hello, constructor!"));
    //friendFunc(cppPrimerStrIns);
    CppPrimer cppPrimerCharIns = CppPrimer('F');

    CppPrimerFriend cppPrimerFriendIns = CppPrimerFriend();
    //cppPrimerFriendIns.useCppPrimerPrivate(cppPrimerIns);
    //cppPrimerIns.toBeFriendOfCppPrimerFriend(cppPrimerFriendIns);

	// ϵͳ���� "Press any key to continue..."
	//system("pause");

    // ����mainû��return���ֱ�ӽ��������������뷵��0��return����ʾִ�гɹ�
    return 0;
}

