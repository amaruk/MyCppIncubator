#include "stdafx.h"
#include "Item28.h"


Item28::Item28() :
  ItemBase("28")
{
}


Item28::~Item28()
{
}

void Item28::ItemEntry()
{
  //// Item 28: Avoid returning "handles" to object internals.
  // handleָ�����ڻ����һ������ķ�������reference��pointer��iterator��
  // ������Ա��������ʹ��const������handle��������߿�ʹ��handle�޸����ڲ���˽�г�Ա����Щ��Ա��ò���˽�С�
  // ����const��handle�൱�ڸ��û�ֻ����handle���ɽ�������⡣
  // ����ʹ����const��handle���û���Ȼ�����Լ�����ָ��ָ��handle��ָ������ݣ�֮������ṩ��handle�Ķ������٣��û����е�ָ�뼴���ա�
  // �����ܱ����ó�Ա��������handle�������Ǿ��ԵĹ���
}