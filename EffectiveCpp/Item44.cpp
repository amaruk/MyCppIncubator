#include "stdafx.h"
#include "Item44.h"


Item44::Item44() :
  ItemBase("44")
{
}


Item44::~Item44()
{
}

void Item44::ItemEntry()
{
  //// Item 44: Factor parameter-independent code out of templates
  // ����������ģ��ʵ����ʱ��ֻ�б�������õ��ĳ�Ա�����Ż�ʵ����
  // ���ǲ�С�ĵĻ�������ɿ������������룬���������ɺܶ��ظ��Ĳ��֡�Code bloat��
  // Ϊ�˱�������������֣�Ҫ��commonality and variability analysis.
  // �ҵ�template�����Ϊģ�����Ͳ�ͬ�������ظ��Ĵ��룬���ⲿ�ִ����ģ������ȥ��
}
