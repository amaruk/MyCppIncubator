#include "stdafx.h"
#include "Item13.h"


Item13::Item13() :
  ItemBase("13")
{
}


Item13::~Item13()
{
}

void Item13::ItemEntry()
{
  //// Item 13: Use objects to manage resources.
  // ��һ�δ�������new����ִ�д��룬���delete���ܻ���Ϊ�м����ִ�г���������û��delete���й©��
  // �����use objects to manage resourcesָResource Acquisition Is Initialization (RAII)��
  // ��Ϊ������Դ�ͳ�ʼ����Դ������һ��ͬʱobject������ʱ��֤�ͷ���Դ��
  // auto_ptr��RAII��һ��ʵ��
  // shared_ptr��reference-counting smart pointer (RCSP)��һ��ʵ�֣��ܼ�¼�ж��ٶ���ָ��ͬһ����Դ��
  // ��û�ж���ָ����Դʱ�ͷ���Դ���������ͷųɻ������á�
}
