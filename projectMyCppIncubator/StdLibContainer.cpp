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
    array<char, 3> charArray{ 'f', 'g', 'h' }; // array除了指定类型外，还要指定容器大小

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
        C c1(c2);               构造c2的拷贝c1。array可拷贝，但内置数组类型不能拷贝。
        C c1 = c2;              同上，赋值后c1的size变为c2的size
        C c(b, e);              构造c，将迭代器b（第一个拷贝的元素位置）和e（拷贝的最后一个元素之后的位置）指定范围的元素拷贝到c，类型相容即可，不需相同（array不支持）
        C c{a, b, c...};        C++11列表初始化c
        C c = {a, b, c...};     C++11同上，赋值后c1的size变为c2的size
        C c(n);                 顺序容器（array除外）包含n个元素，进行值初始化。此构造函数是explicit的。
        C c(n, t);              同上，但初始化为t
        ****大小****
        c.size();               c中元素数目（不支持forward_list）
        c.max_size();           c可保存的最大元素数目
        c.empty();              若c中存储了元素，返回false；否则返回true
    */
    /*
        ****赋值与swap****
        c1 = c2;                将c1中的元素替换为c2
        c1 = {a, b, c...};      将c1中的元素替换为列表中元素（原书第五版提示array不支持，VS2017支持）
                                *对array进行swap，耗时和array元素数量成正比，因为实际交换元素
                                *对其他容器进行swap，速度很快为线性时间，因为不是拷贝元素而是交换了两个容器的内部数据结构
        a.swap(b);              交换a和b的元素，早期版本之提供此类型
        swap(a, b);             与a.swap(b)等价，在范性编程中很重要，建议使用此种非成员版本的swap
                                *assign用于类型不同但相容的赋值，或用子序列赋值。不适用于关联容器和array
        seq.assign(b, e);       将seq的元素替换为迭代器b和e所表示范围内的元素，迭代器b和e不能指向seq的元素（因为旧元素会被替换）
        seq.assign(il);         将seq的元素替换为初始化列表il中的元素
        seq.assign(n, t);       将seq的元素替换为n个值为t的元素
    */
    // 注意赋值操作会导致容器内部的迭代器、引用、指针失效
    vector<int> vectorInt10 = { 0,1,2,3,4,5,6,7,8,9 };
    vector<int> vectorInt5 = { 4,3,2,1,0 };
    cout << "vectorInt10 size [" << vectorInt10.size() << "] " <<
        "vectorInt5 size [" << vectorInt5.size() << "]" << endl;
    vectorInt10 = vectorInt5; // 不同大小的容器赋值，左边的容器大小变为右边容器大小
    cout << "vectorInt10 size [" << vectorInt10.size() << "] " <<
        "vectorInt5 size [" << vectorInt5.size() << "]" << endl;

    array<int, 10> aryInt10 = { 0,1,2,3,4,5,6,7,8,9 };
    array<int, 10> aryInt10Another = { 9,8,7,6,5,4,3,2,1,0 };
    array<int, 5> aryInt5 = { 4,3,2,1,0 };
    //aryInt10 = aryInt5; // array赋值必须类型相同
    aryInt10 = aryInt10Another; // 类型相同，可以赋值
    cout << "before " << aryInt5[0] << aryInt5[1] << aryInt5[2] << aryInt5[3] << aryInt5[4] << endl;
    aryInt5 = { 1,2 };
    cout << "after " << aryInt5[0] << aryInt5[1] << aryInt5[2] << aryInt5[3] << aryInt5[4] << endl;

    /*
        ****关系运算符****
        *运算符两边的容器必须类型相同，元素类型相同
        ==, !=                  所有容器都支持
        <, <=, >, >=            关系运算符，无序关联容器不支持
                                比较规则：
                                - 两个容器大小相同且所有元素亮亮对应相等，则容器相等；否则不等
                                - 两个容器大小不同，较小容器中每个元素都等于较大容器中对应元素，则较小容器小于较大容器
                                - 两个容器都不是另一个容器的前缀子序列，则比较结果取决于第一个不相等的元素比较结果
    */
    vector<int> vector1 = { 1,3,5,7,9,12 };
    vector<int> vector2 = { 1,3,9 };
    vector<int> vector3 = { 1,3,5,7 };
    vector<int> vector4 = { 1,3,5,7,9,12 };
    cout << "vector1 < vector2: " << ((vector1 < vector2) ? "true" : "false") << endl; // 结果取决于元素[2]
    cout << "vector1 < vector3: " << ((vector1 < vector3) ? "true" : "false") << endl; // 元素都相等，vector3元素数量少
    cout << "vector1 == vector4: " << ((vector1 == vector4) ? "true" : "false") << endl; //大小相同，元素相等
    cout << "vector1 == vector2: " << ((vector1 == vector2) ? "true" : "fasle") << endl; // vector2元素数量少
    /*
        ****添加删除元素（不适用array）****
        c.insert(args);         将args中元素拷贝进c
        c.emplace(inits);       使用inits构造c中的一个元素
        c.erase(args);          删除args指定的元素
        c.clear();              删除c中所有元素，返回void
        ****获取迭代器****
        c.begin(); c.end();     返回指向c的首元素和尾元素之后位置的迭代器iterator
        c.cbegin(); c.cend();   返回const_iterator
        ****反向容器的额外成员（不支持forward_list）****
        reverse_iterator        按逆序寻址元素的迭代器，++得到上一个元素
        const_reverse_iterator  不能修改元素的逆序迭代器
        c.rbegin(); c.rend();   返回指向c的尾元素和首元素之前为止的迭代器reverse_iterator
        c.crbegin(); c.crend(); 返回const_reverse_iterator
    */
}

