// projectMyCppIncubator.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "CppPrimer.h"
#include "CppPrimerFriend.h"
#include "CppPrimerAggregate.h"
#include "CppPrimerLiteral.h"
#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::cin;
using std::string;

// Part one: C++����
void partOne(void)
{
    // �������ʽ
    const int constIntVar1 = 20; // constIntVar1�ǳ������ʽ
    const int constIntVar2 = constIntVar1 + 1; // constIntVar2�ǳ������ʽ
    int nonConstIntVar = 27; // nonConstIntVar���ǳ������ʽ����Ȼ��ʼֵΪ������������Ϊ��ͨint
                             //const int constIntVar3 = get_size(); // constIntVar3���ǳ������ʽ����Ϊ��ֵ������ʱ�ŵõ�

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
    // ��ʽ������ת����bool��������ʽת��Ϊ����CppPrimer(bool boolInitVal)����Ķ���
    //cppPrimerCharIns.convertingConstructorTest(false);
    // ȥ��CppPrimer(CppPrimerStr initStr)�����explicit�ؼ��֣������������������ʽ������ת��
    //cppPrimerCharIns.convertingConstructorTest(string("test"));
    CppPrimer cppPrimerDefaultIns = CppPrimer();
    CppPrimer &cppPrimerRef = cppPrimerDefaultIns;
    CppPrimer *cppPrimerPtr = &cppPrimerDefaultIns;
    cppPrimerDefaultIns.staticFuncTest(string("Zero")); // �������ʾ�̬��Ա����
    cppPrimerRef.staticFuncTest(string("First")); // ��������÷��ʾ�̬��Ա����
    cppPrimerPtr->staticFuncTest(string("Second")); // �����ָ����ʾ�̬��Ա����
                                                    // �����������ֱ�ӷ��ʾ�̬��Ա����
    CppPrimer::staticFuncTest(string("Thrid"));

    CppPrimerFriend cppPrimerFriendIns = CppPrimerFriend();
    //cppPrimerFriendIns.useCppPrimerPrivate(cppPrimerIns);
    //cppPrimerIns.toBeFriendOfCppPrimerFriend(cppPrimerFriendIns);

    // �����ۺ����ʵ��
    CppPrimerAggregate cppPrimerAggregateIns = CppPrimerAggregate();
    // ������˳���ʵ���б��ʼ���ۺ���
    CppPrimerAggregate cppPrimerAggregateInsInit = { string("Hello"), 123 };

    // ��������ֵ������ʵ��
    CppPrimerLiteral cppPrimerLiteralIns = CppPrimerLiteral(false);
}

// Part two: C++��׼��
void partTwo(void)
{

}

int main(int argc, char *argv[])
{
    // main�����в���
    // argv[0]�ǳ������������
    for (int i = 0; i != argc; i++)
    { cout << argv[i] << " "; }
    cout << endl;

	// ϵͳ���� "Press any key to continue..."
	//system("pause");

    // ����mainû��return���ֱ�ӽ��������������뷵��0��return����ʾִ�гɹ�
    return 0;
}

