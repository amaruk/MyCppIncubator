#include "stdafx.h"
#include "MultiThreadTest.h"
#include <iostream>
#include <thread>

/*
 * ���̱߳����ص�ͷ�ļ���
 * atomic��������atomic��atomic_flag���Լ�C����ԭ�����ͺ�ԭ�Ӳ�������
 * thread��thread�࣬this_thread�����ռ�
 * mutex�������������mutex��lock_guard��unique_lock
 * condition_variable������������أ�condition_variable��condition_variable_any
 * future��Provider��promise��package_task��future��future��shared_future
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
