#include "stdafx.h"
#include "CppPrimer.h"
#include "CppPrimerFriend.h"
#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include <initializer_list>
#include <cassert>
using std::cout;
using std::endl;
using std::cerr;
using std::string;
using std::vector;
using std::begin;
using std::end;
using std::runtime_error;
using std::initializer_list;

/*
******************** ��������ȼ� ********************
�����	�����	        ����	                �÷�
*****************************************************
��	::	            ȫ��������	        ::name
��	::	            ��������	            class:name
��	::	            �����ռ�������	    namespace::name
*****************************************************
��	.	            ��Աѡ��	            object.member
��	->	            ��Աѡ��	            pointer->member
��	[]	            �±�	                expr[expr]
��	()	            ��������	            name(expr_list)
��	()	            ���͹���	            type(expr_list)
*****************************************************
��	++	            ���õ�������	        lvalue++
��	--	            ���õݼ�����	        lvalue--
��	typeid	        ����ID	            typeid(type)
��	typeid	        ����ʱ����ID	        typeid(expr)
��	Explicit cast	����ת��	            cast_name<type>(expr)
*****************************************************
��	++	            ǰ�õ�������	        ++lvalue
��	--	            ǰ�õݼ�����	        --lvalue
��	~	            λ��	            expr
��	!	            �߼���	            !expr
��		            һԪ����	            -expr
��	+	            һԪ����	            +expr
��	*	            ������	            *expr
��	&	            ȡ��ַ	            &lvalue
��	()	            ����ת��	            (type)expr
��	sizeof	        ����Ĵ�С	        sizeof expr
��	sizeof	        ���͵Ĵ�С	        sizeof(type)
��	sizeof��	        �������Ĵ�С	        sizeof��(name)
��	new	            ��������	            new type
��	new[]	        ��������	            new type[size]
��	delete	        �ͷŶ���	            delete expr
��	delete[]	    �ͷ�����	            delete[] expr
��	noexcept	    �ܷ��׳��쳣	        noexcept(expr)
*****************************************************
��	->*	            ָ���Աѡ���ָ��	ptr->*ptr_to_member
��	.*	            ָ���Աѡ���ָ��	obj.*ptr_to_member
*****************************************************
��	*	            �˷�	                expr * expr
��	/	            ����	                expr / expr
��	%	            ȡģ�����ࣩ	        expr % expr
*****************************************************
��	+	            �ӷ�              	expr + expr
��		            ����	                expr - expr
*****************************************************
��	<<	            ������λ	            expr << expr
��	>>	            ������λ	            expr >> expr
*****************************************************
��	<	            С��	                expr < expr
��	<=	            С�ڵ���	            expr <= expr
��	>	            ����	                expr > expr
��	>=	            ���ڵ���	            expr >= expr
*****************************************************
��	==	            ���	                expr == expr
��	!=	            �����	            expr != expr
*****************************************************
��	&	            λ��                expr & expr
*****************************************************
��	^	            λ���	            expr ^ expr
*****************************************************
��	|	            λ��	                expr | expr
*****************************************************
��	&&	            �߼���	            expr && expr
*****************************************************
��	||	            �߼���	            expr || expr
*****************************************************
��	?:	            ����                expr ? expr : expr
*****************************************************
��	=	            ��ֵ	                lvalue = rvalue
��	"*=, /=, %="	���ϸ�ֵ	            lvalue += rvalue
��	"+=, -="
��	"<<=, >>="
��	"&=, |=, ^="
*****************************************************
��	throw	        �׳��쳣	            throw expr
*****************************************************
��	","	            ����                "expr, expr"
*****************************************************

*/


// ���캯���ĺ�������������ͬ��û�з�������
// ���캯�����ܱ�����Ϊconst���������һ��const����ʱ��
// Ҫ�����캯����ɳ�ʼ�����̣����캯�����������дֵ��������ŵõ��������ԡ�
// ����ʽ�������캯��ʱ���ɱ��������ɵ���ʽĬ�Ϲ��캯���Գ�Ա���г�ʼ��
// ��Ĭ�ϳ�ʼ�����ö������Աʱ�ĳ�ֵ��ʼ������һ��������һ�����캯����
// �Ͳ�����Ĭ�Ϲ��캯���ˡ�

CppPrimer::CppPrimer(CppPrimerStr initStr)
{
    cout << "Constructor: " << initStr << endl;
}

CppPrimer::~CppPrimer()
{
}

void CppPrimer::printIntAry(int intAry[], int size)
{
    for (int i = 0; i != size; i++)
        cout << intAry[i] << " ";
    cout << endl;
}

void CppPrimer::displayArithTypes(void)
{
    // �����Ա�����ڲ��б��������Ա���������ⲿ����ͬ��
    // ֱ��ʹ�ñ�������ָ��Ա�����ڲ��ı���
    // Ҫ�������Ա����������this->varName��className.varName
    // Ҫ�������ⲿ����������::varNmae
	cout << "==== Display all arithmetic types ====" << endl;
	cout << "bool[" << (sizeof arithType_bool) << " byte]: " << arithType_bool << endl;
	cout << "char[" << (sizeof(arithType_char)) << " byte]: " << arithType_char << endl;
	cout << "wchar_t[" << (sizeof(wchar_t)) << " byte]: " << arithType_wchar << endl;
	cout << "char16_t[" << (sizeof(char16_t)) << " byte]: " << arithType_char16 << endl;
	cout << "char32_t[" << (sizeof(char32_t)) << " byte]: " << arithType_char32 << endl;
	cout << "short[" << (sizeof arithType_short) << " byte]: " << arithType_short << endl;
	cout << "int[" << (sizeof arithType_int) << " byte]: " << arithType_int << endl;
	cout << "long[" << (sizeof arithType_long) << " byte]: " << arithType_long << endl;
	cout << "long long[" << (sizeof arithType_longlong) << " byte]: " << arithType_longlong << endl;
	cout << "float[" << (sizeof arithType_float) << " byte]: " << arithType_float << endl;
	cout << "double[" << (sizeof arithType_double) << " byte]: " << arithType_double << endl;
	cout << "long double[" << (sizeof arithType_longdouble) << " byte]: " << arithType_longdouble << endl;
	cout << "pointer[" << (sizeof arithType_ptr) << " byte]: " << arithType_ptr << endl;

	//// sizeof����
	//  ��char������Ϊchar�ı��ʽִ��sizeof�����Ϊ1
	//  ����������ִ��sizeof�õ������ö�����ռ�ռ��С
	//  ��ָ��ִ��sizeof�õ�ָ�뱾����ռ�ռ��С
	//  �Խ�����ָ��ִ��sizeof�õ�ָ��ָ��Ķ�����ռ�ռ��С��ָ�벻����Ч
	//  ������ִ��sizeof�õ�����������ռ�ռ��С������constexpr size_t sz = sizeof(ia) / sizeof(*ia)���������Ԫ�ظ���
	//  ��string�����vector����ִ��sizeofֻ���ع̶����ֵĴ�С��������������е�Ԫ��ռ�ö��ٿռ䡣

	//// ������ǿ������ת��
	// cast name<type>(expression);
	//     type��Ŀ������
	//     expression��Ҫת����ֵ
	//     case-nameΪ��
	//       static_cast�������ײ�const������ȷ���������ת�������intת��char������д�����ʱ��֪�����Ҳ����⾫�ȵ���ʧ
	//       dynamic_cast֧������ʱ����ʶ��
	//       const_castֻ�ܸı�ײ�const��ȥ��const���ʡ����ں������ء�
	//       reinterpret_castΪ��������λģʽ�ṩ�ϵͲ���ϵ����½��ͣ������intָ��ת����charָ��
	// ��ʽ��ǿ������ת��
	//    type(expr);
	//    (type)expr;

    // static_cast: doubleתint
    double dblVar = 123.456;
    int intVar = static_cast<int>(dblVar);
    cout << "double: " << dblVar << " int: " << intVar << endl;
    // static_cast: voidָ��תdoubleָ��
    void *ptrVoid = &dblVar;
    double *ptrDouble = static_cast<double *>(ptrVoid);
    cout << "*ptrDouble: " << (*ptrDouble) << endl;

    // dynamic_cast: TODO

    // const_cast: ȥ���ײ�const�����Ǻ������ص��÷�һ��Ԥʾ���������
    const int cIntVal = 123;
    const int *ptrConstInt = &cIntVal;
    int *ptrInt = const_cast<int *>(ptrConstInt); // ��ȷ��ȥ���˵ײ�const����ͨ��ָ��дֵ��δ������Ϊ
    //*ptrInt = 456; // ��һ������������ܲ�����Ч
    //int ptrIntImpossible = const_cast<int>(cIntVal); // �����޷�ȥ������const
    // ���ں�������

    // reinterpret_cast: intָ��תshortָ���ʹ��
    int intValTarget = 0x12345678;
    int *ptrIntTarget = &intValTarget;
    short *ptrCharTarget = reinterpret_cast<short *>(ptrIntTarget);
    cout << "*ptrIntTarget" << *ptrIntTarget << endl;
    cout << "*ptrCharTarget" << *ptrCharTarget << endl;
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

	//// ��ͨ����
	// ���㣨top-level��const
	// �����ʼ��������������������������ֵ��ʼ��
	const int iConst = 123;

	//// ��ͨ����
	// ���ñ����ʼ������ʼ��֮���޷������
	// ֻ�ܰ󶨵����󣨿��Զ���ָ������ã������ܰ󶨵�����������ʽ���
	// ��ֵ�Ķ������ͱ������������һ��
	int &refVal = iVal;

	//// �Գ��������ã�reference to const��
	// ��Ϊ�Լ������˳��������Բ��ܸı����õĳ�����ֵ
	// �ײ㣨low-level�� const
	// ���õĶ���һ��Ҫconst�����԰󶨵����������������ʽ
	// �������õĶ����ǲ���const���ͣ�������ͨ���Գ��������ò������ı䱻���õĶ����ֵ���磺refCInt = 123; ����
	const int &refCInt = iConst;

	//// ��ָͨ��
	// ����ָ��const����������ָ�����ã���Ϊ���Ƕ���
	int *pInt = &iVal;

	//// ָ������ָ�루pointer to const��
	// ��Ϊ�Լ�ָ���˳��������Բ��ܸı�ָ��ĳ�����ֵ
	// �ײ㣨low-level�� const
	// ָ��Ķ���һ��Ҫconst
	// ����ָ��Ķ����ǲ���const���ͣ�������ͨ��ָ������ָ��������ı䱻ָ��Ķ����ֵ���磺*ptrCInt = 123; ����
	const int *ptrCInt = &iConst;

	//// ����ָ�루const pointer��
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

	//// ע����������
	char charVar = 'a';
	typedef char *pstring;
	const pstring cstr = &charVar; // cstr�ǡ�ָ��char�ĳ���ָ�롱
	const pstring *cstrptr; // cstrptr��һ��ָ�룬���Ķ����ǡ�ָ��char�ĳ���ָ�롱
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

// �ں����Ķ��崦ָ��inline
inline void CppPrimer::exceptionThrower(void)
{
    throw runtime_error("Incubator's exception!");
}

void CppPrimer::exceptionThrower(int intVal)
{
    throw runtime_error("Incubator's overload exception!");
}

void CppPrimer::exceptionTest(void)
{
    // throw���ʽ����throw��ʾ�������޷����������
    // try���飺��try��ʼ��һ������catch����
    // �쳣�ࣺ������throw���ʽ����ص�catch�Ӿ�֮�䴫���쳣�ľ�����Ϣ
    // ���һֱû���ҵ��ʵ����͵�catch�������ת��terminate��׼�⺯������
    
    static bool exceptFlag = false;
	try {
        exceptFlag = !exceptFlag;
        if (exceptFlag)
        { exceptionThrower(); }
        else
        { exceptionThrower(1); }
	}
	catch (runtime_error e) {
		cout << "Exception caught: " << e.what() << endl;
	}

    //// ��׼�쳣
    //  exceptionͷ�ļ���������ͨ�õ��쳣��exception��ֻ�����쳣���������ṩ�κζ�����Ϣ
    //  stdexceptͷ�ļ����������쳣�ࣺ
    //      exception�����������
    //      runtime_error��ֻ��������ʱ���ܼ���������
    //      range_error������ʱ�������ɵĽ���������������ֵ��Χ
    //      overflow_error������ʱ���󣬼�������
    //      underflow_error������ʱ���󣬼�������
    //      logic_error�������߼�����
    //      domain_error���߼����󣬲�����Ӧ�Ľ��ֵ������
    //      invalid_argument���߼�������Ч����
    //      length_error���߼�������ͼ����һ��������������󳤶ȵĶ���
    //      out_of_range���߼�����ʹ��һ��������Ч��Χ��ֵ
    //  newͷ�ļ�������bad_alloc�쳣����
    //  type_infoͷ�ļ�������bad_cast�쳣����

}

void CppPrimer::initializerListTest(initializer_list<string> args, string extVal)
{
    cout << "initializerListTest: {";
    for (string cur : args)
        cout << cur << " ";
    cout << "} ";
    cout << extVal << endl;
}

vector<string> CppPrimer::listReturnTest(void)
{
    return vector<string>{ "hello", "list", "return" };
}

intAry3* CppPrimer::funcReturnIntAry3(void)
{
    return &intAry3Var;
}

intAry3Using* CppPrimer::funcReturnIntAry3Using(void)
{
    return &intAry3Var;
}

int(*CppPrimer::funcReturnIntAry3Plain(void))[3]
{
    return &intAry3Var;
}

auto CppPrimer::funcReturnIntAry3Tail(void) -> int(*)[3]
{
    return &intAry3Var;
}

decltype(CppPrimer::intAry3Var) *CppPrimer::funcReturnIntAry3Decltype(void)
{
    return &intAry3Var;
}

void CppPrimer::overloadTest(int intArg)
{
}

void CppPrimer::overloadTest(int * intPtrArg)
{
}

void CppPrimer::overloadTest(const int * intPtrArg)
{
}

void CppPrimer::overloadTest(int & intRefArg)
{
}

void CppPrimer::overloadTest(const int & intRefArg)
{
}

const string & CppPrimer::shorterString(const string & s1, const string & s2)
{ return s1.size() <= s2.size() ? s1 : s2; }

string & CppPrimer::shorterString(string &s1, string &s2)
{
    auto &r = shorterString(const_cast<const string&>(s1), const_cast<const string&>(s2));
    return const_cast<string&>(r);
}

void CppPrimer::defaultParValTest(int intVal, char charVal, double doubleVal) // ʵ��Ĭ��ֵ������ͷ�ļ���������������ʱ�����ټ�Ĭ��ֵ
{
    cout << "defaultParValTest: ";
    cout << "intVal: " << intVal << " charVal: " << charVal << " doubelval: " << doubleVal << endl;
}

// ������ڲ�����Ϊinline
void CppPrimer::inlineTest(void)
{
    cout << "This is an inline function." << endl;
}

string funcToBePointed(int iVal)
{
    if (1 == iVal)
    {
        return string("It's 1!");
    }
    else
    {
        return string("Not 1!");
    }
}

void CppPrimer::functionTest(void)
{
    // void fcn(const int i) { �� }
    // ��
    // void fcn(int i) { �� }
    // ���ظ����塣��Ϊ�βεĶ���const�����ԣ���������ǳ�����ʵ�ζ����ԡ�

    //// �����β�
    // void print(const int*); //�������ֺͱ����ȼ�
    // void print(const int[]); //��������������
    // void print(const int[10]); //ά�ȱ�ʾ����������Ԫ�ظ�����ʵ�ʲ�һ��
    // ��������������Ϊ����ʱ��ʵ���Զ�ת��Ϊָ��������Ԫ�ص�ָ�롣����Ĵ�С�Ժ����ĵ���û��Ӱ�졣

    //// �ɱ��β�
    // ����C++��C�Ľ����Ľӿڣ���varargs��c��׼�⹦�����ʡ�Է��β�
    // ʵ����ΪC��C++ͨ�õ����ͣ�ʡ�Է��β�ֻ�ܳ������β��б�����
    // void foo(parm_list, ��); //���ſ�ѡ
    // void foo(��);

    // C++11�ṩ���ַ���
    // ����һ���������ʵ��������ͬ�����Դ���initializer_list�ı�׼�����͡�
    initializerListTest(initializer_list<string>{"one", "two", "three"}, "hundred");
    initializerListTest(initializer_list<string>{"1", "2", "3", "4", "5"}, "100");
    // �����������ʵ�����Ͳ�ͬ����д�ɱ����ģ�� TODO

    //// �б��ʼ������ֵ
    // C++11�涨���������Է���{}��Χ��ֵ���б���
    for (string curStr : listReturnTest())
    { cout << curStr << " "; }
    cout << endl;

    //// ��������ָ��ĺ���
    // ����һ�� �����ͱ��������£�
    // typedef int arrT[10]; �� using arrT = int[10];
    // arrT* func(int i);
    intAry3 *aryPtr = nullptr;
    aryPtr = funcReturnIntAry3();
    printIntAry(*aryPtr, 3);

    aryPtr = funcReturnIntAry3Using();
    printIntAry(*aryPtr, 3);

    // ��������ֱ�����������£�
    // type(*function(parameter_list))[dimension]
    aryPtr = funcReturnIntAry3Plain();
    printIntAry(*aryPtr, 3);

    // ��������C++11β������trailing return type
    // ���ó��ַ������͵ĵط���auto���β��б�֮���->��������Ҫ�ķ�������
    //  auto func(int i) -> int(*)[10];
    aryPtr = funcReturnIntAry3Tail();
    printIntAry(*aryPtr, 3);

    // �����ģ�ʹ��decltype����ͬ�����鷵������
    // int odd[] = { 1,2,3,4,5 };
    // decltype(odd) *attrPtr(int i);
    aryPtr = funcReturnIntAry3Decltype();
    printIntAry(*aryPtr, 3);

    //// �����е�const_cast
    // �������º�����
    // const string &shorterString(const string &s1, const string &s2)
    // �����ͷ������Ͷ���const string�������������ǳ�����stringʵ�ε�����������������ص���Ȼ��const string������ʹ��const_castʵ�֣�
    // string &shorterString(string &s1, string &s2)
    // {
    //     auto &r = shortString(const_cast<const string&>(s1), const_cast<const string&>(s2));
    //     return const_cast<string&>(r);
    // }
    string strVal1 = "123";
    string strVal2 = "1234";
    cout << shorterString(strVal1, strVal2) << endl;

    // Ĭ��ʵ��
    // ����string screen(size_type ht = 24, size_type wid = 80, char backgrnd = ' ');
    // һ��ĳ���βθ���Ĭ��ֵ֮�����������βζ�������Ĭ��ֵ
    // ����ʱ��дʵ�εĻ��Զ�ʹ��Ĭ��ʵ��ֵ����ֻ��ʡ��β����ʼ��ʵ�Ρ�
    // ���ʱ�����Ѳ���ôʹ��Ĭ��ʵ�εĲ�����ǰ�档
    // ��������ʱ������������β����ʼ��һ����Ĭ��ʵ�Σ�֮���ٴ������˺�����ֻ������֮ǰ�Ѿ���������Ĭ��ʵ�Ρ�Ӧ����ͷ�ļ���ĺ���������ָ��Ĭ��ʵ�Ρ�
    // �ֲ�����֮��Ķ�������ΪĬ��ʵ�Ρ�
    defaultParValTest();
    defaultParValTest(123);
    defaultParValTest(234, '0');
    defaultParValTest(345, '9', 123.456);

    //// �������������������Ժ�������������
    inlineTest();

    //// constexpr����
    // ָ�����ڳ������ʽ�ĺ������ڷ�������ǰ���constexpr�����������¹涨
    //     �������ͺ��βζ�������������
    //     ������������ֻ��һ��return
    // �ڱ����ڰѺ����滻Ϊ���ֵ�����Ժ�����ʽ��Ϊ��������
    cout << "constexpr function: " << constexprFuncTest(2) << endl;

    //// ����ָ��
    // �磺bool(*pf)(const string &, const string &);
    // ��������Ϊֵʹ��ʱ���Զ�ת��Ϊָ��
    // ����ָ�븳ֵ��
    //     pf = lengthCompare;
    //     pf = &lengthCompare; //����һ��ȼۣ�&��ѡ
    // ����ֱ���ú���ָ����ú������������ã��磺
    //     bool b1 = pf("hello", "world");
    //     bool b2 = (*pf)("hello", "world"); //�ȼ�����һ��
    string (*fp)(int iVal);
    fp = funcToBePointed;
    cout << fp(1) << endl;
    fp = &funcToBePointed;
    cout << (*fp)(0) << endl;
    // ����ָ����Ϊ��������ʱ��
    //     �ñ���
    //         using F = int(int *, int);//��������
    //         using PF = int(*)(int *, int); //����ָ�����
    //         PF f1(int); //����ָ������ָ��
    //         F *f1(int); //����ָ������ָ��
    //     ֱ������int(*f1(int))(int*, int);
    //     β�÷�������auto f1(int) -> int(*)(int *, int);
    //     ������decltypeͬ�ຯ������ȡ����ָ������ͣ��������*
    //         size_type sumLength(const string &, const string &);
    //         decltype(sumLength) *getFcn(const string &);

}

void CppPrimer::assertTest(void)
{
    // assertԤ����꣬���ڼ�顰���ܷ����������� : assert(expr);
    // ���exprΪ�٣�assert�����Ϣ����ֹ�����ִ�У���Ϊ�棬assertʲô������
    // ������cassertͷ�ļ���
    // Ԥ����������Ԥ�����������Ǳ������������Կ���ֱ��ʹ��Ԥ�������ֶ������ṩusing����
    // ������NDEBUGʱ��assert��ִ������ʱ���
    // ������#include <cassert>֮ǰ#define NDEBUG���ر�assert�����ڱ������������NDEBUG�궨��
    // ������NDEBUG�����Լ��ĵ�����䣬�磺
    // #ifndef NDEBUG
    //     cerr << __func__ << endl;
    // #endif
    assert(true); // ���Գɹ�
    //assert(false); // ����ʧ��
    cerr << "This is an error message." << endl;

    // Ԥ�������������������������:
    //    __func__	��ǰ��������
    //    __FILE__	�ļ���
    //    __LINE__	��ǰ�к�
    //    __TIME__	�ļ�����ʱ��
    //    __DATE__	�ļ���������
    cout << "__func__: " << __func__ << endl;
    cout << "__FILE__: " << __FILE__ << endl;
    cout << "__LINE__: " << __LINE__ << endl;
    cout << "__TIME__: " << __TIME__ << endl;
    cout << "__DATE__: " << __DATE__ << endl;

}

const CppPrimer & CppPrimer::constMemFunction(int iVal) const
{
    // const��Ա�������ڳ�Ա�������β��б���const��
    // ��ʾ�˺������this��һ��ָ������ָ�루���ܸı�this�ĳ�Ա����
    // ���������Լ�ָ������������û�ָ�붼ֻ�ܵ��ó�����Ա������
    //arithType_bool = true; // ���ܸı䳣��this�ĳ�Ա
    cout << "arithType_bool: " << arithType_bool << endl; // ���Զ�ȡ��Ա
    mutableVar += iVal;
    cout << "in const, mutableVar: " << mutableVar << endl; // const��Ա�������Ըı�mutable��Ա
    return *this;
}

CppPrimer & CppPrimer::constMemFunction(int iVal)
{
    arithType_bool = true; // ���Ըı�ǳ���this�ĳ�Ա
    cout << "arithType_bool: " << arithType_bool << endl; // ���Զ�ȡ��Ա
    mutableVar += iVal;
    cout << "in non-const, mutableVar: " << mutableVar << endl;
    return *this;
}

void CppPrimer::classRefPtrTest(CppPrimer & classRef, CppPrimer * classPtr)
{

}

void CppPrimer::toBeFriendOfCppPrimerFriend(CppPrimerFriend insCppPrimerFriend)
{
    cout << "CppPrimer.toBeFriendOfCppPrimerFriend(): " << insCppPrimerFriend.privateStr << endl;
}

void outsideClassFunc(CppPrimer cppPrimerIns)
{
    cppPrimerIns.showInfo();
}

void outsideClassFunc(int iVal)
{
    cout << "This is an overload outsideClassFunc." << endl;
}

void friendFunc(CppPrimer cppPrimerIns)
{
    cout << "In friend function." << endl;
    cout << "Before changing, arithType_bool: " << cppPrimerIns.arithType_bool << endl;
    cppPrimerIns.arithType_bool = true;
    cout << "After changing, arithType_bool: " << cppPrimerIns.arithType_bool << endl;
}

