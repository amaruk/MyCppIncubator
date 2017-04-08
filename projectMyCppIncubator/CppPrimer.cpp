#include "stdafx.h"
#include "CppPrimer.h"
#include <iostream>
#include <string>
#include <vector>
using std::cout;
using std::endl;
using std::string;
using std::vector;

CppPrimer::CppPrimer()
{
}


CppPrimer::~CppPrimer()
{
}

void CppPrimer::displayArithTypes(void)
{
	cout << "==== Display all arithmetic types ====" << endl;
	cout << "bool: " << arithType_bool << endl;
	cout << "char: " << arithType_char << endl;
	cout << "wchar_t: " << arithType_wchar << endl;
	cout << "char16_t: " << arithType_char16 << endl;
	cout << "char32_t: " << arithType_char32 << endl;
	cout << "short: " << arithType_short << endl;
	cout << "int: " << arithType_int << endl;
	cout << "long: " << arithType_long << endl;
	cout << "long long: " << arithType_longlong << endl;
	cout << "float: " << arithType_float << endl;
	cout << "double: " << arithType_double << endl;
	cout << "long double: " << arithType_longdouble << endl;
}

// 函数体外的变量未初始化会被初始化为0
int intOutsideUninited;
void CppPrimer::varInitTest(void)
{
	cout << "==== Variable initialization test ====" << endl;

	// 普通赋值不检查初值是否超范围
	int intAssign = 2147483648;
	cout << "int intAssign = 2147483648: " << intAssign << endl;

	// 列表赋值检查初值是否超范围，超范围编译ERROR
	int intAssignList = { 2147483647 };
	cout << "int intAssignList = { 2147483647 }: " << intAssignList << endl;

	// 普通赋值不检查初值是否超范围
	int intDirect(2147483648);
	cout << "int intDirect(2147483648): " << intDirect << endl;

	// 列表赋值检查初值是否超范围，超范围编译ERROR
	int intDirectList{ 2147483647 };
	cout << "int intDirectList = { 2147483647 }: " << intDirectList << endl;

	// 函数体内的内置类型变量未初始化 不会被初始化
	int intInsideUninited;
	// 如下语句导致编译告警：warning C4700: uninitialized local variable 'intUinited' used
	// 运行可能崩溃
	//cout << "int intInsideUninited: " << intInsideUninited << endl;

	// 函数体外的内置类型变量为初始化
	cout << "int intOutsideUninited: " << intOutsideUninited << endl;

	// 重名时调用全局变量
	int intOutsideUninited = 123;
	// 打印局部变量
	cout << "intOutsideUninited: " << intOutsideUninited << endl;
	// 打印全局变量
	cout << "::intOutsideUninited:  " << ::intOutsideUninited << endl;

}

void CppPrimer::ptrRefTest(void)
{
	int intI{ 123 };
	int intJ{ 456 };
	// nullPtr为空指针字面量；NULL定义与cstdlib，使用时不需std::
	int *ptrInt = nullptr; // 普通指针
	int *&refPtrInt = ptrInt; // 普通指针的引用

	cout << "==== Point to I ====" << endl;

	ptrInt = &intI;
	cout << "*ptrInt: " << *ptrInt << endl;
	cout << "*refPtrInt: " << *refPtrInt << endl;
	
	cout << "==== Change to J ====" << endl;

	refPtrInt = &intJ; // 相当于改变ptrInt
	cout << "*ptrInt: " << *ptrInt << endl;
	cout << "*refPtrInt: " << *refPtrInt << endl;

	cout << "==== CONST REF PTR =====" << endl;

	int iVal = 135;

	// 普通常量
	// 顶层（top-level）const
	// 必须初始化，可用字面量、变量、返回值初始化
	const int iConst = 123;

	// 普通引用
	// 引用必须初始化，初始化之后无法解除绑定
	// 只能绑定到对象（可以定义指针的引用），不能绑定到字面量或表达式结果
	// 赋值的对象类型必须和引用类型一致
	int &refVal = iVal;

	// 对常量的引用（reference to const）
	// 以为自己引用了常量，所以不能改变引用的常量的值
	// 底层（low-level） const
	// 引用的对象不一定要const，可以绑定到对象、字面量、表达式
	// 不论引用的对象是不是const类型，都不能通过对常量的引用操作来改变被引用的对象的值（如：refCInt = 123; 错误）
	const int &refCInt = iConst;

	// 普通指针
	// 不能指向const常量，不能指向引用（因为不是对象）
	int *pInt = &iVal;

	// 指向常量的指针（pointer to const）
	// 以为自己指向了常量，所以不能改变指向的常量的值
	// 底层（low-level） const
	// 指向的对象不一定要const
	// 不论指向的对象是不是const类型，都不能通过指向常量的指针操作来改变被指向的对象的值（如：*ptrCInt = 123; 错误）
	const int *ptrCInt = &iConst;

	// 常量指针（const pointer）
	// 自己是常量，所以不能改变自己的值
	// 顶层（top-level） const
	// 初始化规则同常量，不能改变指针常量的值
	int * const cPtrInt = &iVal;
	
	// constexpr: 常量表达式是指值不会改变，且在编译过程就能得到计算结果的表达式。
	// C++11规定，变量声明为constexpr类型后，由编译器验证变量的值是否为常量表达式，此变量必须用常量表达式初始化。

	cout << "==== Alias ====" << endl;
	typedef int aliasInt; //aliasInt是int的同义词
	typedef aliasInt neoInt, *neoIntP; //neoInt是int的同义词，neoIntP是int *的同义词

	aliasInt aliasIntVal = 123;
	neoInt neoIntVal = 123;
	neoIntP neoIntPtr = &neoIntVal;

	using usingInt = int; // C++11规定别名声明alias declaration。usingInt是double的同义词
	usingInt usingIntVal = 123;

	// 注意如下陷阱
	char charVar = 'a';
	typedef char *pstring;
	const pstring cstr = &charVar; //cstr是“指向char的常量指针”
	const pstring *ps; //ps是一个指针，他的对象是“指向char的常量指针”
	// 错误的理解为直接把typedef替换进去：const char *cstr = 0;
	//    这种理解中，数据类型为char，*是声明符的一部分，整个定义表示“指向char常量的指针”
	// 正确的理解为：pstring是数据类型的别名，表示char*数据类型
	//    整个定义表示“指向char的常量指针”，即char * const cstr = 0;
	//    可以类比const int i表示int类型的常量，const pstring i表示pstring类型的常量。
	// 用下面的语句实测类型
	//cstr = nullptr; // 错误，左值为const不可改变
	*cstr = 'b'; // 正确
	cout << "charVar: " << charVar << endl;

	// auto类型: C++11引入auto，声明的变量类型由编译器根据表达式的结果确定。
	// decltype类型 C++11引入decltype选择并返回操作数的数据类型
	
}

void CppPrimer::stringTest(void)
{
	cout << "==== String Initialization ====" << endl;

	// 默认初始化，空字符串
	string initStr_default;
	cout << "string initStr_default: " << initStr_default << endl;

	// copy initialization。initStr_assign是initStr_default的副本
	string initStr_copy = initStr_default;
	cout << "string initStr_copy = initStr_default: " << initStr_copy << endl;

	// direct initialization。创建副本
	string initStr_direct(initStr_default);
	cout << "string initStr_direct(initStr_default): " << initStr_default << endl;

	// 字面量的副本
	string initStr_literalAssign = "hiya";
	cout << "string initStr_literalAssign = \"hiya\": " << initStr_literalAssign << endl;

	// 效果同上
	string initStr_literalDirect("hiya");
	cout << "string initStr_literalDirect(\"hiya\"): " << initStr_literalDirect << endl;
	
	// "cccccccccc\0"
	string initStr_times(10, 'c'); 
	cout << "string initStr_times(10, 'c'): " << initStr_times << endl;

	cout << "==== Range for ====" << endl;
	string strRangeFor("This is a string to be ranged for...");
	// range for的statement不能改变序列的大小
	// 如果declaration为变量，则statement里操作的是序列元素的拷贝。for(char c : str)
	cout << "Range for: ";
	for (char c : strRangeFor)
	{ cout << c; }
	cout << endl;
	// 如果declaration为引用，则statement里直接操作序列元素。for(char &c:str)
	for (char &c : strRangeFor)
	{ c = toupper(c); }
	cout << "Range for toupper: " << strRangeFor << endl;
}

void CppPrimer::vectorTest(void)
{
	// 表示对象的集合，其中所有对象的类型都相同。引用不是对象，所以不存在包含引用的vector。
	// vector是模板，vector<T>是类型。

	//vector<T> v1; //空vector，元素类型为T，默认初始化
	vector<int> vInt_default;
	// vInt_direct中包含vInt_default所有元素的副本
	vector<int> vInt_direct(vInt_default);
	// 效果同上
	vector<int> vInt_assign = vInt_default;
	// vInt_repeat包含了5个重复的元素，每个元素都是123
	vector<int> vInt_repeat(5, 123);
	//vInt_repeatDefault包含了5个重复的元素，每个元素值为默认初始化值
	vector<int> vInt_repeatDefault(5); 

	// 以下c++11引入
	// vInt_listDirect包含了初值为1,2,3,...的元素
	vector<int> vInt_listDirect{ 1, 2, 3 };
	// 效果同上
	vector<int> vInt_listAssign = { 1, 2, 3 };

	// 向量接口
	vector<int> vIntA;
	vector<int> vIntB = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };

	// vector中不含元素时返回真，否则返回假
	cout << "Is vIntA empty: " << vIntA.empty() << endl;
	cout << "Is vIntB empty: " << vIntB.empty() << endl;

	// vector的元素个数
	cout << "vIntA size: " << vIntA.size() << endl;
	cout << "vIntB size: " << vIntB.size() << endl;

	// 向末尾添加元素
	vIntA.push_back(2);
	// 返回第n个位置上的引用
	cout << "vIntA[0]: " << vIntA[0] << endl;
	// <, <= , >, >= 以字典序比较
	cout << "vIntA > vIntB: " << (vIntA > vIntB) << endl;
	// 当且仅当元素数量相同且对应位置元素都相同
	cout << "v1 == v2: " << (vIntA == vIntB) << endl;
	// 用vIntB中元素拷贝替换vIntA中元素
	vIntA = vIntB;
	cout << "v1 == v2: " << (vIntA == vIntB) << endl;
	// 用列表中元素替换v1中元素
	vIntA = { 1, 2, 3, 4 };
	cout << "vIntA > vIntB: " << (vIntA > vIntB) << endl;

}

void CppPrimer::iteratorTest(void)
{
	// 所有标准库容器都可以使用迭代器。string不是容器，但可使用迭代器。
	// 获取迭代器不是类似指针的取地址，有迭代器的类型拥有可以返回迭代器的成员，如begin和end。
	// begin()返回指向第一个元素的迭代器，end()返回容器里尾元素的下一个位置的迭代器（是超过末尾的不存在的元素）
	// 可以用++来从一个元素移动到下一个元素
	string strToBeIterator = "Hello, iterator!";
	cout << "Iterator: ";
	for (auto cur = strToBeIterator.begin(), end = strToBeIterator.end(); cur != end; ++cur)
	{
		cout << *cur;
	}
	cout << endl;
	// 注意，C++使用 != 来判断末尾条件而不是用<，因为有些迭代器没有定义<运算符。
	// 迭代器的类型为iterator或const_iterator，如：
	vector<int>::iterator iteratorVar; //iteratorVar能读写vector<int>的元素
	vector<int>::const_iterator iteratorConstVar; //iteratorConstVar只能读取vector<int>的元素
	// 如果vector对象为常量（如，const vector<int>），则只能用const_iterator
	// begin和end返回的迭代器类型依照对象是否常量决定
	// cbegin和cend返回的迭代器无视元素是否常量，直接返回const_iterator。
	// 用*来解引用迭代器得到迭代器所指对象时，需要加括号来访问成员函数，如(*itr).empty()
	// 可用->来解引用同时访问成员函数，如itr->empty()
	// 使用迭代器的循环里，类似range for，也不能改变容器的大小。
	// difference_type是两个迭代器之间的距离，为有符号整数
}


