#include "stdafx.h"
#include "Item07.h"

Item07::Item07() :
  ItemBase("07")
{
}

Item07::~Item07()
{
}

class Item7AbstractBaseClass
{
public:
  Item7AbstractBaseClass() { cout << "Constructor: Item7AbstractBaseClass" << endl; }
  virtual ~Item7AbstractBaseClass() = 0;
};

// ���붨�崿��������������������Ӵ���
// ��Ϊ��������ʱ����û������������
Item7AbstractBaseClass::~Item7AbstractBaseClass()
{
  cout << "Destructor: Item7AbstractBaseClass" << endl;
}

class Item7DerivedClass : public Item7AbstractBaseClass
{
public:
  Item7DerivedClass() { cout << "Constructor: Item7DerivedClass" << endl; }
  ~Item7DerivedClass() { cout << "Destructor: Item7DerivedClass" << endl; }
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

  Item7AbstractBaseClass* pBase = new Item7DerivedClass();
  delete pBase;
}
