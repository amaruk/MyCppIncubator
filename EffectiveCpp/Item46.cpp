#include "stdafx.h"
#include "Item46.h"


Item46::Item46() :
  ItemBase("46")
{
}


Item46::~Item46()
{
}

void Item46::ItemEntry()
{
  //// Item 46: Define non-member functions inside templates when type conversions are desired
  // non-member��ģ�庯��������£���Ҫ���Ƶ�typename��ʵ�����ͣ�������ʵ�ε���ʽ����ת����
  // ���԰�non-number�ĺ�����Ϊ��ģ���������Ԫnon-member�����������������壩���������Ƶ�typename��ʵ�����ͣ���ʱ����Ҳ�Ѿ��Ƶ������ͣ�ʵ�ο�������ʽ����ת����
  // ����ʱ����Ԫ������Ϊֱ�Ӷ���������������Ϊinline��Ϊ�˼���inline�Ŀ��������Դ���helper������Ԫ���������helper��

}