#include "stdafx.h"
#include "NamespaceTest.h"

using std::cout;
using std::endl;

NamespaceTest::NamespaceTest()
{
}


NamespaceTest::~NamespaceTest()
{
}

// 在namespace外部定义
void NamespaceAlice::SameNameClass::dispInfo(void)
{
    cout << "This is Alice's class" << endl;
}

// 在namespace内部定义
namespace NamespaceBob
{
    void NamespaceBob::NamespaceOld::SameNameClass::dispInfo(void)
    {
        cout << "This is old Bob's class" << endl;
    }

    // inline的namespace实现
    void SameNameClass::dispInfo(void)
    {
        cout << "This is current Bob's class" << endl;
    }
}

void NamespaceAlice::NamespaceCarol::SameNameClass::dispInfo(void)
{
    cout << "This is Alice's Carol's class" << endl;
}

void testNamespace(void)
{
    // 多个库将名字放在全局命名空间会引发命名空间污染 Namespace Pollution
    // 命名空间定义包括两：关键字namespace、命名空间的名字、花括号包围的声明和定义（尾部无需分号）
    // 每个命名空间是一个作用域
    // 能出现在全局作用域的声明就可以置于命名空间：类/变量（及其初始化）/函数（及其定义）/模板/其他命名空间
    // 不能出现在函数或类的内部
    // 命名空间定义可以不连续
    // 通常不把include放在命名空间内，会造成头文件里的内容定义为此命名空间内

    ::NamespaceTest globalClass = ::NamespaceTest(); // 全局命名空间Global Namespace隐式声明，没有名字
    NamespaceAlice::SameNameClass aliceClass = NamespaceAlice::SameNameClass();
    NamespaceBob::NamespaceOld::SameNameClass oldBobClass = NamespaceBob::NamespaceOld::SameNameClass();
    NamespaceBob::SameNameClass currentBobClass = NamespaceBob::SameNameClass();
    NamespaceAlice::NamespaceCarol::SameNameClass carolClass = NamespaceAlice::NamespaceCarol::SameNameClass();

    globalClass.dispInfo();
    aliceClass.dispInfo();
    oldBobClass.dispInfo();
    currentBobClass.dispInfo();
    carolClass.dispInfo();
}
