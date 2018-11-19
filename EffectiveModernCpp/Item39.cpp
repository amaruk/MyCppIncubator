#include "stdafx.h"
#include "Item39.h"
#include <thread>
#include <future>
#include <string>
#include <chrono>

using std::thread;
using std::async;
using std::to_string;
using std::this_thread::sleep_for;
using std::chrono::milliseconds;

namespace ITEM39_SOLUTION_1
{
  std::condition_variable cv;
  std::mutex m;

  void NotifierThread()
  {
    sleep_for(milliseconds(1000));
    cout << "Solution 1: Notifier notify_one()." << endl;
    cv.notify_one();
  }

  void WaiterThread()
  {
    {
      std::unique_lock<std::mutex> lk(m);
      cout << "Solution 1: Waiter wait()." << endl;
      cv.wait(lk);
      cout << "Solution 1: Waiter Wakeup." << endl;
    }
  }

}

namespace ITEM39_SOLUTION_3
{
  std::condition_variable cv;
  std::mutex m;
  bool flag{ false };

  void NotifierThread()
  {
    sleep_for(milliseconds(1000));
    {
      std::lock_guard<std::mutex> lg(m);
      flag = true;
    }
    cout << "Solution 3: Notifier notify_one()." << endl;
    cv.notify_one();
  }

  void WaiterThread()
  {
    {
      std::unique_lock<std::mutex> lk(m);
      cout << "Solution 3: Waiter wait()." << endl;
      cv.wait(lk, [] {return flag; });
      cout << "Solution 3: Waiter Wakeup." << endl;
    }
  }

}

namespace ITEM39_SOLUTION_4
{

  std::promise<void> p;

  void NotifierThread()
  {
    sleep_for(milliseconds(1000));
    cout << "Solution 4: Notifier promise.set_value()." << endl;
    p.set_value();
  }

  void WaiterThread()
  {
    {
      cout << "Solution 4: Waiter promise.get_future().wait()." << endl;
      p.get_future().wait();
      cout << "Solution 4: Waiter Wakeup." << endl;
    }
  }

}

void Item39::ItemEntry()
{
  // Item 39: Consider void futures for one-shot event communication.

  // 方案一：
  // 使用condition variable来在两个线程之间发送通知。
  // 创建mutex和condition variable对象，检测到事件的线程使用notify_one()通知另一个线程，
  // 使用notify_all()通知多个线程。
  thread notifierThread = thread(ITEM39_SOLUTION_1::NotifierThread);
  thread waiterThread = thread(ITEM39_SOLUTION_1::WaiterThread);
  notifierThread.join();
  waiterThread.join();
  // 缺陷：
  // - mutex是用来控制共享数据访问的，这里并没有共享数据缺仍然用了mutex。
  // - 如果先notify了才开始wait，会永远wait不到。
  // - wait的线程可能被不是这个condition variable的原因而唤醒（spurious wakeups)，
  //   虽然wait函数可以用lambda表达式检查到底是不是condition variable对应的事件发生了，
  //   但在wait线程无法得知对应的事件时，无法确认到底是不是condition variable被notify了。

  // 方案二：
  // 使用atomic<bool>的flag变量，一个线程设置此变量，另一个线程使用while忙等此变量。
  // 缺陷：
  // 相对于mutex的wait会block线程，检测变量的线程处于忙等的状态。

  // 方案三：
  // 结合flag变量（因为有mutex包含，无需atomic）和condition variable。
  // 缺陷：
  // 虽然解决了所以问题，但代码不是很清晰，
  // 因为已经有condition variable，却还是需要用flag来检测是不是真的由于这个condition variable而唤醒。
  notifierThread = thread(ITEM39_SOLUTION_3::NotifierThread);
  waiterThread = thread(ITEM39_SOLUTION_3::WaiterThread);
  notifierThread.join();
  waiterThread.join();

  // 方案四：
  // 发送端使用promise，接收端使用future。
  // 缺陷：
  // promise和future都是shared state，一般实现都是动态分配内存，所以使用时有堆上分配和释放内存的开销。
  // promise和future都是一次性的，不能像condition variable和flag变量那样重复使用
  // 可以用shared_future对象来实现一次唤醒多个线程
  notifierThread = thread(ITEM39_SOLUTION_4::NotifierThread);
  waiterThread = thread(ITEM39_SOLUTION_4::WaiterThread);
  notifierThread.join();
  waiterThread.join();
}
