#include "stdafx.h"
#include "Item12.h"


Item12::Item12() :
  ItemBase("12")
{
}


Item12::~Item12()
{
}

void Item12::ItemEntry()
{
  //// Item 12: Copy all parts of an object
  // Copy all parts�������ֺ��壬1.ȷ��������������г�Ա 2.ȷ��������������г�Ա����ϸ���£�
  // 1. copy function�������������캯���Ϳ�����������ʵ��֮�����������Ա����Ҫ�ֶ�������Щ��Ա�Ŀ���������copy function
  // 2. �������copy function������û����Ӧ��copy function��������ܻ���Ϊ���÷ǿ����İ汾���»���ĳ�Աû�б�����
  // DerivedClass::DerivedClass(const DerivedClass& rhs) : BaseClass(rhs)
  // DerivedClass::operator=(const DerivedClass& rhs) { BaseClass::operator=(rhs); }

  // ע�ⲻҪ�ڿ�����ֵ������ʵ���е��ÿ������캯����Ҳ��Ҫ���������á�
  // ����private��init������ִ����ͬ�Ŀ����������ڿ�����ֵ�������Ϳ������캯������á�
}
