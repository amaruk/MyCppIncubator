#include "stdafx.h"
#include "CppPrimer.h"
#include <iostream>
#include <string>
#include <vector>
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::begin;
using std::end;

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
	// range for��statement���ܸı����еĴ�С
	// ���declarationΪ��������statement�������������Ԫ�صĿ�����for(char c : str)
	cout << "Range for: ";
	for (char c : strRangeFor)
	{ cout << c; }
	cout << endl;
	// ���declarationΪ���ã���statement��ֱ�Ӳ�������Ԫ�ء�for(char &c:str)
	for (char &c : strRangeFor)
	{ c = toupper(c); }
	cout << "Range for toupper: " << strRangeFor << endl;
}

void CppPrimer::vectorTest(void)
{
	// ��ʾ����ļ��ϣ��������ж�������Ͷ���ͬ�����ò��Ƕ������Բ����ڰ������õ�vector��
	// vector��ģ�壬vector<T>�����͡�

	//vector<T> v1; //��vector��Ԫ������ΪT��Ĭ�ϳ�ʼ��
	vector<int> vInt_default;
	// vInt_direct�а���vInt_default����Ԫ�صĸ���
	vector<int> vInt_direct(vInt_default);
	// Ч��ͬ��
	vector<int> vInt_assign = vInt_default;
	// vInt_repeat������5���ظ���Ԫ�أ�ÿ��Ԫ�ض���123
	vector<int> vInt_repeat(5, 123);
	//vInt_repeatDefault������5���ظ���Ԫ�أ�ÿ��Ԫ��ֵΪĬ�ϳ�ʼ��ֵ
	vector<int> vInt_repeatDefault(5); 

	// ����c++11����
	// vInt_listDirect�����˳�ֵΪ1,2,3,...��Ԫ��
	vector<int> vInt_listDirect{ 1, 2, 3 };
	// Ч��ͬ��
	vector<int> vInt_listAssign = { 1, 2, 3 };

	// �����ӿ�
	vector<int> vIntA;
	vector<int> vIntB = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };

	// vector�в���Ԫ��ʱ�����棬���򷵻ؼ�
	cout << "Is vIntA empty: " << vIntA.empty() << endl;
	cout << "Is vIntB empty: " << vIntB.empty() << endl;

	// vector��Ԫ�ظ���
	cout << "vIntA size: " << vIntA.size() << endl;
	cout << "vIntB size: " << vIntB.size() << endl;

	// ��ĩβ���Ԫ��
	vIntA.push_back(2);
	// ���ص�n��λ���ϵ�����
	cout << "vIntA[0]: " << vIntA[0] << endl;
	// <, <= , >, >= ���ֵ���Ƚ�
	cout << "vIntA > vIntB: " << (vIntA > vIntB) << endl;
	// ���ҽ���Ԫ��������ͬ�Ҷ�Ӧλ��Ԫ�ض���ͬ
	cout << "v1 == v2: " << (vIntA == vIntB) << endl;
	// ��vIntB��Ԫ�ؿ����滻vIntA��Ԫ��
	vIntA = vIntB;
	cout << "v1 == v2: " << (vIntA == vIntB) << endl;
	// ���б���Ԫ���滻v1��Ԫ��
	vIntA = { 1, 2, 3, 4 };
	cout << "vIntA > vIntB: " << (vIntA > vIntB) << endl;

}

void CppPrimer::iteratorTest(void)
{
	// ���б�׼������������ʹ�õ�������string��������������ʹ�õ�������
	// ��ȡ��������������ָ���ȡ��ַ���е�����������ӵ�п��Է��ص������ĳ�Ա����begin��end��
	// begin()����ָ���һ��Ԫ�صĵ�������end()����������βԪ�ص���һ��λ�õĵ��������ǳ���ĩβ�Ĳ����ڵ�Ԫ�أ�
	// ������++����һ��Ԫ���ƶ�����һ��Ԫ��
	string strToBeIterator = "Hello, iterator!";
	cout << "Iterator: ";
	for (auto cur = strToBeIterator.begin(), end = strToBeIterator.end(); cur != end; ++cur)
	{
		cout << *cur;
	}
	cout << endl;
	// ע�⣬C++ʹ�� != ���ж�ĩβ������������<����Ϊ��Щ������û�ж���<�������
	// ������������Ϊiterator��const_iterator���磺
	vector<int>::iterator iteratorVar; //iteratorVar�ܶ�дvector<int>��Ԫ��
	vector<int>::const_iterator iteratorConstVar; //iteratorConstVarֻ�ܶ�ȡvector<int>��Ԫ��
	// ���vector����Ϊ�������磬const vector<int>������ֻ����const_iterator
	// begin��end���صĵ������������ն����Ƿ�������
	// cbegin��cend���صĵ���������Ԫ���Ƿ�����ֱ�ӷ���const_iterator��
	// ��*�������õ������õ���������ָ����ʱ����Ҫ�����������ʳ�Ա��������(*itr).empty()
	// ����->��������ͬʱ���ʳ�Ա��������itr->empty()
	// ʹ�õ�������ѭ�������range for��Ҳ���ܸı������Ĵ�С��
	// difference_type������������֮��ľ��룬Ϊ�з�������
}

void CppPrimer::arrayTest(void)
{
	// �����Ԫ��Ҳ�Ƕ������Բ�������������

	// ��ʼ��
	const unsigned sz = 3;
	int intAry_sizeAssign[sz] = { 0, 1, 2 }; // ��������Ԫ��0,1,2������
	int intAry_OnlyAssign[] = { 0, 1, 2 }; // ά����3������
	int intAry_sizePartAssign[5] = { 0, 1, 2 }; // �ȼ���intAry_sizePartAssign[]={0,1,2,0,0};
	string strAry[3] = { "hi", "bye" }; // �ȼ���strAry[] = {"hi","bye",""}
	char charArray[] = "C++"; //�ַ�����������ʼ�����Զ����\0�ַ�
	// ������һ�������ʼ����һ�����飬Ҳ����ֱ�ӿ�������

	// ���ӵ���������
	int intAry[10];
	int *intPtrAry[10]; // 10������ָ�������
	//int &refs[10]; // ���������Ŷ������ò��Ƕ���
	int(*intAryPtr)[10] = &intAry; // intAryPtr��ָ�룬ָ��һ������10�����͵�����
	int(&intAryRef)[10] = intAry; // intAryRef�����ã�����һ������10�����͵�����
	int *(&refIntPtrAry)[10] = intPtrAry; // arry����������ã�����һ������10��ָ�������

	// ������ָ��
	string strNum[] = { "one", "two", "three" };
	string *pStrAryEle = &strNum[0]; //ָ���һ��Ԫ��
	string *pStrAryName = strNum; //�ȼ���pStrAryEle

	// C++11Ϊ��������begin��end������Ϊ���鲢�����࣬���������������������Ա����ʽ����,
	// �����Ժ�����ʽ���֣�ʹ�����£�
	char charAry[10] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j' };
	char *charAryBeg = begin(charAry);
	char *charAryEnd = end(charAry);
	cout << "Using begin()&end() to loop array: ";
	for (char *c = charAryBeg; c != charAryEnd; c++)
	{ cout << *c; }
	cout << endl;

	// ָ������Ľ��Ϊ�����ŵ�ptrdiff_t����
	// ������±�Ϊ�����±����㣬����ʹ�ø�������������׼�����͵��±��Ǳ�׼��ʵ�ֵģ��±����Ϊ�޷������͡�

	// �������ͱ���
	using int_array = int[4]; //C++11
	typedef int int_array[4];
	// ����ʹ��int_array*��ʾָ��4��Ԫ�ص�int�����ָ��

	// ��range for�����ά����
	int intAryAry[2][3] = { {1, 2, 3}, { 4, 5, 6} };
#if 0
	for (auto row : intAryAry)
		for (auto col : row) // ERROR row��������ת��int*�����ܶ�int*����range for
			cout << col << endl;
#endif

	for (auto &row : intAryAry)
		for (auto col : row) // row��4��Ԫ�����������
			cout << col << endl;

	for (auto &row : intAryAry)
		for (auto col : row)
			col = 123; // col�������ã�����û���޸ĵ�ia��Ԫ��

	for (auto &row : intAryAry)
		for (auto &col : row)
			col = 123; // col�����ã�ֱ���޸ĵ�ia��Ԫ��

}


