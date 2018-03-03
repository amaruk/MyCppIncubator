#pragma once

#include "ItemBase.h"
#include "ClassHierarchy.h"
#include <memory>

class Item18 :
  public ItemBase
{
public:
  Item18();
  ~Item18();

  void ItemEntry() override;
};

class FactoryUniquePtr
{
public:
  // �ڶ��ϴ�������ʵ�������ػ���ָ��Ĺ���������ʹ��Ĭ��deleter
  static std::unique_ptr<ClassBase> createInstDeleterDefault(int deriveType);
  // ʹ���Զ���deleter
  static auto createInstDeleterCustom(int deriveType);
};

void item18(void);
