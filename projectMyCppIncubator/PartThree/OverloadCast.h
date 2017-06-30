#pragma once

#include <iostream>

class OverloadCast
{

    friend std::ostream & operator<<(std::ostream &os, const OverloadCast &ins);
    friend std::istream & operator>>(std::istream &is, OverloadCast &ins);
    friend OverloadCast operator+(const OverloadCast &lhs, const OverloadCast &rhs);
    friend bool operator==(const OverloadCast &lhs, const OverloadCast &rhs);
    friend bool operator<(const OverloadCast &lhs, const OverloadCast &rhs);

public:
    OverloadCast(std::string initStr) : memStr(initStr) {};
    ~OverloadCast() {};

    /*
        重载的运算符是函数，其名字由关键字operator和其后要定义的运算符号组成，
        其参数与该运算符作用的运算对象数量一样多。

        对一个运算符函数来说，要么是类的成员，要么至少函授一个类类型的参数，
        为了防止内置类型的运算符被重载：int operator+(int, int);

        只能重载已有的运算符，不能创造运算符。

        可以重载的运算符：
            +       -       *       /       &       ^
            &       |       ~       !       ,       =
            <       >       <=      >=      ++      --
            <<      >>      ==      !=      &&      ||
            +=      -+      /=      %=      ^=      &=
            |=      *=      <<=     >>=     []      ()
            ->      ->*     new     new[]   delete  delete[]
        不可以重载的运算符：
            ::      .*      .       ?:
        不建议重载的运算符：
            逻辑与/或，逗号运算符重载后，运算对象求值顺序无法保留
            &&和||重载后无法保留短路求值属性，两个运算对象总是被求值
            逗号和取地址运算符对类类型对象有特殊含义，重载后导致用户无法适应
        必须是成员函数的重载：
            =       []      ()      ->
            复合赋值运算符（如+=）一般是成员，但非必须
            递增/递减/解引用运算符改变对象状态或与给定类型密切相关，通常是成员
            具有对称性的运算符可能转换任意一段的运算对象，如算术/相等性/关系/位运算符，通常是非成员函数

        调用的两种方式：
        data1 + data2
        operator+(data1, data2)

        如果是成员运算符函数，调用方式如下：
        data1 += data2
        data1.operator+=(data2)

        区别成员运算符函数和非成员运算符函数：
        string s = "world";
        string u - "hi" + s;    // 如果+被string重载为成员函数，则错误，相当于"hi".operator+(s)，而“hi“是const char *，内置类型没有成员
                                // 实际上，+被string重载为非成员函数，两个运算对象至少有一个是string类类型时，相当于operator+("hi",s)，两个实参都可转换为形参类型。
        string t = s + "!";     // 正确，同上
    */ 

    // 重载复合赋值运算符
    // 不一定要定义为类成员，但一般定义为类成员
    // 这样左侧运算符绑定到隐式的this
    // 返回左侧运算符对象的引用
    OverloadCast & operator+=(const OverloadCast &rhs);

    // 重载赋值运算符
    // 实现花括号的赋值
    OverloadCast & operator=(std::initializer_list<std::string> initVals);

    // 辅助函数
    void setMemStr(const std::string &newStr);

private:
    std::string memStr;
};

// 重载输出运算符<<
// 第一个形参为非常量（写入流会改变其状态）ostream对象引用（无法复制ostream对象），
// 第二个形参为想要打印的类类型的常量（一般不会改变打印对象的内容）引用（避免复制实参）
// 与其他输出运算符保持一致，返回ostream形参
// 必须是非成员函数，否则第一个形参必须是对应类的对象
std::ostream & operator<<(std::ostream &os, const OverloadCast &ins);

// 重载输入运算符>>
// 第一个形参为要读取的流的引用
// 第二个形参为要读入到的非常量对象的引用
// 返回给定流的引用
std::istream & operator>>(std::istream &is, OverloadCast &ins);

// 重载算术运算符
// 参数为常量的引用，因为不需要改变运算对象的状态
// 运算后得到新值，操作完后返回该局部变量的副本
OverloadCast operator+(const OverloadCast &lhs, const OverloadCast &rhs);

// 重载相等运算符
bool operator==(const OverloadCast &lhs, const OverloadCast &rhs);

// 重载关系运算符
bool operator<(const OverloadCast &lhs, const OverloadCast &rhs);

void testOverloadCast(void);

