#include "stdafx.h"
#include "StdLibContainer.h"
#include <string>
#include <vector>
#include <deque>
#include <list>
#include <forward_list>
#include <array>
#include <iostream>

using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::deque;
using std::list;
using std::forward_list;
using std::array;

StdLibContainer::StdLibContainer()
{
}


StdLibContainer::~StdLibContainer()
{
}

void StdLibContainer::sequenceContainer(void)
{
    // �������ض����Ͷ���ļ���
    // ˳���������ṩ����Ԫ�ش洢�ͷ���˳�������˳����Ԫ�ؼ�������ʱ��λ�ö�Ӧ

    //// ����˳����������
    // vector �ɱ��С���飬֧�ֿ���������ʣ�β��֮������ɾ��Ԫ�ؿ��ܺ���
    // string ��vector���ƣ�ר�����ڱ����ַ���������ʿ죬��β�������ɾ���ٶȿ�
    // deque ˫�˶��У�֧�ֿ���������ʣ�ͷβ�����ɾ���ܿ�
    // list ˫������ֻ֧��˫��˳����ʣ��κ�λ�ò����ɾ�����ܿ�
    // forward_list ��������ֻ֧�ֵ���˳����ʣ��κ�λ�ò����ɾ�����ܿ�
    // array �̶���С���飬֧�ֿ���������ʣ�������ӻ�ɾ��Ԫ��

    // string��vector��Ԫ�ر������������ڴ�ռ䣬�������±�����ַ�ǳ��졣
    // �����м�λ�ò����ɾ��ʱ����Ҫ�ƶ���������Ԫ��������������
    // ���Ԫ�ػ�������Ҫ�������Ĵ洢�ռ䲢�ƶ�����Ԫ�أ����Ժܺ�ʱ��

    // list��forward_list����������������λ����Ӻ�ɾ�����ܿ졣
    // ����֧��������ʣ�Ҫ����Ԫ�ر����������
    // ��vector��deque��array�ȣ���Ҫ������ڴ濪����
    // forward_listû��size������Ϊ�˽�ʡ���������С�Ķ��⿪����

    // deque��string��vector���ƣ�֧�ֿ���������ʣ����м�λ����ӻ�ɾ��Ԫ�ش��ۿ��ܸܺߡ�
    // ��������ӻ�ɾ��Ԫ���ٶȺܿ죬��list��forward_list�ٶ��൱

    // array��С�̶�����֧����ӻ�ɾ���������������鰲ȫ������ʹ�á�

    //// ѡ�������Ĺ���
    // - �����úܺõ�����ѡ����������������ʹ��vector
    // - �кܶ�СԪ�أ��ռ�Ķ��⿪������Ҫ����Ҫʹ��list��forward_list
    // - Ҫ���������Ԫ��ʱ��ʹ��vector��deque
    // - Ҫ�����м�����ɾ��Ԫ�أ�ʹ��list��forward_list
    // - ֻ��ͷβ�����ɾ��Ԫ�أ�ʹ��deque
    // - �������ʱ��Ҫ���м����Ԫ�أ������Ҫ������ʣ���������list���ٰ�list�����ݿ�����vector

    vector<char> charVector{ 'a', 'b', 'c' };
    string charString("4 5 6"); 
    deque<char> charDeque = { '7', '8', '9' };
    list<char> charList{ '0', 'a', 'b' };
    forward_list<char> charFarwardList = { 'c', 'd', 'e' };
    array<char, 3> charArray{ 'f', 'g', 'h' };

    //// ��������
    /*
        ****���ͱ���****
        iterator                ĳ�������͵ĵ���������
        const_iterator          ���Զ�ȡԪ�ص������޸�Ԫ�صĵ���������
        size_type               �޷����������㹻����ĳ������������������С
        difference_type         �з����������㹻��������������֮��ľ���
        value_type              Ԫ������
        reference               Ԫ�ص���ֵ���ͣ���value_type&������ͬ
        const_reference         Ԫ�ص�const��ֵ���ͣ���const value_type&
        ****���캯��****
        C c;                    Ĭ�Ϲ��캯�������������
        C c1(c2);               ����c2�Ŀ���c1
        C c(b, e);              ����c����������b��eָ����Χ��Ԫ�ؿ�����c��array��֧�֣�
        C c{a, b, c...};        �б��ʼ��c
        ****��ֵ��swap****
        c1 = c2;                z��c1�е�Ԫ���滻Ϊc2
        c1 = {a, b, c...};      z��c1�е�Ԫ���滻Ϊ�б���Ԫ�أ�array��֧�֣�
        a.swap(b);              z����a��b��Ԫ��
        swap(a, b);             z��a.swap(b)�ȼ�
        ****��С****
        c.size();               c��Ԫ����Ŀ����֧��forward_list��
        c.max_size();           c�ɱ�������Ԫ����Ŀ
        c.empty();              ��c�д洢��Ԫ�أ�����false�����򷵻�true
        ****���ɾ��Ԫ�أ�������array��****
        c.insert(args);         ��args��Ԫ�ؿ�����c
        c.emplace(inits);       ʹ��inits����c�е�һ��Ԫ��
        c.erase(args);          ɾ��argsָ����Ԫ��
        c.clear();              ɾ��c������Ԫ�أ�����void
        ****��ϵ�����****
        ==, !=                  ����������֧�ֵ��ڡ������������
        <, <=, >, >=            ��ϵ��������������������֧��
        ****��ȡ������****
        c.begin(); c.end();     ����ָ��c����Ԫ�غ�βԪ��֮��λ�õĵ�����iterator
        c.cbegin(); c.cend();   ����const_iterator
        ****���������Ķ����Ա����֧��forward_list��****
        reverse_iterator        ������ѰַԪ�صĵ�������++�õ���һ��Ԫ��
        const_reverse_iterator  �����޸�Ԫ�ص����������
        c.rbegin(); c.rend();   ����ָ��c��βԪ�غ���Ԫ��֮ǰΪֹ�ĵ�����reverse_iterator
        c.crbegin(); c.crend(); ����const_reverse_iterator
    */
}

