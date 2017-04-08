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
private:
	////////�������ͱ���
	// ��С�ߴ�淶δ����
	bool arithType_bool = false;
	// 8-bit. ���������ͣ�char/unsigned char/signed char��
	// char��һ����signed���ɱ���������
	char arithType_char = u8'A'; 
	// 16-bit
	wchar_t arithType_wchar = L'B';
	// 16-bit Unicode
	char16_t arithType_char16 = u'��';
	// 32-bit Unicode
	char32_t arithType_char32 = U'��';
	// 16-bit
	short arithType_short = 32767;
	// 16-bit TODO: ȷ��16-bit
	unsigned int arithType_int = 65535u;
	// 32-bit
	long arithType_long = 2147483647L;
	// 64-bit
	long long arithType_longlong = 9223372036854775807LL;
	// 6λ��Ч����
	float arithType_float = 0.123456F;
	// 10λ��Ч����
	double arithType_double = 0.0123456789;
	// 10λ��Ч����
	long double arithType_longdouble = 0.0987654321L;

};

