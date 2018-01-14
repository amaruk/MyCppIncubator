#include "stdafx.h"
#include "Item09.h"


Item09::Item09() :
  ItemBase("09")
{
}


Item09::~Item09()
{
}

class Item9BaseClass
{
public:
  Item9BaseClass() { cout << "Item9BaseClass Constructor" << endl; }
  ~Item9BaseClass() { cout << "Item9BaseClass Destructor" << endl; }
};

class Item9DerivedClass : public Item9BaseClass
{
public:
  Item9DerivedClass() { cout << "Item9DerivedClass Constructor" << endl; }
  ~Item9DerivedClass() { cout << "Item9DerivedClass Destructor" << endl; }
};

void Item09::ItemEntry()
{
  //// Item 9: Never call virtual functions during construction or destruction
  // ����������ʵ��ʱ����ִ�л��๹�캯�����ڴ��ڼ�ʵ������Ϊ�������ͣ���ֻ��ʹ�û���ĳ�Ա
  // ִ������๹�캯����ִ�������๹�캯������ʱʵ������Ϊ���������͡�
  // ������ʱ����ִ���������������������ִ�л������������

  // ������ʵ��Ϊ���������ڼ䣬��������麯��������õĻ��ǻ�����麯������������Դ��麯����ʵ�֡�
  // Ϊ�˱���������⣬��Ҫ�ڹ��캯������������������麯����
  // ����б�Ҫʵ�����Ƴ����Ļ���������Ĺ��캯�������������๹�캯�����ɡ�

  // ע���ӡ��˳��
  cout << "Creating a base class instance:" << endl;
  {
    Item9BaseClass baseInstance{};
  }

  cout << endl << "Creating a derived class instance:" << endl;
  {
    Item9DerivedClass derivedInstance{};
  }
}
