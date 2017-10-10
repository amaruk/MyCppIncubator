#pragma once

#include <iostream>
#include <memory>
#include "ClassHierarchy.h"


class FactorySharedPtr
{
public:
  // 在堆上创建子类实例，返回基类指针的工厂函数，使用默认deleter
  static std::shared_ptr<ClassBase> createInstDeleterDefault(int deriveType);
  // 使用自定义deleter
  static auto FactorySharedPtr::createInstDeleterCustom(int deriveType);
};

void item19(void);
