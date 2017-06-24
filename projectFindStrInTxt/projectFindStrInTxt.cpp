// projectFindStrInTxt.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <fstream>

using std::ifstream;

void runQuery(ifstream &inFile)
{
    // 创建查询类实例


    // 提示用户输入查询的单词

}

int main()
{
    ifstream iFileToBeQueried; // 创建文件流但不绑定文件
    iFileToBeQueried.open(".\\Resources\\queryMe.txt"); // 以默认模式绑定文件
    if (iFileToBeQueried.is_open())
    { runQuery(iFileToBeQueried); }
    return 0;
}

