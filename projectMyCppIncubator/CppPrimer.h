#pragma once
class CppPrimer
{
public:
	CppPrimer();
	~CppPrimer();
	// ��ʾ˽�г�Ա���������ͱ�����ֵ
	void displayArithTypes(void);
	// ���Ը��ֳ�ʼ���ķ�ʽ
	void varInitTest(void);
	// ָ��/����/const���
	void ptrRefTest(void);
	// �ַ���
	void stringTest(void);
	// ����
	void vectorTest(void);
	// ������
	void iteratorTest(void);
	// ����
	void arrayTest(void);
    // �쳣
    void exceptionTest(void);
private:
	////////�������ͱ���
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

    void exceptionThrower(void);

};

