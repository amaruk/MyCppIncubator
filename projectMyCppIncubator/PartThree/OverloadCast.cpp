#include "stdafx.h"
#include "OverloadCast.h"
#include <string>

using std::ostream;
using std::cout;
using std::endl;
using std::string;

ostream & operator<<(ostream &os, const OverloadCast &ins)
{
    // 不应打印换行符
    os << "[Overload] " << ins.memStr;
    return os;
}

void testOverloadCast(void)
{
    OverloadCast ocIns = OverloadCast("Initialized.");
    cout << ocIns << endl;
}
