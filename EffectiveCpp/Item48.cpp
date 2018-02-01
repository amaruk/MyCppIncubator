#include "stdafx.h"
#include "Item48.h"


Item48::Item48() :
  ItemBase("48")
{
}


Item48::~Item48()
{
}

void Item48::ItemEntry()
{
  //// Item 48: Be aware of template metaprogramming
  // Template MetaProgramming (TMP): ��д����ģ���C++����ִ���ڱ����ڡ�
  // �൱��template metaprogram����c++��д���ɱ�����ִ�еĳ���ִ�е����Ϊģ���ʵ�������г�����롣
  // ������typeid�ж���������������ִ�еı�̷�ʽ����Item47��trait���ڱ���������жϡ�

  // TMP��֤����ͼ���걸�ģ�Turing-complete�������κοɼ�������ⶼ�ɱ������
  // ��ѭ�����õݹ�ģ��ʵ������ʵ�֡�

  // �ȽϺõ�TMPʵ����
  // 1. Ensuring dimensional unit correctness. ��֤���ּ�����������ȷ������ġ�
  // 2. Optimizing matrix operations. ʹ��expression template�������㣬�����ֱ��ʽ����ʽ���䡣
  // 3. Generating custom design pattern implementations. ʹ��policy-based designʵ�֣���Ϊgenerative programming��
}
