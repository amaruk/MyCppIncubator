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
  // 从duration模板创建特定类型的类
  using shakes = duration<int, std::ratio<1, 100000000>>;
  using jiffies = duration<int, std::centi>;
  using microfortnights = duration<float, std::ratio<12096, 10000>>;
  using nanocenturies = duration<float, std::ratio<3155, 1000>>;

  cout << "==== Duration Test ====" << endl;

  seconds sec(1);

  cout << "1 second is:" << endl;

  // 无类型转换，无精度损失的整形缩放。
  // 直接把一种duration作为另一种duration的参数构造。
  cout << microseconds(sec).count() << " microseconds." << endl
    << shakes(sec).count() << " shakes." << endl
    << jiffies(sec).count() << " jiffies." << endl;

  // 显式类型转换，有精度损失。
  cout << duration_cast<minutes>(sec).count() << " minutes." << endl;

  // 无类型转换的浮点缩放
  cout << microfortnights(sec).count() << " microfortnights." << endl
    << nanocenturies(sec).count() << " nanocenturies." << endl;
}

void chronoTest(void)
{
  /*
   * 三种主要类型:
   * - Duration：某种时间单位表示的时间段，如42秒用duration表示为42个1秒时间单元的tick
   * - Clock：
   * - Time point
   */
  durationTest();
}
