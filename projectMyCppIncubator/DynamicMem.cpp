#include "stdafx.h"
#include "DynamicMem.h"
#include <memory>
#include <string>

using std::shared_ptr;
using std::unique_ptr;
using std::weak_ptr;
using std::string;

DynamicMem::DynamicMem()
{
}


DynamicMem::~DynamicMem()
{
}

void DynamicMem::DynamicMemTest(void)
{
    /*
        - 静态内存用来保存局部static对象、类static数据成员，以及定义在任何函数外的变量。
        - 栈内存用来保存定义在函数内的非static对象。
        静态内存和栈内存由编译器自动创建和销毁。

        - 堆（heap）或称自由空间（free store）用来存储动态分配的对象。
        动态分配的对象由程序在运行时分配，不再使用时由程序显式销毁。

        new运算符在堆中为对象分配空间并返回指向对象的指针
        delete运算符接受动态对象的指针，销毁改对象，释放与之关联的内存
    */

    /*
        C++ 11：智能指针（smart pointer）负责自动释放所指向的对象
        shared_ptr允许多个指针指向同一个对象
        unique_ptr独占指向的对象
        weak_ptr是弱引用，指向shared_ptr所管理的对象

        shared_ptr和unique_ptr都支持的操作：
        shared_ptr<T> sp;       空智能指针，指向类型为T的对象
        unique_ptr<T> up;       
        p;                      将p作为条件判断，若p指向一个对象则为true
        *p;                     解引用，获得它指向的对象
        p->mem;                 等价于(*p).mem
        p.get();                返回p中保存的指针，若智能指针释放了其对象，返回的指针指向的对象也消失了
        swap(p, q);             交互p和q中的指针
        p.swap(q);

        shared_ptr独有的操作：
        make_shared<T>(args);   返回一个shared_ptr，指向一个动态分配的用args初始化的类型为T的对象
        shared_ptr<T>p(q);      p是q的拷贝，递增q中的计数器，q中的指针必须能转换为T*
        p=q;                    p和q都是shared_ptr，其指针能相互转换。递减p的引用计数器，递增q的引用计数器，若p的引用计数器为0，则将其管理的原内存释放
        p.unique();             若p.use_count()为1，返回true；否则返回false
        p.use_count();          返回与p共享对象的智能指针数量。执行速度可能会很慢，主要用于调试
    */
    shared_ptr<string> strShPtr;
    428 shared_ptr的拷贝和赋值
}
