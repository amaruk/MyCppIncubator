#include "stdafx.h"
#include "Item40.h"


Item40::Item40() :
  ItemBase("40")
{
}


Item40::~Item40()
{
}

void Item40::ItemEntry()
{
  //// Item 40: Use multiple inheritance judiciously
  // Virtual Base Class用来解决deadly multiple inheritance diamond.
  // 标准库的文件类用此实现
}