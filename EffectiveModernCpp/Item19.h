#pragma once

#include <iostream>
#include <memory>
#include "ClassHierarchy.h"


class FactorySharedPtr
{
public:
  // �ڶ��ϴ�������ʵ�������ػ���ָ��Ĺ���������ʹ��Ĭ��deleter
  static std::shared_ptr<ClassBase> createInstDeleterDefault(int deriveType);
  // ʹ���Զ���deleter
  static auto FactorySharedPtr::createInstDeleterCustom(int deriveType);
};

void item19(void);
