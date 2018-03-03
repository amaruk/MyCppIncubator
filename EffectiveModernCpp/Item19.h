#pragma once

#include "ItemBase.h"
#include "ClassHierarchy.h"
#include <memory>

class Item19 :
  public ItemBase
{
public:
  Item19();
  ~Item19();

  void ItemEntry() override;
};

class FactorySharedPtr
{
public:
  // �ڶ��ϴ�������ʵ�������ػ���ָ��Ĺ���������ʹ��Ĭ��deleter
  static std::shared_ptr<ClassBase> createInstDeleterDefault(int deriveType);
  // ʹ���Զ���deleter
  static auto FactorySharedPtr::createInstDeleterCustom(int deriveType);
};

