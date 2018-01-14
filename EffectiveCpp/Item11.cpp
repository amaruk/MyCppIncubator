#include "stdafx.h"
#include "Item11.h"


Item11::Item11() :
  ItemBase("11")
{
}


Item11::~Item11()
{
}

void Item11::ItemEntry()
{
  //// Item 11: Handle assignment to self in operator=
  // 当实现赋值操作符时，需要考虑操作符两边为同一个对象的情况，否则赋值给自身时可能出现如下情况：
  // 1. 把左操作数的资源释放
  // 2. 把右操作数的资源传递给左操作数（此时右操作数的资源已经在上一步被释放）
  // 3. 返回左操作数（赋值给自身之后，其资源丢失）

  // 传统的解决方案为在实现赋值操作符时，先判断如左右操作数相同则直接返回


}