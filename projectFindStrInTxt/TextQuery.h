#pragma once
#include <fstream>
#include <vector>
#include <map>
#include <set>
#include <memory>

class QueryResult;
class TextQuery // 保持文件，记录单词和所有行号的对应关系
{
public:
    using type_LineNum = std::vector<std::string>::size_type; // 表示行号的类型成员，即vector的下标
    TextQuery(std::ifstream &inFile);
    QueryResult query(std::string qWrod) const;
private:
    std::shared_ptr<std::vector<std::string>> vec_str_FileContent; // 指向动态分配的vector，其中保持着输入文件
    std::map<std::string, std::shared_ptr<std::set<type_LineNum>>> map_str_shdptr_WordLineNums; // map是 单词 和 此单词出现行号的动态分配set 的映射
};

