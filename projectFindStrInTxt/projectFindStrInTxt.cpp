// projectFindStrInTxt.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <fstream>
#include <iostream>
#include "QueryResult.h"
#include "TextQuery.h"
#include <string>

using std::ifstream;
using std::cout;
using std::cin;
using std::endl;
using std::string;

void runQuery(ifstream &inFile)
{
    // 创建查询类实例
    TextQuery newQuery(inFile);

    // 提示用户输入查询的单词
    while (true)
    {
        cout << "Enter your query word. Type \"q\" to quit." << endl;
        string queryWord;
        if (!(cin >> queryWord) || queryWord == "q")
        { break; }
        print(cout, newQuery.query(queryWord));
    }
}

int main()
{
    ifstream iFileToBeQueried; // 创建文件流但不绑定文件
    iFileToBeQueried.open(".\\Resources\\queryMe.txt"); // 以默认模式绑定文件
    if (iFileToBeQueried.is_open())
    { runQuery(iFileToBeQueried); }
    return 0;
}

