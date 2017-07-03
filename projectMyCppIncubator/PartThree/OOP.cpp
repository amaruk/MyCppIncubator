#include "stdafx.h"
#include "OOP.h"
#include <string>

using std::cout;
using std::endl;
using std::string;


void OperatingSystem::osRootInfo(void)
{
    cout << "OS ROOT INFO" << endl;
}

void OperatingSystem::dispOsName(void) const
{
    cout << "OS name: " << osName << endl;
}

void OperatingSystem::dispOsVer(void) const
{
    cout << "OS ver: " << osVer << endl;
}

void OperatingSystem::dispOsOpenSource(void) const
{
    cout << "OS open source: " << osIsOpen << endl;
}

const std::string OSWindows::companyName = string("Microsoft");
void OSWindows::dispOsName(void) const
{
    cout << OSWindows::companyName << " Product: " << osName << ". Embedded: " << isEmbedded << endl;
}

void printOsInfo(OperatingSystem &osIns)
{
    osIns.dispOsName();
    osIns.dispOsVer();
    osIns.dispOsOpenSource();
}

void testOOP(void)
{
    /*
    面向对象程序设计三个基本概念：
    - 数据抽象： 把现实生活的事物抽象为类，将类的接口与实现分离
    - 继承：定义相似的类型并对其相似关系建模
    - 动态绑定：在一定程度忽略类型区别，以统一的方式使用它们的对象

    继承inheritance关系的基础是基类Base class，其他类直接或间接从基类继承，称为派生类derived class

    动态绑定dynamic binding：又名运行时绑定run-time binding。
    使用基类的引用或指针调用虚函数时，动态决定调用哪个类的函数。即把派生类对象当作基类对象使用。
    称为派生类到基类derived-to-base类型转换

    静态类型static type：编译时已知，是变量声明是的类型或表达式生成的类型
    动态类型dynamic type：变量或表达式表示的内存中对象的类型
    表达式如果不是引用也不是指针，其动态类型和静态类型永远一致

    直接基类direct base，派生类对于基类
    间接基类indirect base，派生类的派生类对于基类

    用基类的默认（合成）拷贝和赋值操作派生类对象，只能操作基类定义的成员，派生类独有的成员被切除sliced down

    */
    OperatingSystem baseOS = OperatingSystem(string("Abstract OS"), 0, true);
    OSWindows dervWin = OSWindows(string("Windows"), 10, false, false);

    cout << "### Test virtual and override." << endl;
    cout << endl << "<OS CLASS:>" << endl;
    printOsInfo(baseOS);
    cout << endl << "<WINDOWS CLASS:>" << endl;
    printOsInfo(dervWin);
    cout << endl;

}
