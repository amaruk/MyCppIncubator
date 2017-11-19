#pragma once
#include "common.h"

class Item02
{
public:
  Item02();
  ~Item02();

  static const int NumTurns = 5; // ��������ĳ�Ա�����static��const�����ͣ�integer��char��bool����������Ϊ����
                                 // ������ʵ���ļ�����ܷ��ڴ�ͷ�ļ��У���Ϊ��ֵ������ʱ�Ѿ�����������ʱ�����ٸ���ֵ
  int scores[NumTurns];   // ���������������Ļ����á�enum hack����ʵ�֣����£�

  enum {EnumNumTurns = 5};  // Enum hack
  int scoresEnum[EnumNumTurns];

};

//#define CALL_WITH_MA(a,b) f((a)>(b) ? (a) : (b))
// �滻Ϊ
template <typename T>
inline T callWithMax(const T& a, const T& b)
{
  return (a > b) ? a : b;
}

void ExampleItem02();
