#include "stdafx.h"
#include "Item23.h"


Item23::Item23() :
  ItemBase("23")
{
}


Item23::~Item23()
{
}

void Item23::ItemEntry()
{
  //// Item 23: Prefer non-member non-friend functions to member functions
  // �������ԱΪpublic����������װ�Բ�������Ϊ�������û��������Ե��õ���Щ��Ա��
  // �Դ����ƣ�����ṩԽ������Ա���������Ա����ʹ��private�ģ��ͱ�¶��Խ��ĺ�����
  // ��Ԫ����ͬ��
  // ������ͬ�������ռ��¶������ⲿ��convenience function����Щ�������ܷ�����ķ�public��Ա��
  // ���ᵼ��ʹ�����Ա�ĺ�����࣬�����и��õķ�װ�ԡ�
  // ��һ���棬�����ڶ��ͷ�ļ��ﰴ����;���� ��Щconvenience function���û�ֻ�������Ҫ��ͷ�ļ����ɡ�
  // �����Щconvenience�����Ա���������޷������ֲ��ڶ��ͷ�ļ��С�
}