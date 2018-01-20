#include "stdafx.h"
#include "Item27.h"


Item27::Item27() :
  ItemBase("27")
{
}


Item27::~Item27()
{
}

namespace ITEM27
{
  class BaseClass
  {
  public:
    BaseClass() = default;
    virtual ~BaseClass() = default;

    virtual void changeName(string newName) { m_name = "BASE-" + newName; }
    virtual void printName() { cout << "BASE NAME: " + m_name << endl;; }
  private:
    string m_name{ "BASE-Default" };
  };

  class DerivedClass : public BaseClass
  {
  public:
    DerivedClass() = default;

    void changeName(string newName) override
    {
      // ����ĵ��û��෽���������һ��������Ŀ��������õ�changeName�ǿ����õ��Ķ���ĳ�Ա��
      // ���µ��ú�˺�����ԭ�������Ĳ���û�б仯��������Ĳ��ֱ��޸�
      //static_cast<BaseClass>(*this).changeName(newName);

      // ��ȷ�ĵ��û����Ա��������
      BaseClass::changeName(newName);

      m_name = "DERIVED-" + newName;
    }

    void printName() override
    {
      BaseClass::printName();
      cout << "DERIVED NAME: " + m_name << endl;;
    }

  private:
    string m_name{ "DERIVED-Default" };
  };
}

void Item27::ItemEntry()
{
  //// Item 27: Minimize casting.
  // ��ʽC�������ת����ֻ��д����ͬ����û�в��
  // 1. (T)expression
  // 2. T(expression)
  // C++�������ת����
  // 1. const_cast<T>(expression)
  //    Ψһ����ȥ��const��C++����ת��
  // 2. dynamic_cast<T>(expression)
  //    �����ڼ̳нṹ��safe downcasting����C��������ת���޷�ʵ�֡�������ʱ������Ӱ��Ƚϴ���Ϊ�кܶ�ʵ����Ҫ�Ƚ��������ַ�����
  // 3. reinterpret_cast<T>(expression)
  //    �ײ�����ת��������ָ��תint�����ǵײ���뾡�����á�
  // 4. static_cast<T>(expression)
  //    ����ǿ����ʽת�������constתconst��intתdouble��void*ת����ָ�룬ָ������ָ��ת������ָ�롣

  ITEM27::DerivedClass derivedIns{};
  cout << endl << "-----Print default values" << endl;
  derivedIns.printName();
  cout << endl << "-----Print changed values" << endl;
  derivedIns.changeName("Changed");
  derivedIns.printName();
  
}