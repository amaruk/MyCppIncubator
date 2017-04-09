#pragma once

#include <string>
#include <vector>
#include <initializer_list>

typedef int intAry3[3];
using intAry3Using = int[3];

class CppPrimer
{
public:
	CppPrimer();
	~CppPrimer();
	// 显示私有成员中算数类型变量的值
	void displayArithTypes(void);
	// 测试各种初始化的方式
	void varInitTest(void);
	// 指针/引用/const相关
	void ptrRefTest(void);
	// 字符串
	void stringTest(void);
	// 向量
	void vectorTest(void);
	// 迭代器
	void iteratorTest(void);
	// 数组
	void arrayTest(void);
    // 异常
    void exceptionTest(void);
    // 函数相关
    void functionTest(void);
    // 重载
    // 同一作用域内的几个函数名字相同但形参列表不同（形参数量或类型）
    // 编译器根据实参类型判断调用的是哪个函数。编译期决定！
    // 不允许只有返回值不同的多个函数存在
    // main不能重载
    // 形参有顶层const和没有顶层const是一样的，重载时要注意；底层const能实现重载
    void overloadTest(int intArg);
    //void overloadTest(const int intArg); // 顶层const，重复声明
    void overloadTest(int *intPtrArg);
    //void overloadTest(int * const intPtrArg); // 顶层const，重复声明
    void overloadTest(const int* intPtrArg); // 底层const，const指针，重载
    void overloadTest(int &intRefArg); // 普通引用
    void overloadTest(const int &intRefArg); // 底层const，const引用，重载
    // const_cast用于重载
    const std::string &shorterString(const std::string &s1, const std::string &s2);
    std::string &shorterString(std::string &s1, std::string &s2);
    // 默认实参
    void defaultParValTest(int intVal = 1, char charVal = '2', double doubleVal = 3.0);
    // 内联函数
    inline void inlineTest(void);
    constexpr int constexprFuncTest(int x) { return 123 * x; }

private:
	////////算数类型变量
	// 最小尺寸规范未定义
	bool arithType_bool = false;
	// 最小尺寸8-bit. 有三种类型：char/unsigned char/signed char，
	// char不一定是signed，由编译器决定
	char arithType_char = u8'A'; 
	// 最小尺寸16-bit
	wchar_t arithType_wchar = L'B';
	// 最小尺寸16-bit Unicode
	char16_t arithType_char16 = u'测';
	// 最小尺寸32-bit Unicode
	char32_t arithType_char32 = U'试';
	// 最小尺寸16-bit
	short arithType_short = 32767;
	// 最小尺寸16-bit, VS下32-bit
	unsigned int arithType_int = 65535u;
	// 最小尺寸32-bit
	long arithType_long = 2147483647L;
	// 最小尺寸64-bit
	long long arithType_longlong = 9223372036854775807LL;
	// 6位有效数字
	float arithType_float = 0.123456F;
	// 10位有效数字
	double arithType_double = 0.0123456789;
	// 10位有效数字
	long double arithType_longdouble = 0.0987654321L;
	// 指针
	short *arithType_ptr = nullptr;
    // 数组
    intAry3 intAry3Var = { 1, 2, 3 };

    // 打印数组
    void CppPrimer::printIntAry(int intAry[], int size);
    // 抛出异常用
    void exceptionThrower(void);
    // 可变数量形参
    void initializerListTest(std::initializer_list<std::string> args, std::string extVal);
    // 列表返回值
    std::vector<std::string> listReturnTest(void);
    // 返回数组指针
    intAry3* funcReturnIntAry3(void);
    intAry3Using* funcReturnIntAry3Using(void);
    int(*funcReturnIntAry3Plain(void))[3];
    auto funcReturnIntAry3Tail(void) -> int(*)[3];
    decltype(intAry3Var) *funcReturnIntAry3Decltype(void);
};

