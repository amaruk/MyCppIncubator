#pragma once
#include <iostream>

class NamespaceTest
{
public:
    NamespaceTest();
    ~NamespaceTest();
};

namespace NamespaceAlice
{
    class SameNameClass
    {
    public:
        void dispInfo(void);
    };
}

namespace NamespaceBob
{
    class SameNameClass
    {
    public:
        void dispInfo(void);
    };
}

// TODO: 模板特例化 Page 698

void testNamespace(void);
