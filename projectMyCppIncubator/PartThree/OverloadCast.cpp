#include "stdafx.h"
#include "OverloadCast.h"
#include <string>

using std::ostream;
using std::istream;
using std::cout;
using std::cin;
using std::endl;
using std::string;

ostream & operator<<(ostream &os, const OverloadTest &ins)
{
    // 不应打印换行符，让调用者自行换行
    os << "[memStr] " << ins.memStr;
    return os;
}

istream & operator>>(istream & is, OverloadTest & ins)
{
    is >> ins.memStr;

    if (!is) // 输入失败
    { ins.memStr = "istream fail"; }

    return is;
}

OverloadTest & OverloadTest::operator+=(const OverloadTest & rhs)
{
    this->memStr += " + ";
    this->memStr += rhs.memStr;
    return *this;
}

OverloadTest & OverloadTest::operator=(std::initializer_list<std::string> initVals)
{
    int eleNum = 0;

    for (auto itr = initVals.begin(); itr != initVals.end(); itr++, eleNum++)
    {
        this->memStrAry[eleNum] = *itr;
        if (2 == eleNum)
        {
            break;
        }
    }

    return *this;
}

std::string & OverloadTest::operator[](std::size_t idx)
{
    if (idx < 3)
    { return this->memStrAry[idx]; }
    else
    { return this->invalidIndex; }
}

const std::string & OverloadTest::operator[](std::size_t idx) const
{
    if (idx < 3)
    { return this->memStrAry[idx]; }
    else
    { return this->invalidIndex; }
}

OverloadTest & OverloadTest::operator++(void)
{
    // 无实际操作，仅打印输出表示执行
    cout << "++OverloadTest called!" << endl;
    return *this;
}

OverloadTest & OverloadTest::operator--(void)
{
    // 无实际操作，仅打印输出表示执行
    cout << "--OverloadTest called!" << endl;
    return *this;
}

OverloadTest & OverloadTest::operator++(int)
{
    // 一般先拷贝当前值，然后再调用前置版本
    cout << "OverloadTest++ called by calling ";
    ++*this;
    return *this;
}

OverloadTest & OverloadTest::operator--(int)
{
    // 一般先拷贝当前值，然后再调用前置版本
    cout << "OverloadTest-- called by calling ";
    --*this;
    return *this;
}

std::string & OverloadTest::operator*(void)
{
    return this->memStr;
}

std::string * OverloadTest::operator->(void)
{
    // 将实际工作委托给解引用
    // 因为ptr->member相当于(*ptr).member
    return & this->operator*();
}

std::string OverloadTest::operator()(std::string arg) const
{
    return "[Overload ()]: " + arg;
}

void OverloadTest::setMemStr(const string & newStr)
{
    this->memStr = newStr;
}

string OverloadTest::getMemStrAry(void)
{
    return this->memStrAry[0] + " " + this->memStrAry[1] + " " + this->memStrAry[2];
}

OverloadTest operator+(const OverloadTest & lhs, const OverloadTest & rhs)
{
    // 如果同时重载了符合赋值运算符+=，一般用复合赋值运算符来实现算术运算符
    OverloadTest result = lhs;
    result += rhs;
    return result;
}


bool operator==(const OverloadTest & lhs, const OverloadTest & rhs)
{
    return lhs.memStr == rhs.memStr;
}

bool operator<(const OverloadTest & lhs, const OverloadTest & rhs)
{
    return lhs.memStr < rhs.memStr;
}

void testOverload(void)
{
    OverloadTest ocIns = OverloadTest("Initialized.");
    cout << "Test << and >>" << endl;
    cout << "Original value:";
    cout << ocIns << endl; // 测试输出重载 
    cout << "Enter new value: ";
    cin >> ocIns; // 测试输入重载
    cout << "New value: ";
    cout << ocIns << endl << endl;

    cout << "Test overload +" << endl;
    OverloadTest ocLhs = OverloadTest("Left");
    OverloadTest ocRhs = OverloadTest("Right");
    OverloadTest ocRst = ocLhs + ocRhs; // 测试算术运算符重载
    cout << ocRst << endl << endl;

    cout << "Test overload ==" << endl;
    ocLhs.setMemStr("Left");
    ocRhs.setMemStr("Right");
    cout << ocLhs << " == " << ocRhs << " is: " << (ocLhs == ocRhs) << endl;
    ocLhs.setMemStr("Same");
    ocRhs.setMemStr("Same");
    cout << ocLhs << " == " << ocRhs << " is: " << (ocLhs == ocRhs) << endl;

    cout << "Test overload <" << endl;
    ocLhs.setMemStr("Same");
    ocRhs.setMemStr("Same");
    cout << ocLhs << " < " << ocRhs << " is: " << (ocLhs < ocRhs) << endl;
    ocLhs.setMemStr("Samf");
    ocRhs.setMemStr("Same");
    cout << ocLhs << " < " << ocRhs << " is: " << (ocLhs < ocRhs) << endl;
    ocLhs.setMemStr("Same");
    ocRhs.setMemStr("Samf");
    cout << ocLhs << " < " << ocRhs << " is: " << (ocLhs < ocRhs) << endl;
    cout << endl;

    cout << "Test overload ={}" << endl;
    cout << "Current value: ";
    cout << ocIns.getMemStrAry() << endl;
    ocIns = { "val1", "val2", "val3" };
    cout << "Current value: ";
    cout << ocIns.getMemStrAry() << endl << endl;

    cout << "Test overload []" << endl;
    cout << "memStrAry[0]: ";
    cout << ocIns[0] << endl;
    cout << "memStrAry[1]: ";
    cout << ocIns[1] << endl;
    cout << "memStrAry[2]: ";
    cout << ocIns[2] << endl;
    cout << "memStrAry[3]: ";
    cout << ocIns[3] << endl;
    cout << endl;

    cout << "Test overload ++ and --" << endl;
    ++ocIns;
    --ocIns;
    ocIns++;
    ocIns--;
    // 显式调用时，用参数区分前置与后置
    ocIns.operator++();
    ocIns.operator++(0);
    cout << endl;

    cout << "Test overload ()" << endl;
    cout << ocIns("TestArgument") << endl;
    cout << endl;
}



CallableTest::CallableTest()
{
}

CallableTest::~CallableTest()
{
}

void testCallSignature(void)
{

}

void testOverloadCast(void)
{
    //testOverload();
    testCallSignature();
}

