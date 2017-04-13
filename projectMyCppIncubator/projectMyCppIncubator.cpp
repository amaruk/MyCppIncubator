// projectMyCppIncubator.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "CppPrimer.h"
#include "CppPrimerFriend.h"
#include "CppPrimerAggregate.h"
#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::cin;
using std::string;

int main(int argc, char *argv[])
{
    // argv[0]是程序自身的名字
    for (int i = 0; i != argc; i++)
    { cout << argv[i] << " "; }
    cout << endl;

	class CppPrimer cppPrimerIns = CppPrimer(); // 声明类对象时，类名前可不加class或struct关键字
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
    //cppPrimerIns.constMemFunction(1).constMemFunction(2); // 非常量对象调用非常量版本
    const CppPrimer cppPrimerConstIns = CppPrimer();
    //cppPrimerConstIns.constMemFunction(3).constMemFunction(4); // 常量对象调用常量版本
    CppPrimer cppPrimerStrIns = CppPrimer(CppPrimer::CppPrimerStrUsing("Hello, constructor!"));
    //friendFunc(cppPrimerStrIns);
    CppPrimer cppPrimerCharIns = CppPrimer('F');
    // 隐式类类型转换，bool参数被隐式转换为调用CppPrimer(bool boolInitVal)构造的对象
    //cppPrimerCharIns.convertingConstructorTest(false);
    // 去掉CppPrimer(CppPrimerStr initStr)构造的explicit关键字，才能用如下语句做隐式类类型转换
    //cppPrimerCharIns.convertingConstructorTest(string("test"));

    CppPrimerFriend cppPrimerFriendIns = CppPrimerFriend();
    //cppPrimerFriendIns.useCppPrimerPrivate(cppPrimerIns);
    //cppPrimerIns.toBeFriendOfCppPrimerFriend(cppPrimerFriendIns);

    // 创建聚合类的实例
    CppPrimerAggregate cppPrimerAggregateIns = CppPrimerAggregate();
    // 用声明顺序的实参列表初始化聚合类
    CppPrimerAggregate cppPrimerAggregateInsInit = { string("Hello"), 123 };


	// 系统调用 "Press any key to continue..."
	//system("pause");

    // 允许main没有return语句直接结束，编译器插入返回0的return语句表示执行成功
    return 0;
}

