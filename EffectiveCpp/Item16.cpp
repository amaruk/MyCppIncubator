#include "stdafx.h"
#include "Item16.h"


Item16::Item16() :
  ItemBase("16")
{
}


Item16::~Item16()
{
}

void Item16::ItemEntry()
{
  //// Item 16: Use the same form in corresponding uses of new and delete.
  // ע��delete�����ʱ��Ҫ��[]��newʱ��[]��deleteʱҲ��[]
  std::string *stringPtr1 = new std::string;
  std::string *stringPtr2 = new std::string[100];
  delete stringPtr1;      // delete an object
  delete[] stringPtr2;    // delete an array of objects

  // �ر�Ҫע����typedef���͵�ʱ�򣬲鿴ԭ��������ȷ��Ҫ��Ҫdeleteʱ��[]
  typedef std::string AddressLines[4];
  std::string *pal = new AddressLines;
  delete[] pal;

}
