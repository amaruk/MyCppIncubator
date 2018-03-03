#include "stdafx.h"
#include "Item01.h"

Item01::Item01() :
  ItemBase("01")
{
}


Item01::~Item01()
{
}


void Item01::ItemEntry()
{
  // ���ں���ģ����˵��Paramtype�Ǻ�T��ص�����������޶����Ĳ��֣���const T&����
  // template<typename T>
  // void f(ParamType param);

  // �ڵ������ģ��ʱ��
  // f(expr);
  // ��������expr�Ƶ���T��ParamType
  
  // ������������£��Ƶ�����������expr����������ParamType����ʽ��

  // 1. ParamType��ָ������ã�������universal reference
  // �������expr�����ã���������ò��֣�������expr������ȥ��ParamType��ģʽ������T
  //
  // ���õ�������磺
  // template<typename T>
  // void f(T& param);        // ParamType������
  //
  // int x = 27;
  // f(x);                    // T��int��param����Ϊint&
  //
  // const int cx = x;
  // f(cx);                   // T��const int, param����Ϊconst int&
  //
  // const int& rx = x;
  // f(rx);                   // T��const int��param����Ϊconst int&
  //                          // expr�����ã���������������ò��ֺ��൱�����b
  //
  // ָ���������磺
  // template<typename T>
  // void f(T* param);
  //
  // ���a��
  // int x = 27;
  // f(&x);                   // T��int��param����Ϊint*
  //
  // ���b��
  // const int *px = &x;
  // f(px);                   // T��const int��param����Ϊconst int*

  // 2. ParamType��universal reference
  // �������expr����ֵ��T��ParamType�����Ƶ�Ϊ��ֵ����
  // �������expr����ֵ������"1."�Ĺ����Ƶ�
  //
  // ���磺
  // template<typename T>
  // void f(T&& param);       // param��universal reference
  // 
  // int x = 27;
  // f(x);                    // xΪ��ֵ��T��int&��param����Ϊint&
  //
  // const int cx = x;
  // f(cx);                   // cxΪ��ֵ��T��const int&, param����Ϊconst int&
  //
  // const int& rx = x;
  // f(rx);                   // rxΪ��ֵ��T��const int&, param����Ϊconst int&
  //
  // f(27);                   // 27Ϊ��ֵ��T��int��param����ΪT&&

  // 3. ParamType�Ȳ���ָ��Ҳ��������
  // �൱�ڴ�ֵ�������������Կ��Ժ��Ը����޶���
  // �������expr�����ã��������ò��֣��������ú����expr��const������const�����expr��volatile������volatile
  //
  // ���磺
  // template<typename T>
  // void f(T param);
  //
  // int x = 27;
  // f(x);                    // T��param���Ͷ�Ϊint
  //
  // const int cx = x;
  // f(cx);                   // T��param���Ͷ�Ϊint
  //
  // const int& rx = x;
  // f(rx);                   // T��param���Ͷ�Ϊint
  //
  // const char* const ptr = "test";  // ��ߵ�const��ʾָ��ָ����ַ��������޸�
  //                                  // �ұߵ�const��ʾָ�������ֵ��ָ��ĵ�ַ�������޸�
  // f(ptr);                  // T��param���Ͷ�Ϊconst char*���ұߵ�const�����ԣ���ߵ�const����

  // ע��С�Ĵ���ԭʼarray�ͺ���ָ��
}
