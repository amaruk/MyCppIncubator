#include "stdafx.h"
#include "ClassFeatures.h"
#include <iostream>

using std::cout;
using std::endl;
using std::string;

ClassFeatures::ClassFeatures()
{
    cout << "/!\\ default constructor" << endl;
    this->memStr = string("Default");
}


ClassFeatures::ClassFeatures(const ClassFeatures & cfIns)
{
    cout << "/!\\ copy constructor" << endl;
    this->memStr = cfIns.memStr;
}

ClassFeatures::~ClassFeatures()
{
    cout << "/!\\ destructor" << endl;
}

ClassFeatures & ClassFeatures::operator=(const ClassFeatures & rgtIns)
{
    cout << "/!\\ copy-assignment operator" << endl;
    this->memStr = rgtIns.memStr;
    return *this; // 返回此对象的引用
}

void ClassFeatures::displayMem(void)
{
    cout << "Instance members: "
        << "memStr[" << this->memStr << "] "
        << endl;
}

void ClassFeatures::setMem(const string memStrVal)
{
    this->memStr = memStrVal;
}

void testClassFeatures(void)
{
    // 直接初始化
    ClassFeatures cfInsDefault = ClassFeatures();
    cout << "1. ";
    cfInsDefault.displayMem();
    cfInsDefault.setMem("setMem");
    cout << "2. ";
    cfInsDefault.displayMem();

    // 虽然调用了拷贝构造函数，但是使用普通的函数匹配，是直接初始化
    ClassFeatures cfInsCallCopyConst = ClassFeatures(cfInsDefault);
    cout << "3. ";
    cfInsCallCopyConst.displayMem();
    cfInsCallCopyConst.setMem("Changed");
    /*
        拷贝初始化发生在如下情况：
        - 用=直接赋值
        - 将对象作为实参传给非引用类型的形参
        - 返回非引用类型的函数返回对象
        - 用花括号列表初始化数组的元素或聚合类的成员
    */

    // 拷贝初始化
    ClassFeatures cfInsCopyConstruct = cfInsCallCopyConst;
    cout << "4. ";
    cfInsCopyConstruct.displayMem();

    // 拷贝赋值运算符
    cfInsCopyConstruct = cfInsDefault;
    cout << "5. ";
    cfInsCopyConstruct.displayMem();

    /*
        调用析构函数的情况：
        - 变量离开作用域时被销毁
        - 当一个对象被销毁时，其成员被销毁
        - 容器被销毁时，其元素被销毁
        - 动态分配的对象，当指向其的指针应用delete运算符时被销毁
        - 创建临时对象的完整表达式结束时，临时对象被销毁
    */

}
