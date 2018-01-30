#include "stdafx.h"
#include "Item45.h"


Item45::Item45() :
  ItemBase("45")
{
}


Item45::~Item45()
{
}

namespace ITEM45
{
  // ģ������ָ���ʵ��
  template<typename T>
  class MySmartPointer
  {
  public:

    MySmartPointer(T t) { cout << "MySmartPointer<T>::CTOR(T)" << endl; }

    // ����ͨ�����������͵Ŀ������캯�� generalized copy constructor��
    // �ض����͵�ģ��ʵ������ ������ͬһ��ģ��Ĳ�ͬ����ʵ������ ������
    // ��ʾMySmartPointer<T>������MySmartPointer<S>����
    // ����ʱS��T�����໥����
    template<typename S>
    MySmartPointer(const MySmartPointer<S>& another)
    { cout << "MySmartPointer<T>::CTOR(MySmartPointer<S>)" << endl; }
  };

  // ֻ֧���ܹ���ʽ����ת���Ĺ��캯��
  template<typename T>
  class MySmartPointerAdvanced
  {
  public:

    MySmartPointerAdvanced(T t) : m_typeT(t) { cout << "MySmartPointerAdvanced<T>::CTOR(T)" << endl; }

    // 
    template<typename S>
    MySmartPointerAdvanced(const MySmartPointerAdvanced<S>& another) :
      m_typeT(another.m_typeT) // ���������ʽ����ת����������
    {
      cout << "MySmartPointerAdvanced<T>::CTOR(MySmartPointerAdvanced<S>)" << endl;
    }

    T m_typeT;
  };


}

void Item45::ItemEntry()
{
  //// Item 45: Use member function templates to accept "all compatible types."
  // Member function template���member template������Ϊ�����ɳ�Ա�����ĺ���ģ��
  using ITEM45::MySmartPointer;
  MySmartPointer<int> intIns{123};
  MySmartPointer<double> doubleIns{ intIns };
  MySmartPointer<int> intInsAnother{ doubleIns };

  using ITEM45::MySmartPointerAdvanced;
  MySmartPointerAdvanced<int> intAdvIns{ 123 };
  MySmartPointerAdvanced<double> doubleAdvIns{ intAdvIns }; // int ��ת double
  //MySmartPointerAdvanced<int> intAdvInsAnother{ doubleAdvIns }; // double ����ת int���������

}