#include "stdafx.h"
#include "Item26.h"


Item26::Item26() :
  ItemBase("26")
{
}


Item26::~Item26()
{
}

void Item26::ItemEntry()
{
  //// Item 26: Postpone variable definitions as long as possible.
  // 尽量在要使用变量之前才定义变量，以减少类似于如下现象：生成变量时调用构造函数，但变量还没用到函数就返回，此时又要调用变量析构函数
  // 如果变量是复杂类型，需要初始化成员，则提供初始化成员的构造函数，避免调用默认构造函数之后再赋值。
  // 循环内使用的变量，如果在循环外声明，会将其暴露给循环以外的范围，一般来说变量创建在循环内部，
  // 但如果赋值比构造和析构高效且对代码的性能要求很高，则在循环外部创建。
}