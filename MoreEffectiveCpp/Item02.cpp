#include "stdafx.h"
#include "Item02.h"

Item02::Item02() :
  ItemBase("02")
{
}


Item02::~Item02()
{
}


void Item02::ItemEntry()
{
  // Item02: Prefer C++-style casts.

  // static_cast������C������ת��������ת��constness��
  // const_cast����ֻת��constness��volatileness��
  // dynamic_castֻ�����ڼ̳в㼶�У���ָ������ôӻ���ת��Ϊ��������ֵ��࣬����ͨ�����ת������Ƿ�Ϊnull���ж�ת���Ƿ�ɹ���
  // reinterpret_cast�͵ײ�ʵ�ְ󶨣���ֲ�Բ�

  // ����shared_ptr�ö�Ӧ�ģ�
  // static_pointer_cast, dynamic_pointer_cast, const_pointer_cast, reinterpret_pointer_cast
}
