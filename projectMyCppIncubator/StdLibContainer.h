#pragma once
class StdLibContainer
{
public:
    StdLibContainer();
    StdLibContainer(int initData);
    ~StdLibContainer();

    // ���ڱȽϴ�С������
    int data;

    // ����
    void testContainer(void);
    // ����
    void testGeneric(void);
    // ������
    void testIterator(void);

};


//// �ǳ�Ա�ӿں���
// ���ڱȽϴ�С���ϸ�������
bool compareStdLibContainer(StdLibContainer insA, StdLibContainer insB);