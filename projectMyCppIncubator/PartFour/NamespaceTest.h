#pragma once
#include <iostream>

class NamespaceTest
{
public:
    NamespaceTest();
    ~NamespaceTest();
    void dispInfo(void) { std::cout << "This is Global's class." << std::endl; }
};

namespace NamespaceAlice
{
    class SameNameClass
    {
    public:
        void dispInfo(void);
    };

    // 嵌套namespace
    namespace NamespaceCarol
    {
        class SameNameClass
        {
        public:
            void dispInfo(void);
        };
    }
}

namespace NamespaceBob
{
    namespace NamespaceOld
    {
        class SameNameClass
        {
        public:
            void dispInfo(void);
        };
    }

    // C++11 内联命名空间
    // 第一次出现的命名空间加了inline，其他同名命名空间就可以不加inline
    // 使用时可以忽略namespace层级中的NamespaceCurrent
    // 使用场景：
    // NamespaceOld是上一版本的实现，NamespaceCurrent是当前版本的实现，每次更新实现时，
    // 把NamespaceCurrent去掉inline并改名，新的实现仍然放在inline的NamespaceCurrent里，
    // 外部调用的代码就不用改。
    inline namespace NamespaceCurrent
    {
        class SameNameClass
        {
        public:
            void dispInfo(void);
        };
    }
}

// TODO: 模板特例化 Page 698

void testNamespace(void);
