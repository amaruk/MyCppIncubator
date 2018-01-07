#include "stdafx.h"
#include "Item02.h"

Item02::Item02() :
  ItemBase("02")
{
}


Item02::~Item02()
{
}

const int Item02::NumTurns; // ���������岻����ͷ�ļ���

void Item02::ItemEntry()
{
  // Item 2: Prefer consts, enums, and inlines to #defines
  // ��Ԥ����Ĺ���ת��Ϊ�������Ĺ���

  // ��const��������궨�壬��
  // #define ASPECT_RATIO 1.653
  // �滻Ϊ
  // const double AspectRatio = 1.653;
  cout << "static const int class member: " << Item02::NumTurns << endl;

  // �궨��ĺ�����inline�ĺ���ģ�����滻
  cout << "max value of (1,2) is: " << callWithMax(1, 2) << endl;
}
