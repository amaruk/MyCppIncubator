#include "stdafx.h"
#include "Item40.h"

void Item40::ItemEntry()
{
  //// Item 40: Use std::atomic for concurrency, volatile for special memory
  // 因为有把volatile误认为是atomic的情况存在，所以在并发的章节讨论volatile。
  // atomic模板是针对某种类型提供原子操作，因为有特殊的机器指令实现，所以比用mutex作互斥高效。
  // atomic不支持拷贝构造，因为拷贝构造要读一个变量写另一个变量，硬件一般不支持这种情况的原子操作。
  // TODO：参考Item17，atomic不支持移动构造。
  // 所以在atomic变量之间拷贝值，要用load和store成员函数。
  // volatile的用途是告诉编译器某变量指向特殊的内存位置（比如映射到外设的内存地址），不要对该变量的读写进行优化。
  // 连续读两次普通变量： int y = x; y = x; 称为Redundant loads
  // 连续写两次普通变量： int x = 10; x = 20; 称为dead stores

}
