#include "stdafx.h"
#include "Chapter5.h"
#include <vector>
#include <string>

using std::cout;
using std::endl;
using std::vector;
using std::string;

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
  //
  // ���������T&&Ϊuniversal reference��auto��������Ϊ������ģ�����
  // ԭ����type deduction
  // template<typename T>
  // void f(T&& param);           // Universal reference
  // auto&& var2 = var1;          // Universal reference
  // universal reference����ֵ��ʼ����Ϊ��ֵ���ã�����ֵ��ʼ����Ϊ��ֵ���ã��磺
  // Widget w;
  // f(w);                        // wΪ��ֵ��param����ΪWidget&��ֵ����
  // f(std::move(w));             // move֮������ת��Ϊ��ֵ��param����ΪWidget&&��ֵ����
  // ��Ҫע�����޶���������£�T&&�Ͳ���universal reference�ˣ��磺
  // template<typename T>
  // void f(std::vector<T>&& param);  // param����ֵ����
  // vector<int> v;
  // f(v);                            // ����v����ֵ�����ܰ󶨵���ֵ����
  // template<typename T>
  // void f(const T&& param);         // ����const֮��paramҲ����universal reference������ֵ����
  // ��������ֻ��T&&���־���universal reference



}
