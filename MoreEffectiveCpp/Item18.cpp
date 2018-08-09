#include "stdafx.h"
#include "Item18.h"

void Item18::ItemEntry()
{
  // Item18: Amortize the cost of expected computations.
  // 本章讨论over-eager evaluation，三种evaluation的区别：
  // Over-eager evaluation: Doing things before you're asked to do them.追踪任务被执行的情况和结果，当需要再次执行任务时有可能不计算而直接返回结果。
  // Eager evaluation: 完整地完成任务，可能不会被用到的部分也进行evaluation。
  // lazy evalution: 延迟可以不在当时做的任务，以免evaluation可能不会被用到的部分（见上一章）。
  // over-eager用于结果几乎总是被使用或结果会被多次使用的操作，lazy是结果不是经常被需要的操作。

  // 实例为caching和prefetching。类比内存页表在cache里的缓存和磁盘读取数据时读取整个块。
  // 前提是牺牲空间换取时间。trade space for time.

}
