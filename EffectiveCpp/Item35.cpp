#include "stdafx.h"
#include "Item35.h"


Item35::Item35() :
  ItemBase("35")
{
}


Item35::~Item35()
{
}

void Item35::ItemEntry()
{
  //// Item 35: Consider alternatives to virtual functions
  // Non-virtual interface (NVI) idiom: ��public�ķ�virtual���������private���麯�������ģʽ�г�Ϊtemplate method
  // Strategy���ģʽ���ú���ָ������麯��
  // Strategy���ģʽ����ʹ��function������Ǻ���ָ��
  // ��ͳ��Strategy���ģʽ
}
