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
using std::to_string;
using std::stoi;
using std::stol;
using std::stoul;
using std::stoll;
using std::stoull;
using std::stof;
using std::stod;
using std::stold;

StdLibContainer::StdLibContainer()
{
}


StdLibContainer::~StdLibContainer()
{
}

void StdLibContainer::testContainer(void)
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
    array<char, 3> charArray{ 'f', 'g', 'h' }; // array����ָ�������⣬��Ҫָ��������С

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
        C c1(c2);               ����c2�Ŀ���c1��array�ɿ������������������Ͳ��ܿ�����
        C c1 = c2;              ͬ�ϣ���ֵ��c1��size��Ϊc2��size
        C c(b, e);              ����c����������b����һ��������Ԫ��λ�ã���e�����������һ��Ԫ��֮���λ�ã�ָ����Χ��Ԫ�ؿ�����c���������ݼ��ɣ�������ͬ��array��֧�֣�
        C c{a, b, c...};        C++11�б��ʼ��c
        C c = {a, b, c...};     C++11ͬ�ϣ���ֵ��c1��size��Ϊc2��size
        C c(n);                 ˳��������array���⣩����n��Ԫ�أ�����ֵ��ʼ�����˹��캯����explicit�ġ�
        C c(n, t);              ͬ�ϣ�����ʼ��Ϊt
        ****��С****
        c.size();               c��Ԫ����Ŀ����֧��forward_list��
        c.max_size();           c�ɱ�������Ԫ����Ŀ
        c.empty();              ��c�д洢��Ԫ�أ�����false�����򷵻�true
    */
    /*
        ****��ֵ��swap****
        c1 = c2;                ��c1�е�Ԫ���滻Ϊc2
        c1 = {a, b, c...};      ��c1�е�Ԫ���滻Ϊ�б���Ԫ�أ�ԭ��������ʾarray��֧�֣�VS2017֧�֣�
                                *��array����swap����ʱ��arrayԪ�����������ȣ���Ϊʵ�ʽ���Ԫ��
                                *��������������swap���ٶȺܿ�Ϊ����ʱ�䣬��Ϊ���ǿ���Ԫ�ض��ǽ����������������ڲ����ݽṹ
        a.swap(b);              ����a��b��Ԫ�أ����ڰ汾֮�ṩ������
        swap(a, b);             ��a.swap(b)�ȼۣ��ڷ��Ա���к���Ҫ������ʹ�ô��ַǳ�Ա�汾��swap
                                *assign�������Ͳ�ͬ�����ݵĸ�ֵ�����������и�ֵ���������ڹ���������array
        seq.assign(b, e);       ��seq��Ԫ���滻Ϊ������b��e����ʾ��Χ�ڵ�Ԫ�أ�������b��e����ָ��seq��Ԫ�أ���Ϊ��Ԫ�ػᱻ�滻��
        seq.assign(il);         ��seq��Ԫ���滻Ϊ��ʼ���б�il�е�Ԫ��
        seq.assign(n, t);       ��seq��Ԫ���滻Ϊn��ֵΪt��Ԫ��
    */
    // ע�⸳ֵ�����ᵼ�������ڲ��ĵ����������á�ָ��ʧЧ
    vector<int> vectorInt10 = { 0,1,2,3,4,5,6,7,8,9 };
    vector<int> vectorInt5 = { 4,3,2,1,0 };
    cout << "vectorInt10 size [" << vectorInt10.size() << "] " <<
        "vectorInt5 size [" << vectorInt5.size() << "]" << endl;
    vectorInt10 = vectorInt5; // ��ͬ��С��������ֵ����ߵ�������С��Ϊ�ұ�������С
    cout << "vectorInt10 size [" << vectorInt10.size() << "] " <<
        "vectorInt5 size [" << vectorInt5.size() << "]" << endl;

    array<int, 10> aryInt10 = { 0,1,2,3,4,5,6,7,8,9 };
    array<int, 10> aryInt10Another = { 9,8,7,6,5,4,3,2,1,0 };
    array<int, 5> aryInt5 = { 4,3,2,1,0 };
    //aryInt10 = aryInt5; // array��ֵ����������ͬ
    aryInt10 = aryInt10Another; // ������ͬ�����Ը�ֵ
    cout << "before " << aryInt5[0] << aryInt5[1] << aryInt5[2] << aryInt5[3] << aryInt5[4] << endl;
    aryInt5 = { 1,2 };
    cout << "after " << aryInt5[0] << aryInt5[1] << aryInt5[2] << aryInt5[3] << aryInt5[4] << endl;

    cout << endl;

    /*
        ****��ϵ�����****
        *��������ߵ���������������ͬ��Ԫ��������ͬ
        ==, !=                  ����������֧��
        <, <=, >, >=            ��ϵ��������������������֧��
                                �ȽϹ���
                                - ����������С��ͬ������Ԫ��������Ӧ��ȣ���������ȣ����򲻵�
                                - ����������С��ͬ����С������ÿ��Ԫ�ض����ڽϴ������ж�ӦԪ�أ����С����С�ڽϴ�����
                                - ����������������һ��������ǰ׺�����У���ȽϽ��ȡ���ڵ�һ������ȵ�Ԫ�رȽϽ��
    */
    vector<int> vector1 = { 1,3,5,7,9,12 };
    vector<int> vector2 = { 1,3,9 };
    vector<int> vector3 = { 1,3,5,7 };
    vector<int> vector4 = { 1,3,5,7,9,12 };
    cout << "vector1 < vector2: " << ((vector1 < vector2) ? "true" : "false") << endl; // ���ȡ����Ԫ��[2]
    cout << "vector1 < vector3: " << ((vector1 < vector3) ? "true" : "false") << endl; // Ԫ�ض���ȣ�vector3Ԫ��������
    cout << "vector1 == vector4: " << ((vector1 == vector4) ? "true" : "false") << endl; //��С��ͬ��Ԫ�����
    cout << "vector1 == vector2: " << ((vector1 == vector2) ? "true" : "fasle") << endl; // vector2Ԫ��������

    cout << endl;

    /*
    ****��ȡ������****
    c.begin(); c.end();     ����ָ��c����Ԫ�غ�βԪ��֮��λ�õĵ�����iterator
    c.cbegin(); c.cend();   ����const_iterator
    ****���������Ķ����Ա����֧��forward_list��****
    reverse_iterator        ������ѰַԪ�صĵ�������++�õ���һ��Ԫ��
    const_reverse_iterator  �����޸�Ԫ�ص����������
    c.rbegin(); c.rend();   ����ָ��c��βԪ�غ���Ԫ��֮ǰΪֹ�ĵ�����reverse_iterator
    c.crbegin(); c.crend(); ����const_reverse_iterator
    ****˳����������****
    ˳����������front()��Ա������������Ԫ�ص�����
    ˳����������forward_list�ⶼ��back()��Ա����������βԪ�ص�����
    at���±����ֻʹ����string��vector��deque��array����������
    ������������±�Խ�磬at()Խ����׳�out_of_range�쳣
    */
    vector<string> strVector = { string("first"),string("second"),string("third") };
    cout << "begin(): " << *strVector.begin() << " end(): " << *(strVector.end()-1) << endl; // end()����ĩβԪ�غ�һλ��
    cout << "front(): " << strVector.front() << " back(): " << strVector.back() << endl;
    cout << "at(1): " << strVector.at(1) << endl;
    strVector[1] = "2nd";
    cout << "[1]: " << strVector[1] << endl;
    cout << "rangefor: ";
    for (string str : strVector)
    {
        cout << str << " ";
    }
    cout << endl;

    cout << endl;
    /*
        ****����������֧�ֵ����ɾ��Ԫ�أ������ò��ܸı��С��array��****
        c.insert(args);         ��args��Ԫ�ؿ�����c
        c.emplace(inits);       ʹ��inits����c�е�һ��Ԫ��
        c.erase(args);          ɾ��argsָ����Ԫ��
        c.clear();              ɾ��c������Ԫ�أ�����void
        ****˳���������е����ɾ������****
        *�����ǿ���������������Ǹ���
        *vector��string��Ԫ�������洢
        *��vector��stringβ��֮����κ�λ�ã���deque��β֮����κ�λ�����Ԫ�أ�����Ҫ�ƶ�Ԫ��
        *��vector��string���Ԫ�ؿ���������������洢�ռ�����·���
        *�������vector��string֮�������·���ռ�������������á�ָ��ȫ��ʧЧ����δ���·��䣬�����λ��֮��Ļ�ʧЧ
        *�������deque֮�󣬲��뵽��β֮���λ�û�ʹ���е����������ú�ָ��ʧЧ�����뵽��βλ�ã���������ʧЧ�����ú�ָ�벻��ʧЧ
        *�������list��forward_list֮�󣬵�������ָ�롢���ö���Ч
        *ɾ������deque֮��ɾ����βԪ��֮����κ�Ԫ�ض���ʹ���е����������ú�ָ��ʧЧ��ɾ��βԪ����β�������ʧЧ��ɾ����Ԫ�ز���ʧЧ
        *ɾ������vector��string֮��ɾ����֮��λ�õĵ����������ú�ָ�붼��ʧЧ
        *ɾ������list��forward_list֮�󣬵����������á�ָ�붼��Ч
        *vector��string��֧��push_front��emplace_front��pop_front
        c.push_back(t);         ��c��β������ֵΪt����args������Ԫ�أ�����void��tΪԪ�����͵Ķ���
        c.emplace_back(args);   C++11��argsΪԪ�ع��캯���Ĳ���
        c.push_front(t);        ��c��ͷ������ֵΪt����args������Ԫ�أ�����void
        c.emplace_front(args);  C++11
        c.insert(p,t);          ��c�ĵ�����pָ���Ԫ��֮ǰ�����Ϊt����args������Ԫ�أ�����ָ�������Ԫ�صĵ�����
        c.emplace(p,args);      C++11
        c.insert(p,n,t);        ��c�ĵ�����pָ���Ԫ��֮ǰ���n��ֵΪt��Ԫ�أ�����ָ������ӵĵ�һ��Ԫ�صĵ���������nΪ0������p
        c.insert(p,b,e);        ��b��e������ָ����Χ�ڵ�Ԫ�ز��뵽������pָ���Ԫ��֮ǰ��b��e����ָ��c������ָ������ӵĵ�һ��Ԫ�صĵ�����������ΧΪ�գ�����p
        c.insert(p,il);         il�ǻ����Ű�Χ��Ԫ��ֵ�б����뵽������pָ���Ԫ��֮ǰ������ָ������ӵĵ�һ��Ԫ�صĵ���������ilΪ�գ�����p
        c.pop_back();           ɾ��c��βԪ�أ�����void
        c.pop_front();          ɾ��c����Ԫ�أ�����void
        c.erase(p);             ɾ��p������ָ����Ԫ�أ����ر�ɾԪ��֮���Ԫ�ص�����
        c.erase(b,e);           ɾ��b��e��ָ��Χ�ڵ�Ԫ�أ�����ָ�����һ����ɾԪ��֮���Ԫ�ص�����
        c.clear();              ɾ��c������Ԫ�أ�����void
        *forward_list���Լ���insert��emplace��erase
        *forward_list��֧��push_back��emplace_back��pop_back
        *forward_list���������: forward_list�ǵ������������ɾ�����ڸ���������֮�����
        lst.before_begin();     ����ָ��������Ԫ��֮ǰ�����ڵ�Ԫ�صĵ��������˵��������ܽ�����
        lst.cbefore_begin();    ����const_iterator
        lst.insert_after(p,t);  �ڵ�����p֮�����Ԫ�أ�����ָ�����Ԫ�صĵ�����
        lst.insert_after(p,n,t);�ڵ�����p֮�����n��t���󣬷���ָ�����һ������Ԫ�صĵ�����
        lst.insert_after(p,b,e);��b��eָ����Χ�Ķ�����뵽������p֮��b��e����ָ��lst�������ΧΪ�գ�����p
        lst.insert_after(p,il); �ѻ������б������뵽������p֮��
        lst.emplace_after(p, args); ʹ��args��pָ����λ��֮�󴴽�һ��Ԫ�أ�����ָ����Ԫ�صĵ�����
        lst.erase_after(p);     ɾ��pָ���λ��֮���Ԫ�أ����ر�ɾԪ��֮��Ԫ�صĵ�����
        lst.erase_after(b,e);   ɾ��b��eָ����Χ�ڵ�Ԫ��
    */
    deque<char> cDeque = { '1', '2', '3' };
    cout << "Initial deque: ";
    for (char c : cDeque) { cout << c << " "; } cout << endl;

    cDeque.pop_back();
    cout << "pop_back: ";
    for (char c : cDeque) { cout << c << " "; } cout << endl; 

    cDeque.pop_front();
    cout << "pop_front: ";
    for (char c : cDeque) { cout << c << " "; } cout << endl;

    cDeque.push_back('C');
    cout << "push_back: ";
    for (char c : cDeque) { cout << c << " "; } cout << endl;

    cDeque.emplace_front('A');
    cout << "emplace_front: ";
    for (char c : cDeque) { cout << c << " "; } cout << endl;

    deque<char>::iterator itr = cDeque.end() - 2;
    itr = cDeque.erase(itr);
    cout << "erase: ";
    for (char c : cDeque) { cout << c << " "; } cout << endl;

    cDeque.insert(itr, 'B');
    cout << "insert: ";
    for (char c : cDeque) { cout << c << " "; } cout << endl;

    cDeque.clear();
    cout << "clear: ";
    for (char c : cDeque) { cout << c << " "; } cout << endl;

    cout << endl;

    /*
        ****�ı�������С�������ò��ܸı��С��array��****
        *��С������ɾ��β��Ԫ�أ�����������β�����Ԫ��
        *resizeֻɾ��Ԫ�ظı�size()�����ı�capacity()��Ӧ���ڴ�ռ�
        c.resize(n);    �ı�c��СΪn
        c.resize(n, t); �ı�c��СΪn������ʱ��ӵ�Ԫ�س�ʼ��Ϊt
        *shrink_to_fitֻ������vector��string��deque
        *capacity��reserveֻ������vector��string
        c.shrink_to_fit();  ��capacity()����Ϊ��sizeof()ͬ����С�������ھ���ʵ�֣�����֤�ͷ��ڴ�
        c.capacity();       �����·����ڴ�ռ�Ļ���c���Ա������Ԫ��
        c.reserve(n);       ��������������n��Ԫ�ص��ڴ�ռ�
    */
    vector<char> cVector = { '1','2','3' };
    cout << "Initial: ";
    for (char c : cVector) { cout << c << " "; } cout << endl;
    cout << "Size: " << cVector.size() << " Capacity: " << cVector.capacity() << endl;

    cVector.resize(1);
    cout << "resize small: ";
    for (char c : cVector) { cout << c << " "; } cout << endl;
    cout << "Size: " << cVector.size() << " Capacity: " << cVector.capacity() << endl;

    cVector.resize(3);
    cout << "resize large: ";
    for (char c : cVector) { cout << c << " "; } cout << endl;
    cout << "Size: " << cVector.size() << " Capacity: " << cVector.capacity() << endl;

    cVector.resize(5, 'L');
    cout << "resize large init: ";
    for (char c : cVector) { cout << c << " "; } cout << endl;
    cout << "Size: " << cVector.size() << " Capacity: " << cVector.capacity() << endl;

    cVector.reserve(10);
    cout << "reserve: ";
    for (char c : cVector) { cout << c << " "; } cout << endl;
    cout << "Size: " << cVector.size() << " Capacity: " << cVector.capacity() << endl;

    cVector.shrink_to_fit();
    cout << "shrink: ";
    for (char c : cVector) { cout << c << " "; } cout << endl;
    cout << "Size: " << cVector.size() << " Capacity: " << cVector.capacity() << endl;

    cout << endl;

    /*
        ****string���****
    */
    // ���캯��
    string s1; //Ĭ�Ϲ��캯��
    cout << "s1: " << s1 << endl;
    string s2 = s1; //S2��S1�ĸ���
    cout << "s2: " << s2 << endl;
    string s3 = "hello"; //s3������ֵ�ĸ���
    cout << "s3: " << s3 << endl;
    string s4(5, 'c'); //s4��������ccccc
    cout << "s4: " << s4 << endl;
    char charAry[] = "test";
    string s5(charAry, 2);   //s5��s3ǰ2���ַ��Ŀ���
    cout << "s5: " << s5 << endl;
    string s6(s3, 2); //s6��s3���±�2��ʼ���ַ��Ŀ���
    cout << "s6: " << s6 << endl;
    string s7(s3, 1, 3); //s7��s3���±�1��ʼ�ĳ���λ3���ַ�����
    cout << "s7: " << s7 << endl;

    cout << endl;

    /*
        substr(pos, n);         ����string��������pos��ʼ��n���ַ��Ŀ���
        *string֧��������assign��insert��erase���������ṩ�����±��insert��erase
        s.insert(pos, args);    ��pos֮ǰ����argsָ�����ַ���pos�������±꣨����ָ��s�����ã��������������ָ���һ�������ַ��ĵ���������
        s.erase(pos, len);      ɾ����λ��pos��ʼ��len���ַ�����ʡ��len��ɾ��ĩβ������ָ��s������
        s.assign(args);         ��s���ַ��滻Ϊargsָ�����ַ�������ָ��s������
        s.append(args);         ��args׷�ӵ�s������ָ��s������
        s.replace(range, args); ɾ��range�ڵ��ַ����滻Ϊargsָ�����ַ���range��һ���±��һ�����ȣ���һ��ָ��s�ĵ�����������ָ��s�����á�
        *����string
        s.find(args);           ���ҵ�һ�γ��ֵ�λ��
        s.rfind(args);          �������һ�γ��ֵ�λ��
        s.find_first_of(args);  ����args���κ�һ���ַ���һ�γ��ֵ�λ��
        s.find_last_of(args);   ����args���κ�һ���ַ����һ�γ��ֵ�λ��
        s.find_first_not_of(args);  ���ҵ�һ������args�е��ַ�
        s.find_last_not_of(args);   �������һ������args�е��ַ�
        *�Ƚ�string
        s.compare();            �������汾
        *��ֵת��
        to_string(val);         ����������������val��string��ʾ��
        *sto_(s,p,b);           ����s��ʼ�Ӵ�����ֵ��bΪת������Ĭ��10��p��size_tָ�뱣��s��һ���������ַ��±꣬Ĭ��Ϊ0��ʾ�������±�
        stoi(s,p,b);            ����int
        stol(s,p,b);            ����long
        stoul(s,p,b);           ����unsigned long
        stoll(s,p,b);           ����long long
        stoull(s,p,b);          ����unsigned long long
        stof(s,p);              ����float
        stod(s,p);              ����double
        stold(s,p);             ����long double
    */
    cout << "to_string(12345): " << to_string(12345) << endl;
    cout << "stoi(\"12345\"): " << stoi(string("12345")) << endl;
    cout << "stoi(\"010\"): " << stoi(string("010"), 0, 8) << endl;
    cout << "stoi(\"0x10\"): " << stoi(string("0x10"), 0, 16) << endl;
    cout << "stof(\"3.14\"): " << stof(string("3.14")) << endl;

    cout << endl;

}

