#include "stdafx.h"
#include "Item22.h"
#include <vector>
#include <memory>
#include "ClassHierarchy.h"

using std::cout;
using std::endl;
using std::unique_ptr;
using std::make_unique;
using std::shared_ptr;
using std::make_shared;
using std::vector;

Item22::Item22() :
  ItemBase("22")
{
}


Item22::~Item22()
{
}


void Item22::ItemEntry()
{
  // Pimpl Idiom: Pointer to implementation idiom
  // 
  // �ŵ�
  // �ı���˽�г�Ա��������Ҫ���±����õ������������� -> ���̱���ʱ�䣬���FragileBinaryInterfaceProblem
  // ͷ�ļ�����Ҫ����˽�в��ֵ�ʵ�����ͷ�ļ� -> ���ٱ���
  //
  // ������unique_ptrҲ������shared_ptrʵ��
  // unique_ptrʵ�����ر��ע�����
  // ���ԭ�ġ�
}
