#include "stdafx.h"
#include "Item36.h"
#include <thread>
#include <future>
#include <string>

using std::thread;
using std::async;
using std::to_string;

void Item36::ItemEntry()
{
  // Item 36: Specify std::launch::async if asynchronicity is essential.

  // std::async有默认的policy。

  // 也可以不用默认policy而指定两个标准policy之一：
  // 1. std:launch::async
  //    可执行对象必须在别的线程被执行
  // 2. std::launch::deferred
  //    可执行对象的执行被延迟，阻塞async的调用者。
  //    直到async的get或wait被调用，才执行可执行对象。
  //    知道可执行对象执行完毕，调用者才继续执行。

  // 默认的policy相当于std:launch::async|std::launch::deferred
  // 使用默认的policy时：
  // 1. 不可预测可执行对象是否并发执行，因为可能被defer
  // 2. 不可预测可执行对象是否在不同于调get或wait的线程上被执行
  // 3. 不可预测可执行对象是否已经被执行了
  // 所以默认policy调度时，无法预测到底那个线程的TLS（Thread Local Storage）会被使用。
  // 对默认policy的async做wait_for和wait_until时会返回std::future_status::deferred，
  // 不等于future_status_ready，可能仅在系统运行到高负载时才会造成死循环（bug代码及修正参考原书示例）。

  // 综上所述，在如下情况使用默认policy是安全的：
  // 1. task无需和调用get或wait的线程并发执行
  // 2. 不在乎是那个线程的TLS被读写
  // 3. 要么保证get或wait一定会被调到；要么task永远不被执行是可接受的
  // 4. 使用wait_for或wait_until的代码会处理好defer的policy（见上述std::future_status::deferred的问题描述）
  // 如果上述任意一条不满足，则使用std:launch::async

}
