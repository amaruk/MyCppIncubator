#include "stdafx.h"
#include "ChronoTest.h"
#include <iostream>
#include <string>
#include <chrono>

using std::cout;
using std::endl;
using std::chrono::duration;
using std::chrono::seconds;
using std::chrono::microseconds;
using std::chrono::minutes;
using std::chrono::duration_cast;

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

  cout << "==== Duration Test ====" << endl;

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
}

void chronoTest(void)
{
  /*
   * ������Ҫ����:
   * - Duration��ĳ��ʱ�䵥λ��ʾ��ʱ��Σ���42����duration��ʾΪ42��1��ʱ�䵥Ԫ��tick
   * - Clock��
   * - Time point
   */
  durationTest();
}
