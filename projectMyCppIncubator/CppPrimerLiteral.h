#pragma once

// ���Ǿۺ�����࣬�����������������Ϊ����ֵ�����ࣺ
// * ���ݳ�Ա��������������
// * �������ٺ���һ��constexpr���캯��
// * ������ݳ�Ա�������ڳ�ʼֵ
//   - �������ͳ�Ա��ʼֵ�����ǳ������ʽ
//   - �������͵ĳ�Ա��ʼֵ����ʹ��constexpr���캯����ʼ��
// * �����ʹ��Ĭ�϶������������
class CppPrimerLiteral
{
public:
    constexpr CppPrimerLiteral(bool bVar = true)
        : boolVar(bVar) {};
private:
    bool boolVar;
};

