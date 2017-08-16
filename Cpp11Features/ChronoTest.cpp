#include "stdafx.h"
#include "ChronoTest.h"
#include <iostream>
#include <string>
#include <chrono>
#include <ctime>
#include <iomanip>

using std::cout;
using std::endl;
using std::chrono::duration;
using std::chrono::seconds;
using std::chrono::microseconds;
using std::chrono::minutes;
using std::chrono::hours;
using std::chrono::duration_cast;
using std::chrono::system_clock;
using std::chrono::steady_clock;

ChronoTest::ChronoTest()
{
}


ChronoTest::~ChronoTest()
{
}

void durationTest(void)
{
  // ��durationģ�崴���ض����͵���
  using shakes = duration<int, std::ratio<1, 100000000>>;
  using jiffies = duration<int, std::centi>;
  using microfortnights = duration<float, std::ratio<12096, 10000>>;
  using nanocenturies = duration<float, std::ratio<3155, 1000>>;

  cout << endl << "==== Duration Test ====" << endl;

  seconds sec(1);

  cout << "1 second is:" << endl;

  // ������ת�����޾�����ʧ���������š�
  // ֱ�Ӱ�һ��duration��Ϊ��һ��duration�Ĳ������졣
  cout << microseconds(sec).count() << " microseconds." << endl
    << shakes(sec).count() << " shakes." << endl
    << jiffies(sec).count() << " jiffies." << endl;

  // ��ʽ����ת�����о�����ʧ��
  cout << duration_cast<minutes>(sec).count() << " minutes." << endl;

  // ������ת���ĸ�������
  cout << microfortnights(sec).count() << " microfortnights." << endl
    << nanocenturies(sec).count() << " nanocenturies." << endl;

  // Windows�ľ��ȵ�100ns��Linux�ľ��ȵ�ns��
  // ʹ����������ӡĬ�Ͼ��ȣ��Ա�windows��linuxλ����
  // cout << std::chrono::system_clock::now().time_since_epoch().count() << endl;
}

void clockTimepointTest(void)
{
  /*
   * system_clock��system-wide real time wall clock. ��һ����monotonic��
   *    û��ָ��ϵͳʱ�Ӵ��ĸ���Ԫ��ʼ����һ�㶼��
   *    00:00:00 UTC Thursday 1 January 1970
   * steady_clock������wall clock���������ƴ�ϵͳ������ʼ������Ϊֹ��ʱ������monotonic��
   * high_resolution_clock��ʹ����Сtick�����clock��
   *    ���ܵ�ͬ��system_clock����steady_clock����ĳ������clock
  */

  cout << endl << "==== Clock and Timepoint Test ====" << endl;
  system_clock::time_point now = system_clock::now();
  std::time_t ctimeNow = system_clock::to_time_t(now - hours(24));
  cout << "24 hours ago, the time was: "
    << std::put_time(std::localtime(&ctimeNow), "%F %T") << endl;

  steady_clock::time_point start = steady_clock::now();
  cout << "Hello, Chrono." << endl;
  steady_clock::time_point end = steady_clock::now();
  cout << "Print hello takes: "
    << duration_cast<microseconds>(end - start).count()
    << " us." << endl;
}

void chronoTest(void)
{
  /*
   * ������Ҫ����:
   * - Duration��ĳ��ʱ�䵥λ��ʾ��ʱ��Σ���42����duration��ʾΪ42��1��ʱ�䵥Ԫ��tick
   * - Clock������ʼ��Ԫ��epoch����tick rate��ɡ�����ʼ��1970��1��1�գ�tickΪ��
   * - Time point��ʱ���
   */
  durationTest();
  clockTimepointTest();
}
