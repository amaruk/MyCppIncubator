#pragma once

#include <iostream>
#include <memory>

class ClassBase
{
public:
  /*
      ���������������ڶ�̬��ʱ�������ָ�뱻����ʱ�ܵ������������
      ���Դ������£����virtual����ֻ�ܵ��õ����������
        ClassBase *pClassBase = new ClassDerived1();
        delete pClassBase;
  */
  virtual ~ClassBase()
  {
    std::cout << "~ClassBase()" << std::endl;
  }
};

class ClassDerived1 : public ClassBase
{
public:
  virtual ~ClassDerived1()override
  {
    std::cout << "~ClassDerived1()" << std::endl;
  }
};

class ClassDerived2 : public ClassBase
{
public:
  virtual ~ClassDerived2() override
  {
    std::cout << "~ClassDerived2()" << std::endl;
  }
};

class Factory
{
public:
  // �ڶ��ϴ�������ʵ�������ػ���ָ��Ĺ���������ʹ��Ĭ��deleter
  static std::unique_ptr<ClassBase> createInstDeleterDefault(int deriveType);
  // �Զ���deleter
  static auto Factory::createInstDeleterCustom(int deriveType);
};

void item18(void);
