#include "stdafx.h"
#include "Item33.h"


Item33::Item33() :
  ItemBase("33")
{
}


Item33::~Item33()
{
}

void Item33::ItemEntry()
{
  //// Item 33: Avoid hiding inherited names
  // �����������Ĺ�ϵ��������Ϊ������Ϊһ�δ������ڵĴ��룬������Ϊ������һ�δ������ڵĴ��롣
  // �ڲ���Χ��ͬ����Ա�������ⲿ��Χ�ĳ�Ա��ע����ͬ���������������ں����ͣ������Ǻ����Ĳ�����
  // ���������������� using Base::fun;����������fun���������ص�fun
}