// Cpp17Features.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <variant>
#include <iostream>
#include <any>

using std::cout;
using std::endl;
using std::variant;
using std::any;
using std::any_cast;
using std::get;

int main()
{
    variant<any> var;
    var = 5;
    cout << any_cast<int>(get<any>(var)) << endl;
    return 0;
}

