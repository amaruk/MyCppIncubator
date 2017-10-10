
#include "stdafx.h"
#include <iostream>
#include "Item18.h"

using std::cout;
using std::endl;
using std::unique_ptr;


std::unique_ptr<ClassBase> Factory::createInstDeleterDefault(int deriveType)
{
  if (deriveType == 1)
  {
    return std::make_unique<ClassDerived1>();
  }
}

void myDeleterFunc(ClassBase *pClassBase)
{
  cout << "myDeleterFunc()" << endl;
  delete pClassBase;
}

auto Factory::createInstDeleterCustom(int deriveType)
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

  return pClassBase;
#endif
}

void item18(void)
{
  cout << "----- Create unique_ptr with default deleter" << endl;
  {
    unique_ptr<ClassBase> pClassBase = Factory::createInstDeleterDefault(1);
    // ֱ���÷���ֵ��shared_ptr��ֵ
    // std::shared_ptr<ClassBase> psClassBase = Factory::createInstDeleterDefault(1);
    // ����move��shared_ptr��ֵ
    // std::shared_ptr<ClassBase> psClassBase = std::move(pClassBase);
  }

  cout << "----- Create unique_ptr with myDeleter" << endl;
  {
    auto pClassBaseMyDeleter = Factory::createInstDeleterCustom(1);
  }
}
