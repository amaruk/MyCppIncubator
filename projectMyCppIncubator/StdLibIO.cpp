#include "stdafx.h"
#include "StdLibIO.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using std::cin;
using std::endl;
using std::cout;
using std::cerr;
using std::istream;
using std::string;

StdLibIO::StdLibIO()
{
}


StdLibIO::~StdLibIO()
{
}

void getCinStateBits(void)
{
    // 查看constexpr标志位的值，可用于位操作置或清标志位
    cout << "istream bit: badbit[" << istream::badbit   // 系统级错误，流已崩溃
        << "] failbit[" << istream::failbit             // IO操作失败，可修正继续使用
        << "] eofbit[" << istream::eofbit               // 流到达文件结束，会同时置fail
        << "] gootbit[" << istream::goodbit             // 流未处于错误状态
        << "]" << endl;
}

void getCinStateFunc(void)
{
    cout << "istream bitfun: bad()[" << cin.bad()       // badbit置位时返回true
        << "] fail()[" << cin.fail()                    // failbit或bad置位时返回true
        << "] eof()[" << cin.eof()                      // eofbit置位时返回true
        << "] good()[" << cin.good()                    // 流处于有效状态时返回true
        << "]" << endl;
}

void StdLibIO::conditionState(void)
{
    // iostate是机器相关的类型，提供了表达条件状态的完整功能
    istream::iostate curCondStat = cin.rdstate(); // rdstate()返回当前条件状态
    getCinStateBits();
    cout << "---Initial---" << endl;
    getCinStateFunc();

    // 输入的类型和期望类型不匹配，产生fail
    int intInput = 0;
    cout << "---Test fail. Expect int, but enter string.---" << endl;
    cin >> intInput;
    getCinStateFunc();

    // 需要清除错误状态，才能继续使用
    cout << "---Clear cin.---" << endl;
    cin.clear(); // 所有条件状态位复位，流状态置为有效
    getCinStateFunc();

    // 输入EOF，产生eof和fail
    char charAryInput[50];
    cout << "---Test EOF. Enter Ctrl+D (Unix) or Ctrl+Z (Win)---" << endl;
    cin >> charAryInput; // 把之前输入的字符串读取掉
    cin >> charAryInput;
    getCinStateFunc();

    // 需要清除错误状态，才能继续使用
    cout << "---Bit clear cin.---" << endl;
    cin.clear(cin.rdstate() & ~cin.failbit & ~cin.eofbit); // 用位操作清除fail和eof位
    getCinStateFunc();
}
