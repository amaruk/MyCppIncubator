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

void testOverloadCast(void)
{
    OverloadCast ocIns = OverloadCast("Initialized.");
    cout << ocIns << endl; // 测试输出重载
    cin >> ocIns; // 测试输入重载
    cout << ocIns << endl;
}
