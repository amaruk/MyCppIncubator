#include "stdafx.h"
#include "Item08.h"


Item08::Item08() :
  ItemBase("08")
{
}


Item08::~Item08()
{
}

void Item08::ItemEntry()
{
  //// Item 8: Prevent exceptions from leaving destructors
  // ����������Ӧ���׳��쳣����������������try catch�������쳣
  // ���Կ����ṩ�����û�API����ʽ�������������Ҫִ�еĿ����׳��쳣����������
  // ������������Ҳ��try catch���ô˺�����������û�Ը��ִ�����������쳣�������ô˺�����
  // ������������������ò���ȡĬ�ϵ��쳣����ʹ���
}
