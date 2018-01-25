#include "stdafx.h"
#include "Item34.h"


Item34::Item34() :
  ItemBase("34")
{
}


Item34::~Item34()
{
}

namespace ITEM34
{
  // �д��麯��������abstract class�����ܲ���ʵ��
  class BaseClass
  {
  public:
    virtual void PureVirtualFunc() = 0
    {
      cout << "BaseClass: PureVirtualFunc" << endl;
    }

    virtual void VirtualFuncNoOverride()
    {
      cout << "BaseClass: VirtualFuncNoOverride" << endl;
    }

    virtual void VirtualFuncOverride()
    {
      cout << "BaseClass: VirtualFuncOverride" << endl;
    }

    void Func()
    {
      cout << "BaseClass: Func" << endl;
    }
  };

  class DerivedClass : public BaseClass
  {
  public:
    void PureVirtualFunc() override
    {
      cout << "DerivedClass: PureVirtualFunc" << endl;
    }

    void VirtualFuncOverride() override
    {
      cout << "DerivedClass: VirtualFuncOverride" << endl;
    }

    // ��Ӧ�ö����������ͬ�ĺ���
#if 0
    void Func()
    {
      cout << "DerivedClass: Func" << endl;
    }
#endif
  };
}

void Item34::ItemEntry()
{
  //// Item 34: Differentiate between inheritance of interface and inheritance of implementation
  // ���麯����������inherit interface������Ҫ���������ṩʵ�֣�������һ�㲻�ṩĬ��ʵ��
  // ��ͨ�麯����������inherit interface��default implementation��
  // ��ͨ������������inherit interface��mandatory implementation���������������в�ͬ����Ϊ��

  ITEM34::DerivedClass derived{};

  // ����������ʵ�ֵĴ��麯��
  derived.PureVirtualFunc();
  // ���û���ʵ�ֵĴ��麯��
  derived.BaseClass::PureVirtualFunc();

  // ����û��override���麯��
  derived.VirtualFuncNoOverride();
  // ����override���麯��
  derived.VirtualFuncOverride();

  // ������ͨ����
  derived.Func();
}
