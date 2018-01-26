#include "stdafx.h"
#include "Item37.h"


Item37::Item37() :
  ItemBase("37")
{
}


Item37::~Item37()
{
}

namespace ITEM37
{
  class BaseClass
  {
  public:
    virtual void Virtual(string par = "BaseDefaultPar") { cout << "BASE Virtual: " << par << endl; }
  };

  class DerivedClass : public BaseClass
  {
  public:
    void Virtual(string par = "DerivedDefaultPar") override { cout << "DERIVED Virtual: " << par << endl; }
  };

  class AnotherDerivedClass : public BaseClass
  {
  public:
    void Virtual(string par) override { cout << "ANODERIVED Virtual: " << par << endl; }
  };
}
void Item37::ItemEntry()
{
  using ITEM37::BaseClass;
  using ITEM37::DerivedClass;
  using ITEM37::AnotherDerivedClass;
  //// Item 37: Never redefine a function's inherited default parameter value
  // �麯����̬�󶨣�dynamic binding��late binding��������Ĭ��ֵ��̬�󶨣�static binding��early binding��
  // ��̬�������������ڴ��������ϵ����ͣ��͸���Ķ��������޹ء�
  BaseClass* pB1;                           // ��̬����ΪBaseClass*����̬����û�У���Ϊ��û��ֵ
  BaseClass* pB2 = new DerivedClass;        // ��̬����ΪBaseClass*����̬����ΪDerivedClass*
  BaseClass* pB3 = new AnotherDerivedClass; // ��̬����ΪBaseClass*����̬����ΪAnotherDerivedClass*
  // ͨ����ֵ���Ըı䶯̬����
  // �麯���Ƕ�̬�󶨵ģ�������Ĭ��ֵΪ�����Ч���Ǿ�̬�󶨵ģ����Բ�����ֵ̬���ǻ���ľ�ֵ̬
  pB2->Virtual();
  pB3->Virtual();
  delete pB2;
  delete pB3;

}
