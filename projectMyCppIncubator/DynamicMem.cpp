#include "stdafx.h"
#include "DynamicMem.h"
#include <memory>
#include <string>

using std::shared_ptr;
using std::unique_ptr;
using std::weak_ptr;
using std::make_shared;
using std::nothrow;
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
    int *intP1 = new int; // new无法为分配的对象命名，对象默认初始化，值未定义
    int *intP2 = new int(1234); // 直接初始化
    int *intP3 = new int(); // 值初始化为0
    int *intP4(new int(135));
    delete intP1; // 释放一块非new得到的内存，或将相同的内存释放多次，其行为未定义
    delete intP2;
    delete intP3;
    delete intP4;

    string strObj = string("StrObj");
    auto autoP = new auto(strObj); // autoP指向与strObj类型相同的对象，该对象用strObj初始化。只能有一个对象作为初始化器
    // auto illegalP = new auto{1, 2, 3}; // a brace-enclosed initializer list cannot be used in a new-expression whose type contains 'auto'
    delete autoP;

    const int *cIntP = new const int(321); // 动态分配const对象
    delete cIntP;

    int *memOkIntP = new int(0); // 如果分配失败，new会抛出std::bad_alloc
    int *memFailIntP = new (nothrow) int; // 如果分配失败，new返回一个空指针
    delete memOkIntP;
    delete memFailIntP;
    
    /*
        C++ 11：智能指针（smart pointer）负责自动释放所指向的对象
        shared_ptr允许多个指针指向同一个对象
        unique_ptr独占指向的对象，同一时刻只能有一个unique_ptr指向给定对象
        weak_ptr是弱引用，指向shared_ptr所管理的对象，但不控制此对象的生存周期，绑定到shared_ptr不会改变shared_ptr的引用计数
        auto_ptr标准库早期智能指针，留作向后兼容用

        注意点：
        - 不要混合使用普通指针和智能指针
        - 不要用get初始化另一个智能指针或为智能指针赋值
        - 不使用相同的内置指针初始化或reset多个智能指针
        - 不delete get()返回的指针
        - 不使用get()初始化或reset另一个智能指针
        - 如果使用get()返回的指针，记住当最后一个对应的智能指针销毁后，指针就变无效了
        - 如果使用智能指针管理的资源不是new分配的内存，记住传递给它一个删除器

        shared_ptr和unique_ptr都支持的操作：
        shared_ptr<T> sp;       空智能指针，指向类型为T的对象
        unique_ptr<T> up;       
        p;                      将p作为条件判断，若p指向一个对象则为true
        *p;                     解引用，获得它指向的对象
        p->mem;                 等价于(*p).mem
        p.get();                返回p中保存的指针，若智能指针释放了其对象，返回的指针指向的对象也消失了
                                用途是需要向不能使用智能指针的代码传递一个内置指针
        swap(p, q);             交互p和q中的指针
        p.swap(q);

        shared_ptr独有的操作：
        make_shared<T>(args);   返回一个shared_ptr，指向一个动态分配的用args初始化的类型为T的对象
        shared_ptr<T>p(q);      如果q也是shared_ptr，则p是q的拷贝，递增q中的计数器，q中的指针必须能转换为T*
                                如果q是new创建的对象，q中的指针必须指向new得到的对象且能转换为T*
        shared_ptr<T>p(u);      p从unique_ptr u接管其对象所有权，将u置为空
        shared_ptr<T>p(q,d);    如果q是内置指针，p接管内置指针q所指向的对象所有权，q必须能转换为T*。p将调用对象d来代替delete
                                如果q是shared_ptr，p是q的拷贝，p可调用d来代替delete
        p.reset();              若p是唯一指向其对象的shared_ptr，释放此对象，将p置空
        p.reset(q);             q是内置指针，p指向q
        p.reset(q,d);           用d而不是delete来释放q
        p=q;                    p和q都是shared_ptr，其指针能相互转换。递减p的引用计数器，递增q的引用计数器，若p的引用计数器为0，则将其管理的原内存释放
        p.unique();             若p.use_count()为1，返回true；否则返回false
        p.use_count();          返回与p共享对象的智能指针数量。执行速度可能会很慢，主要用于调试

        unique_ptr独有的操作：
        unique_ptr<T> p;                    空unique_ptr，指向类型为T的对象，使用delete释放其指针
        unique_ptr<T, D> p;                 使用D释放指针
        unique_ptr<T, D> p(d);              用类型为D的对象d代替delete
        p = nullptr;                        释放u指向的对象，u置空
        u.release()                         u放弃对指针的控制权，返回指针，将u置空
        u.reset()                           释放u指向的对象
        u.reset(q)；                        令u指向内置指针q的对象
        u.reset(nullptr);                   将u置空

        unique_ptr<int> p(new int(42));     定义unique_ptr时绑定new返回的指针
        错误：unique_ptr<int> q(p);          unique_ptr不支持拷贝
        错误：unique_ptr<int> r; r = p;      unique_ptr不支持赋值
        unique_ptr<int> q(p.release());     把p指向的对象所有权转移给q，把p置空

        weak_ptr独有的操作：
        weak_ptr<T> w;          空weak_ptr，指向类型为T的对象
        weak_ptr<T> w(sp);      与shared_ptr sp指向相同对象的weak_ptr。T必须能转换为sp指向的类型。
        w = p;                  p可以为shared_ptr或weak_ptr
        w.reset();              w置为空
        w.use_count();          返回与w共享对象的shared_ptr数量
        w.expired();            若w.use_count()返回为0，返回true，否则返回false
        w.lock();               如果w.expired()返回为true，返回空shared_ptr，否则返回指向w的shared_ptr
    */
    shared_ptr<string> strShPtr = make_shared<string>(string("sharedPtr"));
    shared_ptr<int> intShPtr(new int(1)); // 用new得到的对象直接初始化，因为shared_ptr默认用delete释放其关联的对象，推荐用make_shared代替
    //shared_ptr<int> illIntShPtr = new int(0); // 不能把int*转换为shared_ptr<int>
    

    Page 422: 指针操作
}
