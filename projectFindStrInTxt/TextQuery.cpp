#include "stdafx.h"
#include "TextQuery.h"
#include "QueryResult.h"
#include <iostream>
#include <string>
#include <sstream>


using std::ifstream;
using std::string;
using std::vector;
using std::istringstream;
using std::set;
using std::shared_ptr;
using std::ostream;
using std::endl;

// 冒号后为类成员的初始值列表（初始化器）
TextQuery::TextQuery(ifstream & inFile) : vec_str_FileContent(new vector<string>)
{
    string curLine;

    while (getline(inFile, curLine))
    {
        vec_str_FileContent->push_back(curLine);
        int curLineNum = static_cast<int>(vec_str_FileContent->size()) - 1; // 当前行号

        // 将一行字符分解为单词
        string curWord;
        istringstream lineStream(curLine);
        while (lineStream >> curWord)
        {
            // 如果单词不在map里，以其为下标插入map
            auto &shrdptr_LineNums = map_str_shdptr_WordLineNums[curWord]; // lineNums是shared_ptr
            if (!shrdptr_LineNums) // 如果是第一次添加此单词,shared_ptr为空
            {
                shrdptr_LineNums.reset(new set<type_LineNum>); // 在shared_ptr上分配一个新的set
            }
            shrdptr_LineNums->insert(curLineNum); // 在share_ptr指向的set上插入行号
        }
    }
}


// 在map中找到指定单词对应的行号set，构造QueryResult，保存单词/行号的set/被查询的文件vector
QueryResult TextQuery::query(string qWrod) const
{
    // 没有此单词时，返回此指针
    static shared_ptr<set<type_LineNum>> notFound(new set<type_LineNum>);

    auto location = map_str_shdptr_WordLineNums.find(qWrod);
    if (location == map_str_shdptr_WordLineNums.end())
    { return QueryResult(qWrod, notFound, vec_str_FileContent); }
    else
    { return QueryResult(qWrod, location->second, vec_str_FileContent); }

}

ostream &print(ostream &os, const QueryResult &qrIns)
{
    // 打印出现次数
    os << qrIns.queryWord << " occurs " << qrIns.lines->size() << " "
        << "time" << endl;
    // 打印出现的行
    for (auto num : *qrIns.lines)
    {
        os << "\t(line " << num + 1 << ")"
            << *(qrIns.file->begin() + num) << endl;
    }
    os << endl;

    return os;
}
