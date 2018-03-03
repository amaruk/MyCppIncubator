#include "stdafx.h"
#include "Item18.h"

using std::cout;
using std::endl;
using std::unique_ptr;
using std::make_unique;

std::unique_ptr<ClassBase> FactoryUniquePtr::createInstDeleterDefault(int deriveType)
{
  if (deriveType == 1)
  {
    return make_unique<ClassDerived1>();
  }
  else
  {
    return make_unique<ClassDerived2>();
  }
}

void myDeleterFunc(ClassBase *pClassBase)
{
  cout << "myDeleterFunc()" << endl;
  delete pClassBase;
}

auto FactoryUniquePtr::createInstDeleterCustom(int deriveType)
{

  // ʹ�ú�����ʹ��lambda���ʽЧ����ͬ������ʹ��lambda���ʽ
#if 0
  // ʹ�ú�����lambda�����ڴ�ռ�
  unique_ptr<ClassBase, void (*)(ClassBase *pClassBase)> // ʹ�ú���ʱ��unique_ptr����˲����⣬���ж���ĺ���ָ��
    pClassBase(nullptr, myDeleterFunc);

  if (deriveType == 1)
  {
    pClassBase.reset(new ClassDerived1());
  }

  return pClassBase;
#else
  // ����C++14��function return type deduction����lambda���ʽ���빤������
  auto myDeleter = [](ClassBase *pClassBase)
  {
    cout << "myDeleter()" << endl;
    delete pClassBase; // ����������������������delete����ָ���ʱ��������������
  };

  unique_ptr<ClassBase, decltype(myDeleter)> // �ڶ�������Ϊ�Զ���deleter������
    pClassBase(nullptr, myDeleter);

  if (deriveType == 1)
  {
    pClassBase.reset(new ClassDerived1());
  }
  else
  {
    pClassBase.reset(new ClassDerived2());
  }

  return pClassBase;
#endif
}


Item18::Item18() :
  ItemBase("18")
{
}


Item18::~Item18()
{
}


void Item18::ItemEntry()
{
  cout << ">> Create unique_ptr with default deleter" << endl;
  {
    unique_ptr<ClassBase> pClassBase = FactoryUniquePtr::createInstDeleterDefault(1);
    // ֱ���÷���ֵ��shared_ptr��ֵ
    // std::shared_ptr<ClassBase> psClassBase = Factory::createInstDeleterDefault(1);
    // ����move��shared_ptr��ֵ
    // std::shared_ptr<ClassBase> psClassBase = std::move(pClassBase);
  }

  cout << ">> Create unique_ptr with myDeleter" << endl;
  {
    auto pClassBaseMyDeleter = FactoryUniquePtr::createInstDeleterCustom(1);
  }
}
