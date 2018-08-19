#include "stdafx.h"
#include "Item38.h"

void Item38::ItemEntry()
{
  // Item 38:Be aware of varying thread handle destructor behavior.

  // std::thread和future都关联系统线程，所以他们都可以称为系统线程的handle。
  // 但future没有joinable状态析构导致程序被terminate的问题。

  // future可以认为是callee向caller传输结果的通讯通道的一端
  // callee将其计算结果通过通讯通道里（如通过std::promise对象），caller使用future读取结果。
  // callee可以先于caller在future对象上调用get前结束，所以其计算结果不能存在promise里。
  // 计算结果也不能存在caller的future上，如future可能被用于创建shared_future，导致计算结果存在的声明周期长于future
  // 所以计算结果存在与shared state里，一般shared state是在堆上的对象，当其被引用计数为0时被销毁。
  
}
