﻿#include "stdafx.h"
#include "SpecialTechTest.h"
#include <string>

using std::cout;
using std::endl;
using std::bad_cast;
using std::string;

void memOperTest(void)
{
    /*
        #### 控制内存分配 ####

        使用new表达式时，
        string *sp = new string("a value");
        string *arr = new string[10];
        执行了三步操作：
        1. new表达式调用operator new或operator new[]的标准库函数，
        分配一块足够大的、原始的、未命名的内存空间
        2. 调用相应的构造函数构造对象，传入初值
        3. 返回指向该对象的指针
        使用delete表达式时，
        delete sp;
        delete [] arr;
        执行了两步操作：
        1. 对sp指向的对象或arr指向的数组中的元素执行对应的析构函数
        2. 调用operator delete或operator delete[]的标准库函数释放内存空间

        重载时，可以在全局作用域重载，也可以将其定义为成员函数。
        编译器发现new或delete表达式时，先在程序中查找可调用的函数：
        如果new或delete的对象是类类型，则现在类及其基类作用域中查找，
        再到全局作用域查找，都没有找到自定义的版本，则调用标准库的版本。
        可以在代码中使用全局作用域运算符显式(::new)调用全局作用域的new和delete
    */
}

void rttiTest(void)
{
    /*
        #### 运行时类型识别RTTI (Run-time type identification) ####

        用两个运算符实现：
        - typeid：返回表达式的类型
        - dynamic_cast：将基类指针或引用安全转换成派生类的指针或引用

        dynamic_cast使用形式：
        dynamic_cast<type*>(e)          e必须是一个有效指针
        dynamic_cast<type&>(e)          e是左值
        dynamic_cast<type&&>(e)         e不能是左值

        type必须是类类型，通常情况下有虚函数
        e必须满足以下三个条件之一：
        - e的类型是type的公有派生类
        - e的类型是type的公有基类
        - e的类型是type的类型
        如符合，类型转换成功
        如不满足，且转换目标是指针类型，则结果为0
        如不满足，且转换类型为引用类型，则抛出bad_cast异常

        typeid表达式的形式：typeid(e)
        e是任意表达式或类型名
        返回类型为type_info（typeinfo头文件）或其公有派生类的常量对象引用，可以使用name()成员函数打印编译器定义的类型名
        当e不是类类型或是不包含虚函数的类时，返回运算对象的静态类型，意即即是是指向派生类的基类指针，也会返回基类指针类型
    */
    BaseClassForCast baseIns = BaseClassForCast();
    DerivedClassForCast dervIns = DerivedClassForCast();

    // 基类指针指向派生类
    BaseClassForCast *basePtr = &dervIns;
    // 从基类指针转换为派生类指针
    // 在if语句内判断是否转换成功，能保重紧随其后的代码分情况处理
    if (DerivedClassForCast *dervPtr = dynamic_cast<DerivedClassForCast*>(basePtr))
    {
        cout << "dynamic_cast(pointer) success!" << endl;
        // 成功，dervPtr指向派生类对象
    }
    else
    {
        cout << "/!\\dynamic_cast(pointer) fail!" << endl;
        // 失败，dervPtr指向基类对象
    }

    // 基类引用引用派生类对象
    BaseClassForCast &baseRef = dervIns;
    try
    {
        DerivedClassForCast &dervRef = dynamic_cast<DerivedClassForCast&>(baseRef);
        cout << "dynamic_cast(reference) success!" << endl;
    }
    catch (bad_cast)
    {
        cout << "/!\\dynamic_cast(reference) fail!" << endl;
    }

    // 之前if条件内的定义作用域已经结束，再次定义
    DerivedClassForCast *dervPtr = dynamic_cast<DerivedClassForCast*>(basePtr);
    // typeid()作用域对象，所以指针要解引用
    if (typeid(*basePtr) == typeid(*dervPtr))
    { cout << "basePtr and dervPtr are the same." << endl; }
    else
    { cout << "/!\\basePtr and dervPtr are NOT the same." << endl; }
    if (typeid(*basePtr) == typeid(DerivedClassForCast))
    { cout << "basePtr is DerivedClassForCast." << endl; }
    else
    { cout << "/!\\basePtr is NOT DerivedClassForCast." << endl; }

    // 打印各种类型名，type_info类的实现在各种编译器上有所不同
    cout << endl
        << "Different type_info names:" << endl
        << "123: " << typeid(123).name() << endl
        << "12.34: " << typeid(12.34).name() << endl
        << "'c': " << typeid('c').name() << endl
        << "\"string\"" << typeid("string").name() << endl
        << "string(\"string\")" << typeid(string("string")).name() << endl
        << endl;
}

void enumTest(void)
{
    cpuNamesScoped cpuScoped;
    cpuScoped = cpuNamesScoped::cpuPpc; // 必须使用枚举成员赋值，不能用常量赋值
    cpuNamesUnscoped cpuUnscoped = cpuPpc;
    int scopedPPC = cpuNamesUnscoped::cpuPpc; // 不限定作用域的枚举成员可以隐式转换为整型
    cout << "scoped enumeration: " << endl
        << "cpuIntel: " << static_cast<int>(cpuNamesScoped::cpuIntel) << endl
        << "cpuAmd: " << static_cast<int>(cpuNamesScoped::cpuAmd) << endl
        << "cpuArm: " << static_cast<int>(cpuNamesScoped::cpuArm) << endl
        << "cpuPpc: " << static_cast<int>(cpuNamesScoped::cpuPpc) << endl;
    cout << "unscoped enumeration: " << endl
        << "cpuIntel: " << cpuIntel << endl
        << "cpuAmd: " << cpuAmd << endl
        << "cpuArm: " << cpuArm << endl
        << "cpuPpc: " << cpuPpc << endl;
    cout << endl;
}

void specialTechTest(void)
{
    memOperTest();
    rttiTest();
    enumTest();
}
