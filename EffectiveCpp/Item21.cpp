#include "stdafx.h"
#include "Item21.h"


Item21::Item21() :
  ItemBase("21")
{
}


Item21::~Item21()
{
}

void Item21::ItemEntry()
{
  //// Item 21: Don't try to return a reference when you must return an object
  // �����Ѿֲ�������ջ�ڣ���Ϊ���÷��أ������ַ��Ϊָ�뷵�أ�����Ϊ�ֲ������ڽ���������������������Ч�����ú�ָ�롣
  // ��new�ڶ��Ϸ���ռ䣬�����ض����ǿ��еģ���Ҫ������ʹ��������delete����������
  // ���Ը��ÿ������ص�ʱ����Ҫ�ÿ������ء�

}