#include "stdafx.h"
#include "OOP.h"
#include <iostream>

using std::cout;
using std::endl;

OperatingSystem::OperatingSystem()
{
}


OperatingSystem::~OperatingSystem()
{
}

void testOOP(void)
{
    /*
        面向对象程序设计三个基本概念：
        - 数据抽象： 把现实生活的事物抽象为类，将类的接口与实现分离
        - 继承：定义相似的类型并对其相似关系建模
        - 动态绑定：在一定程度忽略类型区别，以统一的方式使用它们的对象

        继承inheritance关系的基础是基类Base class，其他类直接或间接从基类继承，称为派生类derived class

        基类把希望派生类各自实现的函数声明为虚函数virtual function
    */
    cout << "Test OperatingSystem" << endl;
}
