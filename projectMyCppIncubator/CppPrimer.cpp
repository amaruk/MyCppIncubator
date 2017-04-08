#include "stdafx.h"
#include "CppPrimer.h"
#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

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

// ��������ı���δ��ʼ���ᱻ��ʼ��Ϊ0
int intOutsideUninited;
void CppPrimer::varInitTest(void)
{
	cout << "==== Variable initialization test ====" << endl;

	// ��ͨ��ֵ������ֵ�Ƿ񳬷�Χ
	int intAssign = 2147483648;
	cout << "int intAssign = 2147483648: " << intAssign << endl;

	// �б�ֵ����ֵ�Ƿ񳬷�Χ������Χ����ERROR
	int intAssignList = { 2147483647 };
	cout << "int intAssignList = { 2147483647 }: " << intAssignList << endl;

	// ��ͨ��ֵ������ֵ�Ƿ񳬷�Χ
	int intDirect(2147483648);
	cout << "int intDirect(2147483648): " << intDirect << endl;

	// �б�ֵ����ֵ�Ƿ񳬷�Χ������Χ����ERROR
	int intDirectList{ 2147483647 };
	cout << "int intDirectList = { 2147483647 }: " << intDirectList << endl;

	// �������ڵ��������ͱ���δ��ʼ�� ���ᱻ��ʼ��
	int intInsideUninited;
	// ������䵼�±���澯��warning C4700: uninitialized local variable 'intUinited' used
	// ���п��ܱ���
	//cout << "int intInsideUninited: " << intInsideUninited << endl;

	// ����������������ͱ���Ϊ��ʼ��
	cout << "int intOutsideUninited: " << intOutsideUninited << endl;

	// ����ʱ����ȫ�ֱ���
	int intOutsideUninited = 123;
	// ��ӡ�ֲ�����
	cout << "intOutsideUninited: " << intOutsideUninited << endl;
	// ��ӡȫ�ֱ���
	cout << "::intOutsideUninited:  " << ::intOutsideUninited << endl;

}

void CppPrimer::ptrRefTest(void)
{
	int intI{ 123 };
	int intJ{ 456 };
	// nullPtrΪ��ָ����������NULL������cstdlib��ʹ��ʱ����std::
	int *ptrInt = nullptr; // ��ָͨ��
	int *&refPtrInt = ptrInt; // ��ָͨ�������

	cout << "==== Point to I ====" << endl;

	ptrInt = &intI;
	cout << "*ptrInt: " << *ptrInt << endl;
	cout << "*refPtrInt: " << *refPtrInt << endl;
	
	cout << "==== Change to J ====" << endl;

	refPtrInt = &intJ; // �൱�ڸı�ptrInt
	cout << "*ptrInt: " << *ptrInt << endl;
	cout << "*refPtrInt: " << *refPtrInt << endl;

	cout << "==== CONST REF PTR =====" << endl;

	int iVal = 135;

	// ��ͨ����
	// ���㣨top-level��const
	// �����ʼ��������������������������ֵ��ʼ��
	const int iConst = 123;

	// ��ͨ����
	// ���ñ����ʼ������ʼ��֮���޷������
	// ֻ�ܰ󶨵����󣨿��Զ���ָ������ã������ܰ󶨵�����������ʽ���
	// ��ֵ�Ķ������ͱ������������һ��
	int &refVal = iVal;

	// �Գ��������ã�reference to const��
	// ��Ϊ�Լ������˳��������Բ��ܸı����õĳ�����ֵ
	// �ײ㣨low-level�� const
	// ���õĶ���һ��Ҫconst�����԰󶨵����������������ʽ
	// �������õĶ����ǲ���const���ͣ�������ͨ���Գ��������ò������ı䱻���õĶ����ֵ���磺refCInt = 123; ����
	const int &refCInt = iConst;

	// ��ָͨ��
	// ����ָ��const����������ָ�����ã���Ϊ���Ƕ���
	int *pInt = &iVal;

	// ָ������ָ�루pointer to const��
	// ��Ϊ�Լ�ָ���˳��������Բ��ܸı�ָ��ĳ�����ֵ
	// �ײ㣨low-level�� const
	// ָ��Ķ���һ��Ҫconst
	// ����ָ��Ķ����ǲ���const���ͣ�������ͨ��ָ������ָ��������ı䱻ָ��Ķ����ֵ���磺*ptrCInt = 123; ����
	const int *ptrCInt = &iConst;

	// ����ָ�루const pointer��
	// �Լ��ǳ��������Բ��ܸı��Լ���ֵ
	// ���㣨top-level�� const
	// ��ʼ������ͬ���������ܸı�ָ�볣����ֵ
	int * const cPtrInt = &iVal;
	
	// constexpr: �������ʽ��ֵָ����ı䣬���ڱ�����̾��ܵõ��������ı��ʽ��
	// C++11�涨����������Ϊconstexpr���ͺ��ɱ�������֤������ֵ�Ƿ�Ϊ�������ʽ���˱��������ó������ʽ��ʼ����

	cout << "==== Alias ====" << endl;
	typedef int aliasInt; //aliasInt��int��ͬ���
	typedef aliasInt neoInt, *neoIntP; //neoInt��int��ͬ��ʣ�neoIntP��int *��ͬ���

	aliasInt aliasIntVal = 123;
	neoInt neoIntVal = 123;
	neoIntP neoIntPtr = &neoIntVal;

	using usingInt = int; // C++11�涨��������alias declaration��usingInt��double��ͬ���
	usingInt usingIntVal = 123;

	// ע����������
	char charVar = 'a';
	typedef char *pstring;
	const pstring cstr = &charVar; //cstr�ǡ�ָ��char�ĳ���ָ�롱
	const pstring *ps; //ps��һ��ָ�룬���Ķ����ǡ�ָ��char�ĳ���ָ�롱
	// ��������Ϊֱ�Ӱ�typedef�滻��ȥ��const char *cstr = 0;
	//    ��������У���������Ϊchar��*����������һ���֣����������ʾ��ָ��char������ָ�롱
	// ��ȷ�����Ϊ��pstring���������͵ı�������ʾchar*��������
	//    ���������ʾ��ָ��char�ĳ���ָ�롱����char * const cstr = 0;
	//    �������const int i��ʾint���͵ĳ�����const pstring i��ʾpstring���͵ĳ�����
	// ����������ʵ������
	//cstr = nullptr; // ������ֵΪconst���ɸı�
	*cstr = 'b'; // ��ȷ
	cout << "charVar: " << charVar << endl;

	// auto����: C++11����auto�������ı��������ɱ��������ݱ��ʽ�Ľ��ȷ����
	// decltype���� C++11����decltypeѡ�񲢷��ز���������������
	
}

void CppPrimer::stringTest(void)
{
	cout << "==== String Initialization ====" << endl;

	// Ĭ�ϳ�ʼ�������ַ���
	string initStr_default;
	cout << "string initStr_default: " << initStr_default << endl;

	// copy initialization��initStr_assign��initStr_default�ĸ���
	string initStr_copy = initStr_default;
	cout << "string initStr_copy = initStr_default: " << initStr_copy << endl;

	// direct initialization����������
	string initStr_direct(initStr_default);
	cout << "string initStr_direct(initStr_default): " << initStr_default << endl;

	// �������ĸ���
	string initStr_literalAssign = "hiya";
	cout << "string initStr_literalAssign = \"hiya\": " << initStr_literalAssign << endl;

	// Ч��ͬ��
	string initStr_literalDirect("hiya");
	cout << "string initStr_literalDirect(\"hiya\"): " << initStr_literalDirect << endl;
	
	// "cccccccccc\0"
	string initStr_times(10, 'c'); 
	cout << "string initStr_times(10, 'c'): " << initStr_times << endl;

	cout << "==== Range for ====" << endl;
	string strRangeFor("This is a string to be ranged for...");
	// ���declarationΪ��������statement�������������Ԫ�صĿ�����for(char c : str)
	// ���declarationΪ���ã���statement��ֱ�Ӳ�������Ԫ�ء�for(char &c:str)
	// range for��statement���ܸı����еĴ�С
	cout << "Range for: ";
	for (char c : strRangeFor)
	{ cout << c; }
	cout << endl;
	// �൱���õ�����ѭ����
	cout << "Iterator: ";
	for (auto cur = strRangeFor.begin(), end = strRangeFor.end(); cur != end; ++cur)
	{ cout << *cur; }
	cout << endl;
	// ���õ�range for�����޸�ֵ
	for (char &c : strRangeFor)
	{ c = toupper(c); }
	cout << "Range for toupper: " << strRangeFor << endl;
}


