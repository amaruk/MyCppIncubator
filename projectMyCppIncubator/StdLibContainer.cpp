#include "stdafx.h"
#include "StdLibContainer.h"
#include <string>
#include <vector>
#include <deque>
#include <list>
#include <forward_list>
#include <array>
#include <iostream>

using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::deque;
using std::list;
using std::forward_list;
using std::array;

StdLibContainer::StdLibContainer()
{
}


StdLibContainer::~StdLibContainer()
{
}

void StdLibContainer::sequenceContainer(void)
{
    // 容器：特定类型对象的集合
    // 顺序容器：提供控制元素存储和访问顺序的能力顺序与元素加入容器时的位置对应

    //// 各种顺序容器类型
    // vector 可变大小数组，支持快速随机访问，尾部之外插入或删除元素可能很慢
    // string 与vector相似，专门用于保存字符，随机访问快，在尾部插入或删除速度快
    // deque 双端队列，支持快速随机访问，头尾插入或删除很快
    // list 双向链表，只支持双向顺序访问，任何位置插入或删除都很快
    // forward_list 单项链表，只支持单项顺序访问，任何位置插入或删除都很快
    // array 固定大小数组，支持快速随机访问，不能添加或删除元素

    // string和vector的元素保存在连续的内存空间，所以用下标计算地址非常快。
    // 但在中间位置插入或删除时，需要移动后面所有元素来保持连续，
    // 添加元素还可能需要分配额外的存储空间并移动所有元素，所以很耗时。

    // list和forward_list是链表，所以在任意位置添加和删除都很快。
    // 但不支持随机访问，要访问元素必须遍历链表。
    // 和vector、deque、array比，需要额外的内存开销。
    // forward_list没有size操作，为了节省保存或计算大小的额外开销。

    // deque与string和vector类似，支持快速随机访问，但中间位置添加或删除元素代价可能很高。
    // 在两端添加或删除元素速度很快，与list和forward_list速度相当

    // array大小固定，不支持添加或删除，但比内置数组安全、容易使用。

    //// 选择容器的规则
    // - 除非用很好的理由选择其他容器，否则使用vector
    // - 有很多小元素，空间的额外开销很重要，则不要使用list或forward_list
    // - 要求随机访问元素时，使用vector或deque
    // - 要求在中间插入或删除元素，使用list或forward_list
    // - 只在头尾插入或删除元素，使用deque
    // - 如果输入时需要在中间插入元素，随后需要随机访问，可以先用list，再把list的内容拷贝到vector

    vector<char> charVector{ 'a', 'b', 'c' };
    string charString("4 5 6"); 
    deque<char> charDeque = { '7', '8', '9' };
    list<char> charList{ '0', 'a', 'b' };
    forward_list<char> charFarwardList = { 'c', 'd', 'e' };
    array<char, 3> charArray{ 'f', 'g', 'h' };

    //// 容器操作
    /*
        ****类型别名****
        iterator                某容器类型的迭代器类型
        const_iterator          可以读取元素但不能修改元素的迭代器类型
        size_type               无符号整数，足够保存某容器类型最大的容量大小
        difference_type         有符号整数，足够保存两个迭代器之间的距离
        value_type              元素类型
        reference               元素的左值类型，与value_type&含义相同
        const_reference         元素的const左值类型，即const value_type&
        ****构造函数****
        C c;                    默认构造函数，构造空容器
        C c1(c2);               构造c2的拷贝c1
        C c(b, e);              构造c，将迭代器b和e指定范围的元素拷贝到c（array不支持）
        C c{a, b, c...};        列表初始化c
        ****赋值与swap****
        c1 = c2;                z将c1中的元素替换为c2
        c1 = {a, b, c...};      z将c1中的元素替换为列表中元素（array不支持）
        a.swap(b);              z交换a和b的元素
        swap(a, b);             z与a.swap(b)等价
        ****大小****
        c.size();               c中元素数目（不支持forward_list）
        c.max_size();           c可保存的最大元素数目
        c.empty();              若c中存储了元素，返回false；否则返回true
        ****添加删除元素（不适用array）****
        c.insert(args);         将args中元素拷贝进c
        c.emplace(inits);       使用inits构造c中的一个元素
        c.erase(args);          删除args指定的元素
        c.clear();              删除c中所有元素，返回void
        ****关系运算符****
        ==, !=                  所有容器都支持等于、不等于运算符
        <, <=, >, >=            关系运算符，无序关联容器不支持
        ****获取迭代器****
        c.begin(); c.end();     返回指向c的首元素和尾元素之后位置的迭代器
        c.cbegin(); c.cend();   返回const_iterator
        ****反向容器的额外成员（不支持forward_list）****
        reverse_iterator        按逆序寻址元素的迭代器
        const_reverse_iterator  不能修改元素的逆序迭代器
        c.rbegin(); c.rend();   返回指向c的尾元素和首元素之前为止的迭代器
        c.crbegin(); c.crend(); fjhv const_reverse_iterator
    */
}

