#include "stdafx.h"
#include "Item18.h"


Item18::Item18() :
  ItemBase("18")
{
}


Item18::~Item18()
{
}

struct DayType
{
  explicit DayType(int d)  :
  val(d)
  {}

  int val;
};

class MonthType
{
public:
  static MonthType Jan() { return MonthType(1); }
  static MonthType Dec() { return MonthType(12); }

private:
  explicit MonthType(int m) :
    val(m)
  {}

  int val;
};

struct YearType
{
  explicit YearType(int y) :
    val(y)
  {}

  int val;
};

class DateClass {

public:

  // �����κ����ƵĹ��캯�����£�ʹ���߿��ܴ�����·�̫�󣬸��������ڣ��ȵ�
  //DateClass(int month, int day, int year) {}

  // �ýṹ��װ�ꡢ�¡��գ����ٴ���ʹ�õĻ��ᣬ�����ڱ����ڼ��ɷ���
  DateClass(YearType y, MonthType m, DayType d) {}

};


void Item18::ItemEntry()
{
  //// Item 18: Make interfaces easy to use correctly and hard to use incorrectly
  // ���紦�������յĽӿڣ������Ҫ�ýӿڵ�ʹ���߾������ٴ���ʹ�õĻ��ᣬ���Զ���ṹ��װ

  //DateClass(1, 2, 3); // ����explicit���캯�������Բ�����int��ʽת��
  //DateClass(MonthType(1), DayType(1), YearType(1970)); // ��������˳�����Ҳ���ڱ����ڷ���
  DateClass(YearType(1970), MonthType::Jan(), DayType(1)); // ��ǿMonthType��������ַǷ��·�

}