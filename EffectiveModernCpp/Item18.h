#pragma once

#include <iostream>
#include <memory>
#include "ClassHierarchy.h"


class FactoryUniquePtr
{
public:
  // 在堆上创建子类实例，返回基类指针的工厂函数，使用默认deleter
  static std::unique_ptr<ClassBase> createInstDeleterDefault(int deriveType);
  // 使用自定义deleter
  static auto createInstDeleterCustom(int deriveType);
};

void item18(void);
