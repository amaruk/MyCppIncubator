#pragma once
#include <iostream>
#include <string>

// �ۺ���aggregrate class������������������
// - ���г�Ա����public
// - û�ж����κι��캯��
// - û�����ڳ�ʼֵ
// - û�л��࣬û��virtual����
// ����ۺ���ĳ�Ա��������ֵ������Ϊ����ֵ������
class CppPrimerAggregate
{
public:
    std::string stringVar;
    int intVar;

    void printStr(void) { std::cout << stringVar << std::endl; }
};

