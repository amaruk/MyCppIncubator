#include "stdafx.h"
#include "OverloadCast.h"
#include <string>

using std::ostream;
using std::istream;
using std::cout;
using std::cin;
using std::endl;
using std::string;

ostream & operator<<(ostream &os, const OverloadCast &ins)
{
    // 不应打印换行符，让调用者自行换行
    os << "[Overload] " << ins.memStr;
    return os;
}

istream & operator>>(istream & is, OverloadCast & ins)
{
    is >> ins.memStr;

    if (!is) // 输入失败
    { ins.memStr = "istream fail"; }

    return is;
}

OverloadCast & OverloadCast::operator+=(const OverloadCast & rhs)
{
    this->memStr += " + ";
    this->memStr += rhs.memStr;
    return *this;
}

OverloadCast operator+(const OverloadCast & lhs, const OverloadCast & rhs)
{
    // 如果同时重载了符合赋值运算符+=，一般用复合赋值运算符来实现算术运算符
    OverloadCast result = lhs;
    result += rhs;
    return result;
}


void testOverloadCast(void)
{
    OverloadCast ocIns = OverloadCast("Initialized.");
    cout << "Original value:";
    cout << ocIns << endl; // 测试输出重载 
    cout << "Enter new value: ";
    cin >> ocIns; // 测试输入重载
    cout << "New value: ";
    cout << ocIns << endl << endl;

    cout << "Test overload +" << endl;
    OverloadCast ocLhs = OverloadCast("Left");
    OverloadCast ocRhs = OverloadCast("Right");
    OverloadCast ocRst = ocLhs + ocRhs; // 测试算术运算符重载
    cout << ocRst << endl << endl;
}
