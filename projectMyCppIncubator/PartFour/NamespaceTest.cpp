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
    void SameNameClass::dispInfo(void)
    {
        cout << "This is Bob's class" << endl;
    }
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

    NamespaceAlice::SameNameClass aliceClass = NamespaceAlice::SameNameClass();
    NamespaceBob::SameNameClass bobClass = NamespaceBob::SameNameClass();

    aliceClass.dispInfo();
    bobClass.dispInfo();
}
