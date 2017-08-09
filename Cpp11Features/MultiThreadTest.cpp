#include "stdafx.h"
#include "MultiThreadTest.h"
#include <iostream>
#include <thread>

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


MultiThreadTest::MultiThreadTest()
{
}


MultiThreadTest::~MultiThreadTest()
{
}

void thread_main(void)
{
  cout << "Thread main." << endl;
}

void multiThreadTest(void)
{
  thread thread1(thread_main);
  thread1.join();
}
