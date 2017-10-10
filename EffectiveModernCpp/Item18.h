#pragma once

#include <iostream>
#include <memory>
#include "ClassHierarchy.h"


class FactoryUniquePtr
{
public:
  // �ڶ��ϴ�������ʵ�������ػ���ָ��Ĺ���������ʹ��Ĭ��deleter
  static std::unique_ptr<ClassBase> createInstDeleterDefault(int deriveType);
  // ʹ���Զ���deleter
  static auto createInstDeleterCustom(int deriveType);
};

void item18(void);
