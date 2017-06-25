#pragma once

#include <string>

class ClassFeatures
{
    /*
        五种特殊的成员函数（拷贝控制操作 copy control）：
        - copy constructor拷贝构造函数：当用同类型的另一个对象初始化本对象时的行为
        - move constructor移动构造函数：同上
        - copy-assignment operator拷贝赋值运算符：将一个对象赋予给同类型的另一个对象时的行为
        - move-assignment operator移动赋值运算符：同上
        - destructor析构函数：对象销毁时的行为

        如果类没有定义拷贝操作成员，编译器自动定义缺省操作。
    */
public:
    // 默认构造函数
    ClassFeatures();

    // 拷贝构造函数： 第一个参数是自身类型的引用，且任何额外参数都有默认值
    // 即使定义了其他构造函数，编译器也会补上缺失的合成拷贝构造函数(synthesized copy constructor)，
    // 一般情况下，合成拷贝构造函数逐个拷贝对象的成员，类类型的成员调用其拷贝构造函数来拷贝，
    // 数组的元素逐个拷贝。
    // 参数是引用。因为非引用的形参在实参传递时需要调用拷贝构造函数，
    // 如果拷贝构造函数的形参为非引用，就会无限循环调用自己

    ClassFeatures(const ClassFeatures &cfIns); // 参数可以非const，但一般都是。通常不是explicit。
    // 相当于 ClassFeatures(const ClassFeatures &cfIns) : mem1(cfIns.mem1), mem2(cfIns.mem2){}

    ~ClassFeatures();

    void displayMem(void);
    void setMem(const std::string memStrVal);

private:
    std::string memStr;
};

void testClassFeatures(void);
