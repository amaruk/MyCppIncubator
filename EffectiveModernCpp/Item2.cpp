#include "stdafx.h"
#include "Chapter1.h"

using std::cout;
using std::endl;

void item2()
{
  cout << endl << "----- Item 2 -----" << endl;
  cout << ">> ..." << endl;

  // ���԰�auto����template
  // auto x = 27;
  // const auto cx = x;
  // const auto& rx = x;
  // �൱��auto��T��auto��const auto��const auto&ΪT��ParamType��T��const T��const T&
  //
  // ����auto���Ƶ������ģ��һ��������ԭʼָ��ͺ���ָ�룩������һ���������
  // auto x = 27;             // ��Ӧ"3."��x����ָ��Ҳ��������
  // const auto cx = x;       // ��Ӧ"3."��x����ָ��Ҳ��������
  // const auto& rx = x;      // ��Ӧ"1."��x�Ƿ�universal reference
  // auto&& uref1 = x;        // ��Ӧ"2."��x����ֵ���Ƶ�Ϊint&
  // auto&& uref2 = cx;       // ��Ӧ"2."��cx��const int��Ҳ����ֵ���Ƶ�Ϊint&
  // auto&& uref3 = 27;       // ��Ӧ"2."��27��int��ֵ���Ƶ�Ϊint&&
  //
  // �������
  // C++98��ʼ�������ַ�ʽ��
  //    int x1 = 27;
  //    int x2(27);
  // C++11�ṩ�Ķ��ⷽʽ��
  //    int x3 = { 27 };
  //    int x4{ 27 };
  // ����auto�滻int����ʱ
  //    auto x1 = 27;       // auto�Ƶ�Ϊint
  //    auto x2(27);        // ͬ��
  //    auto x3 = { 27 };   // auto�Ƶ�Ϊstd::initializer_list<int>
  //    auto x4{ 27 };      // ͬ��
  // �����������auto��������ŵ�initializer��initializer_list����template��Ҫ�ֶ�ָ��TypeParamΪinitializer_list����
  // C++14��auto����������ֵ��lambda���ʽ����ʱ�������Ƶ�������Ϊinitializer_list


}
