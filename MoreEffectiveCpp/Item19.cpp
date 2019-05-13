#include "stdafx.h"
#include "Item19.h"

void Item19::ItemEntry()
{
  // Item 19: Understand the origin of temporary objects.
  // Temporary object不是指代码局部使用的临时变量，而是指不出现在代码里的真正的临时对象。
  // 未命名的非heap对象即为临时对象。
  // 两种情况下出现：
  // 1. 在函数调用时，实参类型和行参类型不同导致的隐式类型转换时构造，函数调用语句结束时析构。
  // 2. 函数返回对象
}
