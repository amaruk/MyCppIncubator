#include "stdafx.h"
#include "Item03.h"

Item03::Item03() :
  ItemBase("03")
{
}


Item03::~Item03()
{
}


void Item03::ItemEntry()
{
  // Item03: Never treat arrays polymorphically.

  // ��������ʹ���±�λԪ�ص�ʱ���Ԫ�صĳߴ���Ϊƫ�ƣ������������ʵ�ʴ�������������Ļ���������ȷ������ʱ�±�����ƫ�Ʋ����ࡣ
  // ͬ����delete[]����ʱ��Ҳ����Ϊƫ�Ʋ���ȷ������δ������Ϊ
}
