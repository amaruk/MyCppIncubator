#include "stdafx.h"
#include "Item37.h"
#include <thread>

using std::thread;

namespace ITEM37
{
  void endlessLoop()
  {
    for (float f = 0; f < 100; f += 0.1f)
    {
      ;
    }
  }

}

void Item37::ItemEntry()
{
  // Item 37: Make std::threads unjoinable on all paths.

  // 每个thread都处于joinable和unjoinable状态之一
  // Unjoinable的thread是：
  // * 默认构造的std::thread。因为没有可执行的对象，所以没有对应的底层线程。
  // * 被move掉的std::thread。move之后底层线程跟着被move。
  // * Join过的std::thread。join返回之后实际执行的底层线程已经退出了。
  // * Detach过的std::thread。detach操作切断了和底层线程之间的关联。

  // 当一个std::thread仍处在joinable状态时被析构，为了避免实现隐式的join或detach，程序会直接终止。
  // 以下代码，如果不join，在线程仍然执行的情况下离开代码块，会导致joinable状态时被析构，程序终止。
  {
    thread toBeTerminatedThread = thread(ITEM37::endlessLoop);
    toBeTerminatedThread.join(); // 注释此行导致程序终止
  }

  // If you use a std::thread object, it's made unjoinable on every path out of the scope in which it's defined.
  // End of scope还包括return，continue，break，goto，或异常，所以如果std::thread是RAII的就不用担心。
  // 但标准库没有RAII的实现，可能因为在出scope的时候既不适合join也不适合detach（参考书上示例代码的解释），所以没法自动回收。
  // 书上给出的构造时指定join或detach的RAII实现，但Item 39演示了在析构里join可能导致程序挂起的情况。

  // C++11不支持interruptible的thread
}
