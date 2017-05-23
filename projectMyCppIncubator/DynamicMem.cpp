#include "stdafx.h"
#include "DynamicMem.h"
#include <memory>
#include <string>

using std::shared_ptr;
using std::unique_ptr;
using std::weak_ptr;
using std::string;

DynamicMem::DynamicMem()
{
}


DynamicMem::~DynamicMem()
{
}

void DynamicMem::DynamicMemTest(void)
{
    /*
        - ��̬�ڴ���������ֲ�static������static���ݳ�Ա���Լ��������κκ�����ı�����
        - ջ�ڴ��������涨���ں����ڵķ�static����
        ��̬�ڴ��ջ�ڴ��ɱ������Զ����������١�

        - �ѣ�heap��������ɿռ䣨free store�������洢��̬����Ķ���
        ��̬����Ķ����ɳ���������ʱ���䣬����ʹ��ʱ�ɳ�����ʽ���١�

        new������ڶ���Ϊ�������ռ䲢����ָ������ָ��
        delete��������ܶ�̬�����ָ�룬���ٸĶ����ͷ���֮�������ڴ�
    */

    /*
        C++ 11������ָ�루smart pointer�������Զ��ͷ���ָ��Ķ���
        shared_ptr������ָ��ָ��ͬһ������
        unique_ptr��ռָ��Ķ���
        weak_ptr�������ã�ָ��shared_ptr������Ķ���

        shared_ptr��unique_ptr��֧�ֵĲ�����
        shared_ptr<T> sp;       ������ָ�룬ָ������ΪT�Ķ���
        unique_ptr<T> up;       
        p;                      ��p��Ϊ�����жϣ���pָ��һ��������Ϊtrue
        *p;                     �����ã������ָ��Ķ���
        p->mem;                 �ȼ���(*p).mem
        p.get();                ����p�б����ָ�룬������ָ���ͷ�������󣬷��ص�ָ��ָ��Ķ���Ҳ��ʧ��
        swap(p, q);             ����p��q�е�ָ��
        p.swap(q);

        shared_ptr���еĲ�����
        make_shared<T>(args);   ����һ��shared_ptr��ָ��һ����̬�������args��ʼ��������ΪT�Ķ���
        shared_ptr<T>p(q);      p��q�Ŀ���������q�еļ�������q�е�ָ�������ת��ΪT*
        p=q;                    p��q����shared_ptr����ָ�����໥ת�����ݼ�p�����ü�����������q�����ü���������p�����ü�����Ϊ0����������ԭ�ڴ��ͷ�
        p.unique();             ��p.use_count()Ϊ1������true�����򷵻�false
        p.use_count();          ������p������������ָ��������ִ���ٶȿ��ܻ��������Ҫ���ڵ���
    */
    shared_ptr<string> strShPtr;
    428 shared_ptr�Ŀ����͸�ֵ
}
