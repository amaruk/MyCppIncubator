#pragma once
#include <iostream>
#include <memory>
#include <set>
#include "TextQuery.h"

class QueryResult // 处理查询的结果
{
    friend std::ostream &print(std::ostream &os, const QueryResult &qrIns);
public:
    QueryResult(std::string w,
        std::shared_ptr<std::set<TextQuery::type_LineNum>> l,
        std::shared_ptr<std::vector<std::string>> f) :
        queryWord(w), lines(l), file(f) {}
private:
    std::string queryWord; // 查询的单词
    std::shared_ptr<std::set<TextQuery::type_LineNum>> lines; // 出现的行号
    std::shared_ptr<std::vector<std::string>> file; // 被查询的文件
};

