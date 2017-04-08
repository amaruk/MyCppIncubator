#pragma once
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

};

