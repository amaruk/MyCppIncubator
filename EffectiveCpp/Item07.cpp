#include "stdafx.h"
#include "Item07.h"

Item07::Item07() :
  ItemBase("07")
{
}

Item07::~Item07()
{
}

class AbstractBaseClass
{
public:
  AbstractBaseClass() { cout << "Constructor: AbstractBaseClass" << endl; }
  virtual ~AbstractBaseClass() = 0;
};

// ���붨�崿��������������������Ӵ���
// ��Ϊ��������ʱ����û������������
AbstractBaseClass::~AbstractBaseClass()
{
  cout << "Destructor: AbstractBaseClass" << endl;
}

class DerivedClass : public AbstractBaseClass
{
public:
  DerivedClass() { cout << "Constructor: DerivedClass" << endl; }
  ~DerivedClass() { cout << "Destructor: DerivedClass" << endl; }
};

void Item07::ItemEntry()
{
  //// Item 7: Declare destructors virtual in polymorphic base classes
  // ��̬����£�����ָ��ָ������ʵ��������������������������virtual�ģ�������ʱֻ����û��������
  // ������ඨ��Ĳ����޷���������
  // �Ǽ̳�����²�Ҫ����virtual������������Ϊ������virtual table pointer���������С���Ҵ�����Ҫ���⴦�������ֲ��������������
  // �������¹���������virtual������
  // declare a virtual destructor in a class if and only if that class contains at least one virtual function.
  // ��Ҫ�̳��Ҷ�̬û��virtual��Ա���࣬����ʱ�ᵼ��δ������Ϊ
  // �д��鹹�캯�������ǳ����࣬����ʵ������������ĳ���ඨ��Ϊ�����࣬�����Աû�д��麯������ʹ������Ϊ���顣��ע��Ҫ����Ϊ����Ĵ��鹹�캯����

  AbstractBaseClass* pBase = new DerivedClass();
  delete pBase;
}
