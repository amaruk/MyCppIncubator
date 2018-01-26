#include "stdafx.h"
#include "Item36.h"


Item36::Item36() :
  ItemBase("36")
{
}


Item36::~Item36()
{
}

namespace ITEM36
{
  class BaseClass
  {
  public:
    void NonVirtual() { cout << "BASE NonVirtual" << endl; }
    virtual void Virtual() { cout << "BASE Virtual" << endl; }
  };

  class DerivedClass : public BaseClass
  {
  public:
    void NonVirtual() { cout << "DERIVED NonVirtual" << endl; }
    void Virtual() override { cout << "DERIVED Virtual" << endl; }
  };
}

void Item36::ItemEntry()
{
  using ITEM36::BaseClass;
  using ITEM36::DerivedClass;

  //// Item 36: Never redefine an inherited non-virtual function
  BaseClass& baseRef = DerivedClass();
  DerivedClass& derivedRef = DerivedClass();

  // ���¶�ָ������ö�����:
  // ���÷�virtual����ʱ����̬��
  // baseRef�Ƕ�BaseClass��������ã�������ĺ���
  // derivedRef�Ƕ�DerivedClass��������ã���������ĺ���
  // �ɴ˿������Ϊʲô�������������Ҫ����Ϊ�麯������Ϊ���������������������Լ��������������������������麯�����ھ�̬�������ൽ��������ʱֻ�ܵ��������������
  baseRef.NonVirtual();
  derivedRef.NonVirtual();
  // ����virtual����ʱ����̬��
  // baseRef��derivedRef���Ƕ�DerivedClass��������ã���������ĺ���
  baseRef.Virtual();
  derivedRef.Virtual();
}
