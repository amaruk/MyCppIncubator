#include "stdafx.h"
#include "MultiThreadTest.h"
#include <stdint.h>
#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

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
using std::mutex;
using std::timed_mutex;
using std::lock_guard;
using std::unique_lock;
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
  // Ĭ�Ϲ��캯�������յ�thread����
  // �������캯����Ϊdeleted
  // ֧���ƶ����캯��
  // ��ʼ�����캯������joinable��������֮ǰ���뱻���߳�join����Ϊdetached
  // ֧���ƶ�����������joinable�Ķ�����ֵ����
  // ������������Ϊdeleted
  //
  // ������Ա������
  // get_id/joinable/join/detach/swap/native_handle/hardware_concurrency[static]

  cout << endl << "====threadTest====" << endl;

  uint32_t runTimes = 2;
  thread threadConsDefault; // �޷�����
  thread threadConsValue(threadParValue, runTimes); // �߳�������������ֵ
  thread threadConsRef(threadParRef, std::ref(runTimes)); // �߳�����������������
  thread threadConsMove(std::move(threadConsRef)); // �ƶ����캯��
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
  {
    cout << "threadMutex " << get_id() << " excepted." << endl;
  }
}

void threadMutexUniqueLock(mutex &mtx)
{
  try
  {
    unique_lock<mutex> uniqueLock(mtx);
    //uniqueLock.lock(); // ����ͬʱִ��lock
    throw (std::logic_error("ERROR"));
    uniqueLock.unlock();
  }
  catch (std::logic_error &)
  {
    cout << "threadMutexUniqueLock " << get_id() << " excepted." << endl;
  }
}

void mutexTest(void)
{
  cout << endl << "====mutexTest====" << endl;

  // Mutex
  // std::mutex                 ����mutex
  // std::recursive_mutex       �ݹ�mutex��ͬһ���߳̿��Զ�ζ�ͬһ��mutex���������������ͬ����
  // std::time_mutex            ��ʱmutex����ָ��ʱ�������̣߳���ʱ����false
  // std::recursive_timed_mutex ��ʱ�ݹ�mutex

  // �մ�����mutexδunlocked״̬
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
  // std::lock_guard    ʵ��mutex�������ڵ�Mutex RAII��ֻ�й��캯��
  // std::unique_lock   ͬ�ϣ��ṩ���õ������ͽ������ƺ���
  // RAII: Resource Acquisition Is Initialization
  // ����Ĺ��캯���з�����Դ���������������ͷ���Դ��
  // ��һ�����󴴽���ʱ�򣬹��캯�����Զ��ر����ã�
  // ������������ͷŵ�ʱ����������Ҳ�ᱻ�Զ����á�
  // ��ʹ�쳣��������ԴҲ�������ͷ�

  cout << endl << "----MUTEX LOCK GUARD----" << endl;
  thread threadMutex6(threadMutexLockGuard, std::ref(mtx));
  sleep_for(microseconds(20));
  thread threadMutex7(threadMutexLockGuard, std::ref(mtx));
  threadMutex6.join();
  threadMutex7.join();

  cout << endl << "----MUTEX UNIQUE LOCK----" << endl;
  thread threadMutex8(threadMutexUniqueLock, std::ref(mtx));
  sleep_for(microseconds(20));
  thread threadMutex9(threadMutexUniqueLock, std::ref(mtx));
  threadMutex8.join();
  threadMutex9.join();

  // std::once_flag
  // std::adopt_lock_t
  // std::defer_lock_t
  // std::try_to_lock_t

  // std::try_lock    ����ͬʱ�Զ��mutex����
  // std::lock        ͬʱ�Զ��mutex����
  // std::call_once   ���̶߳�ĳ������ֻ����һ��

}

void multiThreadTest(void)
{
  threadTest();
  mutexTest();
}
