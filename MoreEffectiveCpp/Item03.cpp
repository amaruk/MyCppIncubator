#include "stdafx.h"
#include "Item03.h"

Item03::Item03() :
  ItemBase("03")
{
}


Item03::~Item03()
{
}


void Item03::ItemEntry()
{
  // Item03: Never treat arrays polymorphically.

  // 由于数组使用下表定位元素的时候把元素的尺寸作为偏移，如果基类数组实际存的是派生类对象的话，编译正确，运行时下标计算会偏移不够多。
  // 同理在delete[]数组时，也会因为偏移不正确而导致未定义行为
}
