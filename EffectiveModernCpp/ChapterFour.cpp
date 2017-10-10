// EffectiveModernCpp.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "Item18.h"
#include "Item19.h"

using std::cout;
using std::endl;

void ChapterFour(void)
{
  /*
    C++11的四种智能指针：
    - auto_ptr
      * Deprecated leftover from C++98. unique_ptr的前身。
    - unique_ptr
      * 默认情况下可以认为和原始指针大小相同，可用在对内存使用有限制的场景。
        默认用delete；如果自定义了deleter，内存消耗会增加。
        增加的大小视deleter函数的内部状态多少而定。
        没有capture的lambda函数会比没有内部状态的函数要节省空间。
      * 非空的unique_ptr“拥有”其指向的对象。
      * move的时候把“拥有权”转让给另一个指针，把自己置为null。
      * copy不允许，否则可能会出现两个unique_ptr同时拥有对象，按各自的情况清理其指向的堆上对象
      * 不能把原始指针直接赋值给unique_ptr，因为无法类型转换。要用reset(new ...)来绑定拥有关系
    - shared_ptr
      * 是原始指针的两倍大小：除了原始指针之外，还有内部的原始指针指向control block
        （control block结构里有reference count）
      * reference count是动态分配的
      * Reference count的增加和减少操作都是原子操作，相对耗时
    - weak_ptr
  */
  cout << "##### Chapter Four #####" << endl;
  
  item18();
  item19();
}

