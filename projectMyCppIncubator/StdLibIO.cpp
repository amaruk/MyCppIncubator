#include "stdafx.h"
#include "StdLibIO.h"
#include <iostream>
#include <fstream>
#include <sstream>

using std::cin;
using std::endl;
using std::cout;
using std::cerr;
using std::istream;

StdLibIO::StdLibIO()
{
}


StdLibIO::~StdLibIO()
{
}

void StdLibIO::conditionState(void)
{
    // iostate是机器相关的类型，提供了表达条件状态的完整功能
    istream::iostate curCondStat = cin.rdstate(); // rdstate()返回当前条件状态
}
