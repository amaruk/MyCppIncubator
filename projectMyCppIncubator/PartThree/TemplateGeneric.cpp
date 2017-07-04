#include "stdafx.h"
#include "TemplateGeneric.h"
#include <string>

using std::cout;
using std::endl;
using std::vector;
using std::string;

void testTemplateGeneric(void)
{
    /*
        模板是泛型编程的基础。
        模板：创建类或函数的公式，如泛型类型vector，泛型函数find
    */
    cout << "Function template test." << endl;
    // 编译器推断模板实参为int，之后实例化instantiate一个特定版本的函数实例instantiation
    cout << "ftCompare(1,2): " << ftCompare(1, 2) << endl;
    // 编译器推断模板实参为double，实例化另一个特定版本的函数dsfa
    cout << "ftCompare(321.123, 123.321): " << ftCompare(321.123, 123.321) << endl;
    // 编译器推断模板为compare(const char(&pCharAry1)[6], const char(&pCharAry2)[7]) 数组含'\0'
    cout << "ftCompare(\"Hello\", \"World!\"): " << ftCompare("Hello", "World!") << endl;
    // inline和constexpr的模板函数
    cout << "ftInlineConstexprDouble(123): " << ftInlineConstexprDouble(123) << endl;
    cout << endl;

    cout << "Class template test." << endl;
    // 用显式模板实参explicit template argument来绑定模板参数，用于编译器实例化
    ClassTemplate<int> ctIntIns = { 1,2,3,4,5 };
    ++ctIntIns;
    --ctIntIns;
    for (size_t i = 0; i != ctIntIns.size(); i++)
    { cout << "ctIntIns[" << i << "]: " << ctIntIns[i] << endl; }
    cout << endl;

    // 使用类模板别名
    templateClassAlias<string> ctStrIns = { "ONE", "TWO" };
    for (size_t i = 0; i != ctStrIns.size(); i++)
    { cout << "ctStrIns[" << i << "]: " << ctStrIns[i] << endl; }
    cout << endl;

    // 测试类模板的静态成员
    cout << "Before Changing ctIntIns.staticStr" << endl
        << "ctIntIns.staticStr: [" << ctIntIns.staticStr
        << "] ctStrIns.staticStr: [" << ctStrIns.staticStr << "]" << endl;
    ctIntIns.staticStr = string("MODIFY");
    cout << "After Changing ctIntIns.staticStr" << endl
        << "ctIntIns.staticStr: [" << ctIntIns.staticStr
        << "] ctStrIns.staticStr: [" << ctStrIns.staticStr << "]" << endl;
    cout << endl;
}
