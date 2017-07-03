﻿#pragma once
#include <iostream>

// 基类
class OperatingSystem
{
    // 基类把希望派生类各自实现的函数声明为虚函数virtual function
    // 构造函数之外的非静态函数可以为虚函数
    // virtual只能出现在类内部
    // 基类中的虚函数，在派生类中隐式地是虚函数
    // final和override出现在形参列表（包括const或引用修饰符）以及尾置返回类型之后
    // 含有纯虚函数的类是抽象基类abstract base class，定义接口，由派生类实现接口。
    // 不能创建抽象基类的对象
public: // 派生类可以访问，其他用户可以访问
    OperatingSystem() = default;
    OperatingSystem(std::string name, int ver, bool open) : osName(name), osVer(ver), osIsOpen(open) {};
    virtual ~OperatingSystem() = default; // 继承关系中的根节点类一般定义虚析构函数

    // 虚函数
    virtual void dispOsName(void) const;
    virtual void dispOsVer(void) const;
    virtual void dispOsOpenSource(void) const final;
    // 纯虚函数 pure virtual
    // 无需定义，由派生类实现
    // 可以在类外部为纯虚函数提供定义
    virtual void dispOsMotto(void) = 0; // =0表示纯虚函数


    static void osRootInfo(void);
private: // 派生类不可访问，其他用户不可访问
protected: // 派生类可以访问，其他用户不可访问
    std::string osName;
    int osVer;
    bool osIsOpen;
};

// 派生类
// 通过类派生列表class derivation list指明从哪些基类继承而来。
// 每个基类前面可以有访问说明符：public/protected/private
// 派生类在其他文件中的类声明不需要包含派生列表
class OSWindows final : public OperatingSystem // c++11：final的类不能被继承
{
public:
    OSWindows() = default;
    // 派生类不能直接初始化继承来的成员，要调用基类的构造函数
    // 不显式初始化的话，基类的成员会默认初始化
    OSWindows(std::string name, int ver, bool open, bool embedded) : OperatingSystem(name, ver, open), isEmbedded(embedded) {};
    ~OSWindows() = default;

    // 派生类必须对所有重新定义的虚函数进行声明，virtual关键字可选，因为一旦被声明为虚函数，在所有派生类中都是虚函数
    // 如果派生类中虚函数同名的函数有不同的形参列表，则此函数不覆盖虚函数
    // c++11: override关键字表示派生类显式注明用此成员函数改写基类的虚函数，编译器会检查形参列表
    // 覆盖虚函数时，形参类型和返回类型必须与被覆盖的虚函数一致，除非返回类型是类本身的指针或引用
    virtual void dispOsName(void) const override; // 覆盖虚函数
    //virtual void dispOsVer(void) const override; // 不覆盖的虚函数继承基类
    //virtual void dispOsOpenSource(void) const override; // 不能覆盖final的虚函数
    virtual void dispOsMotto(void) override; // 覆盖纯虚函数，如不覆盖，派生类也为抽象类

private:
    static const std::string companyName; // 静态成员
    bool isEmbedded;
};



void testOOP(void);