#include "stdafx.h"
#include "Item35.h"
#include <thread>
#include <future>
#include <string>

using std::thread;
using std::async;
using std::to_string;

namespace ITEM35
{
  int AsyncWork()
  {
    cout << "Inside AsyncWork." << endl;
    return 12345;
  }
}

void Item35::ItemEntry()
{
  // Item 35: Prefer task-based programming to thread-based.

  // Thread-based实现，AsyncWork是thread
  thread asyThread(ITEM35::AsyncWork);
  asyThread.join();
  // Task-based实现，AsyncWork是task
  auto asyAsync = async(ITEM35::AsyncWork);

  // task实现比thread实现好
  // 1. 因为task实现可以获取返回值
  cout << asyAsync.get() << endl;
  
  // 2. task实现可以捕获其内部发生的异常，
  //    而thread实现发生异常时会直接调用std::terminate退出整个程序
  // 3. task实现中标准库为程序员隐藏了线程管理方面的细节，原因如下：
  //
  //    使用Thread的顾虑：
  //    thread在C++并发编程的意义在于：
  //    1. Hardware Thread是真正执行计算的thread，当代的硬件一般每个CPU核会提供一个或多个硬件线程
  //    2. Software Thread，也称为OS thread或system thread，是操作系统管理的针对所有进程的软件线程，
  //       操作系统负责调度并在硬件线程上执行。
  //    3. std::thread是C++的对象，实际上是软件线程的handle。
  //       有些std::thread对象表示null的handle，如那些还在默认构造函数里没有可执行的函数所以没有绑定到软件线程的对象，
  //       或者被move掉的对象，或者被joined的对象（即已经执行完的），或被detached的对象（对象和软件线程的绑定被断开）
  //       * 当没有可用的软件线程时，创建thread会导致抛出system_error异常，即使thread跑的函数是noexcept的。
  //       * 当软件线程超过硬件线程时，会发生oversubscription问题。OS的软件线程调度器一般会采用时间片来保证软件线程都会被执行到。
  //         此时会引入时间片导致的上下文切换，特别是当软件线程在不同时间片内被分配到不同CPU核的硬件线程时，
  //         还有切换CPU核导致额外的cache命中性能折损，同时也会影响切换过去的CPU核里已有硬件线程的cache命中率。
  // 
  //    使用task时，
  //    * 如果软件线程耗尽，async实现默认policy会在调用async的当前线程执行task，以避免system_error异常。
  //    * 对于性能要求高的当前线程，传launch::async的policy会保证开新线程避免影响当前线程。
  //    * C++标准库的实现者会更新其task的内部线程管理实现，更新标准库的时候就能直接用上最新的实现，
  //      而使用thread的话要自己更新线程管理算法（可能还要更新跨平台的实现）。
  
  // 但有些场合必须使用thread实现：
  // 1. 需要访问底层线程实现的API。因为底层线程API（如windows线程）提供比标准库线程更多的API。如设置线程的priority和affinity。
  //    thread提供native_handle成员函数以访问底层线程API，但async没有。
  // 2. Application需要优化其线程的使用状况。在知道所有软件执行细节以及硬件特性的情况下，手动管理线程。
  // 3. 实现C++并发API没有提供的功能。比如使用的C++实现没有thread pool时自己实现pool并管理线程。
}
