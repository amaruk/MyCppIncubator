#pragma once
#include "ItemBase.h"
class Item42 :
  public ItemBase
{
public:
  Item42();
  ~Item42();

  void ItemEntry() override;
};

