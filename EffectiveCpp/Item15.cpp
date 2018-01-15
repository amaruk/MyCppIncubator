#include "stdafx.h"
#include "Item15.h"


Item15::Item15() :
  ItemBase("15")
{
}


Item15::~Item15()
{
}

class Item15InnerClass
{
public:
  Item15InnerClass(string name) : m_name(name) { cout << "Item15Inner CTOR" << endl; }
  ~Item15InnerClass() { cout << "Item15Inner DTOR" << endl; }
  string m_name;
};

class Item15OuterClass
{
public:
  Item15OuterClass() { cout << "Item15OuterClass CTOR" << endl; }
  ~Item15OuterClass() { cout << "Item15OuterClass DTOR" << endl; }

  // �ṩ������ʽ����ת��
  operator Item15InnerClass() const { return m_inner; }
  operator int() const { return m_int; }

private:
  Item15InnerClass m_inner{"InnerName"};
  int m_int{123};
};

void UseInnerInst(Item15InnerClass innerIns)
{
  cout << innerIns.m_name << endl;
}

void UseIntPtr(int pInt)
{
  cout << pInt << endl;
}


void Item15::ItemEntry()
{
  //// Item 15: Provide access to raw resources in resource-managing classes.
  // ��get������auto_ptr��shared_ptr����ʽת����ȡԭʼָ��
  // ֱ�ӵ������ص�->��*������������ԭʼָ��ĳ�Ա
  // ���ṩ��ʽת��
  Item15OuterClass outerInst{};
  cout << "---After create outer" << endl;
  UseInnerInst(outerInst);
  cout << "---After Implicit convert to inner" << endl;
  UseIntPtr(outerInst);
  cout << "---After Implicit convert to int" << endl;
}