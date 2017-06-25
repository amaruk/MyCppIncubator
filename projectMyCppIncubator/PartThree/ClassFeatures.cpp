#include "stdafx.h"
#include "ClassFeatures.h"
#include <iostream>

using std::cout;
using std::endl;
using std::string;

ClassFeatures::ClassFeatures()
{
    cout << "/!\\ default constructor" << endl;
    this->memStr = string("Default");
}


ClassFeatures::ClassFeatures(const ClassFeatures & cfIns)
{
    cout << "/!\\ copy constructor" << endl;
    this->memStr = cfIns.memStr;
}

ClassFeatures::~ClassFeatures()
{
    cout << "/!\\ destructor" << endl;
}

ClassFeatures & ClassFeatures::operator=(const ClassFeatures & rgtIns)
{
    cout << "/!\\ copy-assignment operator" << endl;
    this->memStr = rgtIns.memStr;
    return *this; // 返回此对象的引用
}

ClassFeatures::ClassFeatures(ClassFeatures && cfIns) noexcept
{
    cout << "/!\\ move constructor" << endl;
    this->memStr = cfIns.memStr;
    cfIns.memStr = nullptr;
}

ClassFeatures & ClassFeatures::operator=(ClassFeatures && rgtIns) noexcept
{
    cout << "/!\\ move-assignment operator" << endl;
    // 要处理自己给自己赋值
    if (this != &rgtIns) // 检查this和rgtIns的地址是否相同
    {
        this->memStr = rgtIns.memStr;
        rgtIns.memStr = nullptr;
    }
    return *this; // 返回此对象的引用
}

void ClassFeatures::displayMem(void)
{
    cout << "Instance members: "
        << "memStr[" << this->memStr << "] "
        << endl;
}

void ClassFeatures::setMem(const string memStrVal)
{
    this->memStr = memStrVal;
}

void testClassFeatures(void)
{
    // 直接初始化
    ClassFeatures cfInsDefault = ClassFeatures();
    cout << "1. ";
    cfInsDefault.displayMem();
    cfInsDefault.setMem("setMem");
    cout << "2. ";
    cfInsDefault.displayMem();

    // 虽然调用了拷贝构造函数，但是使用普通的函数匹配，是直接初始化
    ClassFeatures cfInsCallCopyConst = ClassFeatures(cfInsDefault);
    cout << "3. ";
    cfInsCallCopyConst.displayMem();
    cfInsCallCopyConst.setMem("Changed");
    /*
        拷贝初始化发生在如下情况：
        - 用=直接赋值
        - 将对象作为实参传给非引用类型的形参
        - 返回非引用类型的函数返回对象
        - 用花括号列表初始化数组的元素或聚合类的成员
    */

    // 拷贝初始化
    ClassFeatures cfInsCopyConstruct = cfInsCallCopyConst;
    cout << "4. ";
    cfInsCopyConstruct.displayMem();

    // 拷贝赋值运算符
    cfInsCopyConstruct = cfInsDefault;
    cout << "5. ";
    cfInsCopyConstruct.displayMem();

    /*
        调用析构函数的情况：
        - 变量离开作用域时被销毁
        - 当一个对象被销毁时，其成员被销毁
        - 容器被销毁时，其元素被销毁
        - 动态分配的对象，当指向其的指针应用delete运算符时被销毁
        - 创建临时对象的完整表达式结束时，临时对象被销毁
    */

    /*
        对象作为左值，用其值（内容）
        对象作为右值，用其身份（内存中的位置）
        例：
            赋值运算符左侧为非常量的左值，其结果也是左值
            取地址运算符作用于左值，返回的指针是右值
            解引用，下标的求值结果是左值

        左值引用 &：不能绑定到要求转换的表达式/字面常量/返回右值的表达式
        右值引用 &&：与左值引用完全相反，只能绑定到右值
    */
    int intVal = 123;
    int &lvalRef1 = intVal;             // 正确，左值引用
    //int &&rvalRef1 = intVal;          // 错误，右值引用不能绑定到左值
    //int &lvalRef2 = intVal * 5;       // 错误，intVal*5是右值，不能绑定到左值引用
    const int &lvalRef3 = intVal * 5;   // 正确，可以将const的左值引用绑定到右值上
    int &&rvalRef2 = intVal * 5;        // 正确，右值引用
    // 左值有持久的状态，右值是字面量或者表达式求值过程中创建的临时对象
    // 右值引用只能绑定到临时对象（该对象将要被销毁，没有其他用户）
    //int &&rvalRef3 = rvalRef2;          // 错误，变量是左值，不能绑定到右值引用s
    int &&rvalRef4 = std::move(rvalRef2); // 正确，用move把左值当右值处理。用std::move而不是using避免潜在的名字冲突
    //调用move之后，可以对此对象赋值或销毁，但不能再使用其值
    

}
