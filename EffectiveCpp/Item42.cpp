#include "stdafx.h"
#include "Item42.h"


Item42::Item42() :
  ItemBase("42")
{
}


Item42::~Item42()
{
}

namespace ITEM42
{
  template<typename C>
  void f(const C& container, typename C::iterator iter) // C::iteratorΪnested dependent name
  {

  }
}

void Item42::ItemEntry()
{
  //// Item 42: Understand the two meanings of typename
  // �������ַ�ʽ����template����ͬ�ģ�
  // template<class T> class Widget;
  // template<typename T> class Widget;
  // ��ģ���ڲ�������ģ���������ȷ�����͵����ֽ�dependent name����typename C��C��ģ���ڲ��õ��ĵط�
  // ���dependent name������ĳ����ģ����Ϊnested dependent name����C::iterator
  // ������ģ���������ȷ�����͵����ֽ�non-dependent name����int���͵ı�������

  // ��Ϊnested dependent name�ڲ�֪��Cϸ�ڵ�ʱ���޷�ȷ����Ϊ���ͻ���C�ĳ�Ա������ӦΪ����ʱ������ǰ�����typename�ؼ���



}
