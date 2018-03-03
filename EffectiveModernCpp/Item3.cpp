#include "stdafx.h"
#include "Item03.h"

Item03::Item03() :
  ItemBase("03")
{
}


Item03::~Item03()
{
}


void Item03::ItemEntry()
{
  // decltype: ��һ�����ֻ��߱��ʽ�����ض�Ӧ������

  // �����������
  //const int i = 0;              // decltype(i)Ϊconst int
  //bool f(const Widget& w);      // decltype(w)Ϊconst Widget&
  //                                 decltype(f)Ϊbool(const Widget&)
  // struct Point { int x,y; };   // decltype(Point::x)Ϊint
  // Widget w;                    // decltype(w)ΪWidget
  // if(f(w))...                  // decltype(f(w))Ϊbool
  // vector<int> v;               // decltype(v)Ϊvector<int>
  // if (v[0] == 0)...            // decltype(v[0])Ϊint&

  // C++11��decltype�����õĹ�����ʹ�ú����Ĳ������������������ķ�������
  // auto�����������ʹ�β�÷�������trailing return type�õ�
  // template<typename Container, typename Index>
  // auto authAndAccess(Container& c, Index i)
  // -> decltype(c[i]) {}
  // ��������ʹ���˲���c��i��������β�÷�������

}
