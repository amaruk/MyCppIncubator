#pragma once

#include <memory>
#include "ClassHierarchy.h"

// Incomplete type: declared但没有defined的类型

// 优点
// 改变类私有成员变量不需要重新编译用到这个类的其他类 -> 缩短编译时间，解决FragileBinaryInterfaceProblem
// 头文件不需要包含私有部分的实现类的头文件 -> 加速编译

void item22(void);

