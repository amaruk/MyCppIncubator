#include "stdafx.h"
#include "Chapter5.h"

using std::cout;
using std::endl;

void item24()
{
  cout << endl << "----- Item 24 -----" << endl;
  cout << ">> ..." << endl;

  // T&&��һ������ֵ���ã����磺
  // void f(Widget&& param)         // ��ֵ����
  // Widget&& var1 Widget();        // ��ֵ����
  // auto&& var2 = var1;            // auto������universal reference
  // template<typename T>
  // void f(std::vector<T>&& param);// ��ֵ����
  // template<typename T>
  // void f(T&& param);             // ��Ϊ������ģ�������universal reference

  // T&&���԰󶨵���ֵ��ͬ��ֵ���ã���
  // ������Ϊ��ֵ���ã�
  // ���԰󶨵�const��non-const
  // ���԰󶨵�volatile��non-volatile
  // �������԰����ж��󡣿��Գ�Ϊuniversal reference��forwarding reference
  // ���������T&&Ϊuniversal reference��auto��������Ϊ������ģ�����
  // ԭ����type deduction
}
