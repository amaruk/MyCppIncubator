#include "stdafx.h"
#include "Item33.h"
#include <memory>
#include <functional>

using std::make_unique;
using std::bind;

Item33::Item33() :
  ItemBase("33")
{
}


Item33::~Item33()
{
}


void Item33::ItemEntry()
{
  // C++14��generic lambda֧��ʹ��auto������lambda
  // TODO �Ķ�֮ǰ���½���������item
}
