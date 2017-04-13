#pragma once

#include <string>
#include <vector>
#include <initializer_list>
#include <iostream>

typedef int intAry3[3];
using intAry3Using = int[3];

// struct��class�����𣺿���������һ�������ࡣ
// �������ڣ�struct������࣬�ڵ�һ������˵����֮ǰ�ĳ�Ա��public�ģ�
// class������࣬�ڵ�һ������˵����֮ǰ�ĳ�Ա��private�ġ�

class CppPrimer
{
    //// ��Ԫ��������
    // ���Ҫ�Ѷ�����غ�����Ϊ��Ԫ�����������ÿһ�����غ���������Ԫ��������Ϊ���غ����ǲ�ͬ�ĺ���
    friend void friendFunc(CppPrimer cppPrimerIns);
    
    //// ��Ԫ������
    // ��Ԫ��ϵ�����ڴ����ԣ�CppPrimerFriend����Ԫ�����Զ���ΪCppPrimer����Ԫ
    // ÿ���ฺ������Լ�����Ԫ
    friend class CppPrimerFriend;

public:

    //// ���ͳ�Ա
    typedef std::string CppPrimerStr;
    using CppPrimerStrUsing = std::string;

    //// ���졢����
    // ��ʽ����Ĭ�Ϲ��캯��
    CppPrimer() = default;

    // ð�ź�Ϊ���캯����ʼֵ�б��б���Եĳ�Ա�����ڳ�ʼֵ��ʼ������Ĭ��ֵ��ʼ��
    CppPrimer(bool boolInitVal) 
        : arithType_bool(boolInitVal)
    { std::cout << "Constructor(bool)" << std::endl; }

    CppPrimer(bool boolInitVal, char charInitVal, wchar_t wcharInitVal)
        : arithType_bool(boolInitVal), arithType_char(charInitVal), arithType_wchar(wcharInitVal) 
    { std::cout << "Constructor(bool, char, wchar_t)" << std::endl; }

    // ����Ϊstring
    // explicit�ؼ�����ֹ�˹��캯���Ĳ�������ʽ������ת��
    // ��������Ĺ��캯��������ʽ������ת��������explicitֻ�Ե��������캯����Ч
    // explicit�ؼ���ֻ������������ڲ��Ĺ��캯�������������ⲿ�Ķ��岻�ܼ�explicit
    explicit CppPrimer(CppPrimerStr initStr);
    
    // C++11����ί�й��캯����һ�����캯��ʹ������������������캯��ִ�в��ֻ�ȫ����ʼ��������
    // �����������캯��������һ������������������
    CppPrimer(int iInitVal)
        : CppPrimer(true) 
    { }

    // �����������캯���������Լ���ʵ�Σ�����������
    CppPrimer(int iInitVal, bool bInitVal) : CppPrimer(bInitVal) 
    { }

    // ��ִ�б�ί�еĹ��캯������ִ��ί�й��캯��
    CppPrimer(char cInitVal)
        : CppPrimer(std::string("Delegated constructor")) 
    { std::cout << "Delegating constructor" << std::endl; }

	~CppPrimer();

    //// ֻ��ӡ��Ϣ�ĺ���
    void showInfo(void)
    { std::cout << "/!\\showInfo()." << std::endl; } // ���������ڲ��ĺ�������ʽ��inline

	//// ��ʾ˽�г�Ա���������ͱ�����ֵ
	void displayArithTypes(void);
	
    //// ���Ը��ֳ�ʼ���ķ�ʽ
	void varInitTest(void);
	
    //// ָ��/����/const���
	void ptrRefTest(void);
	
    //// �ַ���
	void stringTest(void);
	
    //// ����
	void vectorTest(void);
	
    //// ������
	void iteratorTest(void);
	
    //// ����
	void arrayTest(void);
    
    //// �쳣
    void exceptionTest(void);
    
    //// �������
    void functionTest(void);
    
    //// ����
    // ͬһ�������ڵļ�������������ͬ���β��б�ͬ���β����������ͣ�
    // ����������ʵ�������жϵ��õ����ĸ������������ھ�����
    // ������ֻ�з���ֵ��ͬ�Ķ����������
    // main��������
    // �β��ж���const��û�ж���const��һ���ģ�����ʱҪע�⣻�ײ�const��ʵ������
    void overloadTest(int intArg);
    //void overloadTest(const int intArg); // ����const���ظ�����
    void overloadTest(int *intPtrArg);
    //void overloadTest(int * const intPtrArg); // ����const���ظ�����
    void overloadTest(const int* intPtrArg); // �ײ�const��constָ�룬����
    void overloadTest(int &intRefArg); // ��ͨ����
    void overloadTest(const int &intRefArg); // �ײ�const��const���ã�����

    // const_cast��������
    const std::string &shorterString(const std::string &s1, const std::string &s2);
    std::string &shorterString(std::string &s1, std::string &s2);
    
    //// Ĭ��ʵ��
    void defaultParValTest(int intVal = 1, char charVal = '2', double doubleVal = 3.0);
    
    //// ��������
    inline void inlineTest(void);
    // ����������constexpr�������Զ�ζ��壬�����������ȫһ�£�����ͨ��������ͷ�ļ��С�
    
    //// ����
    void assertTest(void);
    
    //// const��Ա����
    const CppPrimer &constMemFunction(int iVal) const; // ���ض������ã��Ա㼶������
    CppPrimer &constMemFunction(int iVal); //��const��Ա��������const��Ա����

    // �಻�ܰ�������Ϊ�Լ��ĳ�Ա����Ϊ��������Ҫ֪����ռ���ٴ洢�ռ䡣
    // ����ֻҪ�������ٿ�֮�󣬾���Ϊ��������������������ָ���Լ����͵����û�ָ��
    void classRefPtrTest(CppPrimer &classRef, CppPrimer *classPtr);

    //// ������ΪCppPrimerFriend�����Ԫ
    void toBeFriendOfCppPrimerFriend(CppPrimerFriend insCppPrimerFriend);

    //// ������ʽ������ת��
    void convertingConstructorTest(CppPrimer insCppPrimer);

private:
	////�������ͱ���
	// ��С�ߴ�淶δ����
	bool arithType_bool = false;
	// ��С�ߴ�8-bit. ���������ͣ�char/unsigned char/signed char��
	// char��һ����signed���ɱ���������
	char arithType_char = u8'A'; 
	// ��С�ߴ�16-bit
	wchar_t arithType_wchar = L'B';
	// ��С�ߴ�16-bit Unicode
	char16_t arithType_char16 = u'��';
	// ��С�ߴ�32-bit Unicode
	char32_t arithType_char32 = U'��';
	// ��С�ߴ�16-bit
	short arithType_short = 32767;
	// ��С�ߴ�16-bit, VS��32-bit
	unsigned int arithType_int = 65535u;
	// ��С�ߴ�32-bit
	long arithType_long = 2147483647L;
	// ��С�ߴ�64-bit
	long long arithType_longlong = 9223372036854775807LL;
	// 6λ��Ч����
	float arithType_float = 0.123456F;
	// 10λ��Ч����
	double arithType_double = 0.0123456789;
	// 10λ��Ч����
	long double arithType_longdouble = 0.0987654321L;
	// ָ��
	short *arithType_ptr = nullptr;
    // ����
    intAry3 intAry3Var{ 1, 2, 3 }; // ���ڳ�ʼֵ����ʹ��=����ʼ��������{}ֱ�ӳ�ʼ��
    // �ɱ����ݳ�Ա
    mutable int mutableVar = 0; // ���ڳ�ʼֵ����ʹ��=����ʼ��������{}ֱ�ӳ�ʼ��

    //// ��ӡ����
    void CppPrimer::printIntAry(int intAry[], int size);
    
    //// �׳��쳣��
    void exceptionThrower(void);
    void exceptionThrower(int intVal); // ���س�Ա����
    
    //// �ɱ������β�
    void initializerListTest(std::initializer_list<std::string> args, std::string extVal);
    
    //// �б���ֵ
    std::vector<std::string> listReturnTest(void);
    
    //// ��������ָ��
    intAry3* funcReturnIntAry3(void);
    intAry3Using* funcReturnIntAry3Using(void);
    int(*funcReturnIntAry3Plain(void))[3];
    auto funcReturnIntAry3Tail(void) -> int(*)[3];
    decltype(intAry3Var) *funcReturnIntAry3Decltype(void);
};

//// �ǳ�Ա�ӿں���
void outsideClassFunc(CppPrimer cppPrimerIns);
void outsideClassFunc(int iVal); // �ǳ�Ա��������
void friendFunc(CppPrimer cppPrimerIns); // ��Ԫ����

//// constexpr����
constexpr int constexprFuncTest(int x) { return 123 * x; }
