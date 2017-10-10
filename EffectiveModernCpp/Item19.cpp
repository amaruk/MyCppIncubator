#include "stdafx.h"
#include "Item19.h"

using std::cout;
using std::endl;
using std::shared_ptr;
using std::make_shared;

std::shared_ptr<ClassBase> FactorySharedPtr::createInstDeleterDefault(int deriveType)
{
  if (deriveType == 1)
  {
    return make_shared<ClassDerived1>();
  }
  else
  {
    return make_shared<ClassDerived2>();
  }
}

auto FactorySharedPtr::createInstDeleterCustom(int deriveType)
{
  // ��Item18����ͬ��lambda���ʽ
  auto myDeleter = [](ClassBase *pClassBase)
  {
    cout << "myDeleter()" << endl;
    delete pClassBase;
  };

  // ��һ��lambda���ʽ
  auto myAnotherDeleter = [](ClassBase *pClassBase)
  {
    cout << "myAnotherDeleter()" << endl;
    delete pClassBase;
  };

  // ע��shared_ptr��unique_ptrʹ���Զ���deleterʱ������
  //unique_ptr<ClassBase, decltype(myDeleter)> pClassBase(nullptr, myDeleter);
  shared_ptr<ClassBase> pClassBase(nullptr, myDeleter);
  // ����shared_ptr��˵��deleter���������͵�һ����
  // ��deleter��Ϊunique_ptr��ģ��������������͵�һ����
  // �ɴ˿��Զ�����ͬ���͵�shared_ptr����ʹ�ò�ͬ��deleter
  shared_ptr<ClassBase> pAnotherClassBase(nullptr, myAnotherDeleter);
  // ʹ���Զ���deleter������shared_ptr�Ĵ�С
  // �Զ����deleter����control block���������shared_ptr�

  if (deriveType == 1)
  {
    pClassBase = make_shared<ClassDerived1>();
    pAnotherClassBase = make_shared<ClassDerived1>();
  }
  else
  {
    pClassBase = make_shared<ClassDerived2>();
    pAnotherClassBase = make_shared<ClassDerived2>();
  }

  // ��Ҫ���ʹ��ͬһ��ԭʼָ����Ϊ������ʼ��shared_ptr�����£�
  // auto rp = new ClassBase();
  // shared_ptr<ClassBase> sp1(rp, myDeleter);
  // shared_ptr<ClassBase> sp2(rp, myDeleter);
  // �����ᵼ��ͬһ��ԭʼָ�뱻����shared_ptr����������shared_ptr�Ⱥ��ͷű�ָ��
  // ��ԭʼָ��ʱ�����ԭʼָ��ᱻ�ͷ����Ρ�
  // һ��Ҫʹ��ԭʼָ��Ļ����鲻ʹ�ñ����洢��ֱ����Ϊ��������
  // shared_ptr<ClassBase> sp3(new ClassBase(), myDeleter);
  // Ȼ��ڶ���shared_ptr�õ�һ��shared_ptr��Ϊ������������
  // shared_ptr<ClassBase> sp4(sp3);
  // ע��thisҲ��ԭʼָ�롣һ��Ҫʹ��this��Ϊshared_ptr�Ĺ������ʱ��
  // ��this���ڵ���̳�enable_shared_from_this<>���Ա㰲ȫ��ʹ��this��

  // shared_ptr������תΪunique_ptr����ʹֻ��һ��shared_ptr

  // shared_ptr����unique_ptr������������Ϊģ�����

  // ע�⣬����������������shared_ptrָ��Է�����ʹû�����shared_ptrָ�����ǣ�
  // ��һ�Զ�����Զ���ᱻ�Զ����٣����յ���й©����Ϊ���������жԷ���shared_ptrָ�š�
  // ���Կ��ǰ�����һ����Ϊweak_ptr��

  return pClassBase;
}

void item19(void)
{
  cout << endl << "----- Item 19 -----" << endl;
  cout << ">> Create shared_ptr with default deleter" << endl;
  {
    shared_ptr<ClassBase> pClassBase = FactorySharedPtr::createInstDeleterDefault(2);
  }

  cout << ">> Create shared_ptr with myDeleter and myAnotherDeleter" << endl;
  {
    auto pClassBaseMyDeleter = FactorySharedPtr::createInstDeleterCustom(2);
  }
}
