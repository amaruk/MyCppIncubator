#include "stdafx.h"
#include <iostream>
#include <vector>
#include "Item22.h"

using std::cout;
using std::endl;
using std::unique_ptr;
using std::make_unique;
using std::shared_ptr;
using std::make_shared;
using std::vector;


void item22(void)
{
  cout << endl << "----- Item 22 -----" << endl;
  cout << ">> ..." << endl;

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
