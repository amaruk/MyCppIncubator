#include "stdafx.h"
#include "Item30.h"


Item30::Item30() :
  ItemBase("30")
{
}


Item30::~Item30()
{
}

void Item30::ItemEntry()
{
  //// Item 30: Understand the ins and outs of inlining.
  // ���ڱ�������˵��inline��request������command
  // ��ʽ��inlineΪ���������ڲ��ĳ�Ա��������Ԫ����
  // ��ʽ��inlineΪ���������inline�ؼ���
  // ������inline��templateʱ�������е�ʵ������inline
  // ��̬���ӿ����к���Ϊinline�����ı���Щ����ʱ�����û��������±��������õ���Щ�������ļ���
  // �������inline�ģ��ı���Щ�����󣬿��û�ֻҪ����link���ɡ�
  // ����Ƕ�̬���ӿ⣬���û��޷��������inline�ĺ����ı䡣
}