#include "stdafx.h"
#include "Item31.h"
#include "Item32.h"


void ChapterSix(void)
{
  // Lambda Expression:
  // [capture list](parameter list) mutable -> return type {function body}

  // 适合用lambda的场景：
  // * STL的_if算法，如find_if/remove_if/count_if
  // * STL的比较函数的算法，如sort/nth_element/lower_bound
  // * STL之外，使用lambda快速实现unique_ptr和shared_ptr的deleter

  // Closure是lambda创建的运行时对象。closure里有capture数据的拷贝
  // Closure class是closure实例对应的类。编译器为每个lambda创建closure class，
  //    lambda里面的语句是这个类的成员函数。
  // 可以把lambda语句赋值给auto变量，这个auto变量即为此lambda对应的closure
  // 同时可以赋值给其他的auto变量，获得多个拷贝。

  //Item31();
  Item32();
}