#include "stdafx.h"
#include "Item14.h"


Item14::Item14() :
  ItemBase("14")
{
}


Item14::~Item14()
{
}


void Item14::ItemEntry()
{
  //// Item 14: Think carefully about copying behavior in resource-managing classes.
  // ʵ��RAII���ʱ��Ҫע�⴦����������
  // 1. �ѿ���������Ϊprivate����������
  // 2. ����ʱ���Ӽ�������shared_ptrʵ�֣��Զ���shared_ptr��deleter
  // 3. ʵ�������RAII���е���ԴҲ����һ��
  // 4. ����ʱת��RAII���е���Դ

}
