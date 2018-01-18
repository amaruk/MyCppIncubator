#include "stdafx.h"
#include "Item20.h"


Item20::Item20() :
  ItemBase("20")
{
}


Item20::~Item20()
{
}

class Item20BaseClass
{
public:
  Item20BaseClass() { cout << "Base CTOR" << endl; }
  virtual void display() const { cout << "Base Display" << endl; }
};

class Item20DerivedClass : public Item20BaseClass
{
public:
  Item20DerivedClass() { cout << "Derived CTOR" << endl; }
  void display() const override { cout << "Derived Display" << endl; }
};

namespace
{
  void DisplayByValue(Item20BaseClass baseIns)
  { baseIns.display(); }

  void DisplayByRef(const Item20BaseClass& baseRef)
  { baseRef.display(); }
}

void Item20::ItemEntry()
{
  //// Item 20: Prefer pass-by-reference-to-const to pass-by-value
  // C++Ĭ��ʹ�ÿ������캯������pass-by-value��
  // ��������Ϊʵ�ʲ����Ŀ���������ֵҲ�Ƿ��ض���Ŀ���

  // ͨ��pass by reference-to-const��reference�����¶���ͨ�����������Ӷ����ٿ���
  // const��֤��Ȼ�Ǵ������ã�����������ı������ֵ��
  // ������ͬʱ���ܱ���slicing problem����Ϊ����ʵ������ָ��ʵ�ֵġ�

  // �ʺϴ�ֵ�����ͣ�built-in types and STL iterator and function object types
  // ���ഫ����

  cout << "---Create instances" << endl;
  Item20DerivedClass derivedIns{};
  cout << "---Display copy-by-value" << endl;
  DisplayByValue(derivedIns); // ������ֵ�ĺ����������������ʵ���������ಿ�ֱ�slicing��ֻ�ܵ��õ������display
  cout << "---Display copy-by-reference" << endl;
  DisplayByRef(derivedIns); // ���ò����ĺ���������ָ�룬�ܵ��õ��������display



}