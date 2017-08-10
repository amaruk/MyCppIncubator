#include "stdafx.h"
#include "MultiThreadTest.h"
#include <stdint.h>
#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

/*
 * 多线程编程相关的头文件：
 * atomic：包含类atomic和atomic_flag，以及C风格的原子类型和原子操作函数
 * thread：thread类，this_thread命名空间
 * mutex：互斥量相关类mutex，lock_guard，unique_lock
 * condition_variable：条件变量相关，condition_variable和condition_variable_any
 * future：Provider类promise，package_task。future类future，shared_future
 */

using std::cout;
using std::endl;
using std::thread;
using std::mutex;
using std::timed_mutex;
using std::lock_guard;
using std::this_thread::sleep_for;
using std::this_thread::get_id;
using std::chrono::microseconds;

MultiThreadTest::MultiThreadTest()
{
}


MultiThreadTest::~MultiThreadTest()
{
}

void threadParValue(uint32_t runTimes)
{
  for (uint32_t i = 0; i != runTimes; i++)
  {
    cout << "Thread(uint) " << get_id() << " running: " << i << endl;
    sleep_for(microseconds(10));
  }
}

void threadParRef(uint32_t &runTimes)
{
  for (uint32_t i = 0; i != runTimes; i++)
  {
    cout << "Thread(&uint) " << get_id() << " running: " << i << endl;
    sleep_for(microseconds(10));
  }
}

void threadTest(void)
{
  // 默认构造函数创建空的thread对象
  // 拷贝构造函数置为deleted
  // 支持移动构造函数
  // 初始化构造函数创建joinable对象，销毁之前必须被主线程join或置为detached
  // 支持移动操作，不可joinable的对象传右值引用
  // 拷贝操作符置为deleted
  //
  // 其他成员函数：
  // get_id/joinable/join/detach/swap/native_handle/hardware_concurrency[static]

  cout << endl << "====threadTest====" << endl;

  uint32_t runTimes = 2;
  thread threadConsDefault; // 无法运行
  thread threadConsValue(threadParValue, runTimes); // 线程主函数参数传值
  thread threadConsRef(threadParRef, std::ref(runTimes)); // 线程主函数参数传引用
  thread threadConsMove(std::move(threadConsRef)); // 移动构造函数
  thread threadCopy = thread(threadParValue, runTimes);

  threadConsValue.join();
  threadConsMove.join();
  threadCopy.join();
}

void threadMutex(uint32_t runTimes, mutex &mtx)
{
  for (uint32_t i = 0; i != runTimes; i++)
  {
    mtx.lock();
    cout << "threadMutex " << get_id() << " running: " << i << endl;
    mtx.unlock();
    sleep_for(microseconds(i));
  }
}

void threadTimeMutex(char waitCh, timed_mutex &tmd_mtx)
{
  // Block waiting for 100ms and print
  while (!tmd_mtx.try_lock_for(microseconds(100)))
  {
    cout << waitCh;
  }

  // Get lock and print !
  cout << "threadTimeMutex " << get_id() << " done!" << endl;

  // Wait 1000ms before unlock
  sleep_for(microseconds(10000));

  tmd_mtx.unlock();
}

void threadMutexLockGuard(mutex &mtx)
{
  try
  { 
    // Change to #if 0 to be blocked forever after exception
#if 1
    lock_guard<mutex> lockGuard(mtx);
    throw (std::logic_error("ERROR"));
#else
    mtx.lock();
    throw (std::logic_error("ERROR"));
    mtx.unlock();
#endif
  }
  catch (std::logic_error &)
  { cout << "threadMutex " << get_id() << " excepted." << endl; }
}

void mutexTest(void)
{
  cout << endl << "====mutexTest====" << endl;

  // Mutex
  // std::mutex                 基础mutex
  // std::recursive_mutex       递归mutex，同一个线程可以多次对同一个mutex上锁，必须解锁相同次数
  // std::time_mutex            定时mutex，在指定时间阻塞线程，超时返回false
  // std::recursive_timed_mutex 定时递归mutex

  // 刚创建的mutex未unlocked状态
  cout << endl << "----MUTEX----" << endl;

  mutex mtx;
  thread threadMutex1(threadMutex, 3, std::ref(mtx));
  thread threadMutex2(threadMutex, 3, std::ref(mtx));
  threadMutex1.join();
  threadMutex2.join();

  cout << endl << "----TIME MUTEX----" << endl;
  timed_mutex tmd_mtx;
  thread threadMutex3(threadTimeMutex, '3', std::ref(tmd_mtx));
  thread threadMutex4(threadTimeMutex, '4', std::ref(tmd_mtx));
  thread threadMutex5(threadTimeMutex, '5', std::ref(tmd_mtx));
  threadMutex3.join();
  threadMutex4.join();
  threadMutex5.join();

  // Lock
  // std::lock_guard    实现mutex生命周期的Mutex RAII
  // std::unique_lock   同上，提供更好的上锁和解锁控制
  // RAII: Resource Acquisition Is Initialization
  // 在类的构造函数中分配资源，在析构函数中释放资源。
  // 当一个对象创建的时候，构造函数会自动地被调用；
  // 而当这个对象被释放的时候，析构函数也会被自动调用。
  // 即使异常发生，资源也能正常释放

  cout << endl << "----MUTEX LOCK GUARD----" << endl;
  thread threadMutex6(threadMutexLockGuard, std::ref(mtx));
  sleep_for(microseconds(20));
  thread threadMutex7(threadMutexLockGuard, std::ref(mtx));
  threadMutex6.join();
  threadMutex7.join();


  // std::once_flag
  // std::adopt_lock_t
  // std::defer_lock_t
  // std::try_to_lock_t

  // std::try_lock    尝试同时对多个mutex上锁
  // std::lock        同时对多个mutex上锁
  // std::call_once   多线程对某个函数只调用一次

}

void multiThreadTest(void)
{
  threadTest();
  mutexTest();
}
