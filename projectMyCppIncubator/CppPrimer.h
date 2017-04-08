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
private:
	////////算数类型变量
	// 最小尺寸规范未定义
	bool arithType_bool = false;
	// 8-bit. 有三种类型：char/unsigned char/signed char，
	// char不一定是signed，由编译器决定
	char arithType_char = u8'A'; 
	// 16-bit
	wchar_t arithType_wchar = L'B';
	// 16-bit Unicode
	char16_t arithType_char16 = u'测';
	// 32-bit Unicode
	char32_t arithType_char32 = U'试';
	// 16-bit
	short arithType_short = 32767;
	// 16-bit TODO: 确认16-bit
	unsigned int arithType_int = 65535u;
	// 32-bit
	long arithType_long = 2147483647L;
	// 64-bit
	long long arithType_longlong = 9223372036854775807LL;
	// 6位有效数字
	float arithType_float = 0.123456F;
	// 10位有效数字
	double arithType_double = 0.0123456789;
	// 10位有效数字
	long double arithType_longdouble = 0.0987654321L;

};

