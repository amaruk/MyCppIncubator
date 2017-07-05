#include "stdafx.h"
#include "StdLibTest.h"
#include <tuple>
#include <iostream>
#include <string>
#include <vector>
#include <bitset>
#include <regex>

using std::tuple;
using std::tuple_size;
using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::get;
using std::bitset;
using std::regex;
using std::smatch;

void tupleTest(void)
{
    /*
        C++11: tuple类似pair，不同tuple类型可以有任意数量的成员。
        用途:希望将一些数据组合成单一对象,但又不想定义一个新数据结构。如从函数返回多个数据。

        tuple<T1, ..., Tn> t                定义一个tuple，成员数为n，类型为T1/T2/...，值初始化
        tuple<T1, ..., Tn> t(v1, ..., vn)   定义一个tuple，成员用对于的v值初始化，此构造函数explicit
        make_tuple(v1, ..., vn)             返回用v值初始化的tuple
        t1 == t2                            t1和t2数量相同且成员相等时返回true
        t1 != t2
        t1 relop t2                         用字典序比较
        get<i>(t)                           返回第i个数据成员的引用（可能为左值引用也可能为右值引用）
        tuple_size<typleType>::value        用typle类型初始化的类模板，其public constexpr static的value数据成员，
                                            类型为size_t，表示tuple中成员数量
        tuple_element<i, typleType>::type   用整型常量和tuple类型初始化的类模板，其public的type成员表示tuple中指定成员的类型
    */
    tuple<int, char, string, vector<int>> tupleLoft{ 123, 'a', "ABC", vector<int>{1, 2, 3, 4} };

    cout << "## tuple test." << endl;
    cout << "tuple size: " << tuple_size<decltype(tupleLoft)>::value << endl;
    // 无法通过普通的方法遍历tuple容器, 因为"get<>()"方法, 无法使用变量获取值
    cout << "tuple get<0>: " << get<0>(tupleLoft) << endl;
    cout << "tuple get<1>: " << get<1>(tupleLoft) << endl;
    cout << "tuple get<2>: " << get<2>(tupleLoft) << endl;
    cout << "tuple get<3>: " << get<3>(tupleLoft)[3] << endl;
    cout << endl;
}

void bitsetTest(void)
{
    /*
        bitset类似array类，位置编号从0（低位low-order)开始，结束的编号为高位high-order

        bitset<n> b;                b有n位，每位均为0，此构造函数是constexpr
        bitset<n> b(u);             b是unsigned long long值u的低n位拷贝，如果n大于u的大小，b的高位置0
        bitset<n> b(s,pos,m,zero,one);
                                    s是string，只能包含字符zero或one，否则构造函数抛出invalid_argument异常
                                    从s的pos位置开始，拷贝m个字符到b
                                    pos默认为0
                                    m默认为string::npos
                                    zero默认为'0'
                                    one默认为'1'
        bitset<n> b(cp,pos,m,zero,one);
                                    cp不是string而是c风格的字符串

        b.any()                     b中是否有置位的二进制位
        b.all()                     b中是否所有位都置位
        b.none()                    b中是否所有位都未置位
        b.count()                   b中置位的位数
        b.size()                    b的位数
        b.test(pos)                 pos位置是否置位
        b.set(pos,v)                pos位置上置bool值v
        b.set()                     所有位置位
        b.reset(pos)                pos位置复位
        b.reset()                   复位所有位
        b.flip(pos)                 pos位反转
        b.flip()                    反转所有位
        b[pos]                      方位pos位置的位
        b.to_ulong()                返回unsigned long
        b.to_ullong()               返回unsigned long long
        b.to_string(zero,one)       返回一个string表示b的位模式，zero默认为‘0’，one默认为‘1’，表示b中的位值
        os << b                     将b中二进制位打印为字符1或0
        is >> b                     读取字符存入b，如输入字符不为1或0，或已经读到b.size()字符时，终止
    */
    cout << "## bitset test." << endl;

    // cout默认右对齐，需要左对齐时设置如下
    //cout.setf(std::ios::left);

    // 0xBEEF二进制为 1011 1110 1110 1111
    cout.width(32);
    cout << "1011111011101111";
    cout << " : 0xBEEF" << endl;

    bitset<13> bsSmall(0xBEEF); // bitset位数少，截取
    cout.width(32);
    cout << bsSmall;
    cout << " : small bitset" << endl;

    bitset<20> bsBig(0xBEEF); // bitset位数多，高位补0
    cout.width(32);
    cout << bsBig;
    cout << " : big bitset" << endl;

    bitset<8> bsByte(0x00);
    cout << "bsByte: " << bsByte << endl;
    cout << "bsByte.size(): " << bsByte.size() << endl;
    cout << "bsByte.any(): " << bsByte.any() << endl;
    cout << "bsByte.all(): " << bsByte.all() << endl;
    cout << "bsByte.none(): " << bsByte.none() << endl;
    cout << "bsByte.count(): " << bsByte.count() << endl;
    cout << "bsByte.test(0): " << bsByte.test(0) << endl;
    cout << "bsByte.set(0,1): " << bsByte.set(0, 1) << endl;
    cout << "bsByte.any(): " << bsByte.any() << endl;
    cout << "bsByte.count(): " << bsByte.count() << endl;
    cout << "bsByte.test(0): " << bsByte.test(0) << endl;
    cout << "bsByte.reset(0): " << bsByte.reset(0) << endl;
    cout << "bsByte.test(0): " << bsByte.test(0) << endl;
    cout << "bsByte.flip(): " << bsByte.flip() << endl;
    cout << "bsByte.all(): " << bsByte.all() << endl;
    cout << "bsByte.count(): " << bsByte.count() << endl;

}

void regularExpressionTest(void)
{
    /*
        regex                           有一个正则表达式的类
        regex_match（seq, m, r, mft)    将一个字符序列与一个正则表达式匹配
                                        在字符序列seq中查找regex对象r中的正则表达式
                                        seq可以是string、表示范围的一对迭代器、指向空字符结尾的字符数组指针
                                        m是一个match对象，用来保存匹配结果，m和seq必须是兼容类型
                                        mft是可选的regex_constants::match_flag_type值
        regex_search                    寻找第一个与正则表达式匹配的子序列
        regex_replace                   用给定格式替换一个正则表达式
        sregex_iterator                 迭代器适配器，用regex_search遍历一个string中所有匹配的子串
        smatch                          容器类，保存在string中搜索的结果
        ssub_match                      string中匹配的子表达式结果
    */

    cout << "## regular expression test." << endl;

    string pattern("^[a-zA-Z0-9_-]+@[a-zA-Z0-9_-]+(\\.[a-zA-Z0-9_-]+)+$"); // 正则表达式
    regex reg(pattern); // 用正则表达式初始化用于查找模式的regex
    smatch results; // 保存搜索结果
    string shallNotMatch("notmatch#mail.com");
    string shallMatch("match@mail.com");
    
    if (regex_search(shallNotMatch, results, reg))
    { cout << "Match!: " << results.str() << endl; }
    else
    { cout << "Not match: " << shallNotMatch << endl; }

    if (regex_search(shallMatch, results, reg))
    { cout << "Match!: " << results.str() << endl; }
    else
    { cout << "Not match: " << shallMatch << endl; }

    cout << endl;

}

void stdLibTest(void)
{
    tupleTest();
    bitsetTest();
    regularExpressionTest();
}
