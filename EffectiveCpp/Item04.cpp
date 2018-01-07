#include "stdafx.h"
#include "Item04.h"


Item04::Item04() :
  ItemBase("04")
{
}


Item04::~Item04()
{
}

void Item04::ItemEntry()
{
  // Item 4: Make sure that objects are initialized before they're used

  // 在类的构造函数member initialization list里初始化成员。
  // 在构造函数内部对成员操作是赋值，在初始化列表里是初始化。
  // 初始化列表效率高。
  // const和引用成员必须在初始化列表里初始化，因为其不能在构造函数内部赋值
  // 父类先于子类初始化，成员按照声明的先后顺序初始化（即使在构造函数的初始化列表里顺序不同）

  // 注意：the relative order of initialization of non-local static objects defined in different translation units is undefined.
  // 意即非局部的static变量在不同的文件级编译单元里出现，其初始化在何时完成是未定义的。
  // 解决方法为使用单例模式
}
