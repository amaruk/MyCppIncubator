#pragma once

#include <iostream>

// 基类
class BaseClassForCast
{
public:
    BaseClassForCast() = default;
    ~BaseClassForCast() = default;

    virtual void dispClassVirtual(void) { std::cout << "Virtual: Base Class" << std::endl; }
    void dispClass(void) { std::cout << "Non-Virtual: Base Class" << std::endl; }
};

// 派生类
class DerivedClassForCast : public BaseClassForCast
{
public:
    DerivedClassForCast() = default;
    ~DerivedClassForCast() = default;

    virtual void dispClassVirtual(void) override { std::cout << "Virtual: Derived Class" << std::endl; }
    void dispClass(void) { std::cout << "Non-Virtual: Derived Class" << std::endl; }
};

// C++11引入限定作用域的枚举类型scoped enumeration

void specialTechTest(void);

