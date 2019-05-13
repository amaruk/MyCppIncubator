#include "stdafx.h"
#include "Item20.h"

void Item20::ItemEntry()
{
  // Item 20: Facilitate “the return value optimization”.
  // 返回对象的函数会导致临时对象的创建，但如果return语句后跟构造函数的调用，则不会创建临时对象。
}
