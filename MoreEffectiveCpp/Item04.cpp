#include "stdafx.h"
#include "Item04.h"

Item04::Item04() :
  ItemBase("04")
{
}


Item04::~Item04()
{
}

namespace ITEM04
{
  class NoDefaultCtor
  {
  public:
    NoDefaultCtor(int i) {};
  };
}

using ITEM04::NoDefaultCtor;

void Item04::ItemEntry()
{
  // Item04: Avoid gratuitous default constructors.

  // ���Ĭ�Ϲ��캯�������ã����޷�����array��Ҳ�޷��ڶ���new��array
  //NoDefaultCtor noDefaultCtor{};
  //NoDefaultCtor noDefaultCtorAry[3];
  //NoDefaultCtor *noDefaultCtorAryPtr = new NoDefaultCtor[3];

  // �������: ��ʽ���÷�Ĭ�Ϲ��캯��
  NoDefaultCtor noDefaultCtorAry[3] =
  {
    NoDefaultCtor(1),
    NoDefaultCtor(2),
    NoDefaultCtor(3)
  };

  // ���ڶ���new��array��һ��һ��new����ָ������Ԫ��һ��һ����

  // û��Ĭ�Ϲ��캯������һ���������޷�ʹ�û���ģ���������
  // ģ��������һ�㶼��Ҫ���������ṩĬ�Ϲ��캯������Ϊģ���ڲ�����arrayʵ�ֵġ�

  // û��Ĭ�Ϲ��캯���������Ҫ�����������ṩ�乹����Ҫ�Ĳ���

  // �����Ĭ�Ϲ��캯����������Ķ���û�д��ڵ�ʵ�����壬��ʹ�����ϵ�������ڣ�Ҳ��Ҫ�ṩĬ�Ϲ��캯��
}
