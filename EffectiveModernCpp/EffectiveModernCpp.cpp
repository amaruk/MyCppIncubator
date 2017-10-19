#include "stdafx.h"
#include <iostream>
#include "Chapter1.h"
#include "Chapter5.h"
#include "Item3.h"
#include "Item9.h"


using std::cout;
using std::endl;

int main()
{
////////// Chapter One: Deducing types //////////
  /*
    C++98��type deduction����
      - for function templates
    C++11��type deduction����
      - for auto
      - for decltype
    C++14��C++11�Ĺ��������չ
  */
  //item1();
  //item2();
  //item3();
  //TODO item4();
  
////////// Chapter Two: auto //////////
  //TODO item5();
  //TODO item6();

////////// Chapter Three: Moving to Modern C++ //////////
  //TODO item7();
  //TODO item8();
  //item9();
  //TODO item10();
  //TODO item11();
  //TODO item12();
  //TODO item13();
  //TODO item14();
  //TODO item15();
  //TODO item16();
  //TODO item17();

////////// Chapter Four: Smart pointers //////////

  /*
    C++11����������ָ�룺 
    - auto_ptr
      * Deprecated leftover from C++98. unique_ptr��ǰ��
    - unique_ptr
      * Ĭ������¿�����Ϊ��ԭʼָ���С��ͬ�������ڶ��ڴ�ʹ�������Ƶĳ�����
        Ĭ����delete������Զ�����deleter���ڴ����Ļ����ӡ�
        ���ӵĴ�С��deleter�������ڲ�״̬���ٶ�����
        û��capture��lambda�������û���ڲ�״̬�ĺ���Ҫ��ʡ�ռ䡣
      * �ǿյ�unique_ptr��ӵ�С���ָ��Ķ���
      * move��ʱ��ѡ�ӵ��Ȩ��ת�ø���һ��ָ�룬���Լ���Ϊnull��
      * copy������������ܻ��������unique_ptrͬʱӵ�ж��󣬰����Ե����������ָ��Ķ��϶���
      * ���ܰ�ԭʼָ��ֱ�Ӹ�ֵ��unique_ptr����Ϊ�޷�����ת����Ҫ��reset(new ...)����ӵ�й�ϵ
    - shared_ptr
      * ��ԭʼָ���������С������ԭʼָ��֮�⣬�����ڲ���ԭʼָ��ָ��control block
      ��control block�ṹ����reference count��
      * reference count�Ƕ�̬�����
      * Reference count�����Ӻͼ��ٲ�������ԭ�Ӳ�������Ժ�ʱ
    - weak_ptr
      * ����shared_ptr������û�С�ӵ�С��ĸ�����Լ���Լ��Ƿ�������ָ��
      * weak_ptr��shared_ptr�ߴ���ͬ

    ������make������make_unique/make_shared/allocate_shared
    allocate_shared����make_shared�Ĺ������⣬���һ������Ϊ���ڶ�̬�ڴ�����allocator����
    make_unique��C++14��ʼ���룬make_shared��C++11��ʼ����
  */
  //item18();
  //item19();
  //item20();
  //item21();
  //item22();

////////// Chapter Five: Rvalue References, Move Semantics, and Perfect Forwarding //////////

  /* Move semantics: makes it possible for compilers to replace expensive copying operations
        with less expensive moves.
        �������캯���Ϳ�����ֵ�������ڿ���copy
        �ƶ����캯�����ƶ���ֵ�������ڿ���move
        �����ƶ�����ʵ�ֵ�move-only type����unique_ptr��future��thread
     Perfect forwarding: make it possible to write function templates that take arbitrary
          arguments and forward them to other functions such that the target functions
          receive exactly the same arguments as were passed to the forwarding functions.
     rvalue��ֵ��ʵ�����������ܵĻ�����
   */
  RuleOfFive();
  //item23();
  //item24();
  item25();
  //TODO item26();
  //TODO item27();
  //TODO item28();
  //TODO item29();
  //TODO item30();


////////// Chapter Six: Lambda Expressions //////////

  /* Lambda Expression:
     [capture list](parameter list) mutable -> return type {function body}

     �ʺ���lambda�ĳ�����
     * STL��_if�㷨����find_if/remove_if/count_if
     * STL�ıȽϺ������㷨����sort/nth_element/lower_bound
     * STL֮�⣬ʹ��lambda����ʵ��unique_ptr��shared_ptr��deleter

     Closure��lambda����������ʱ����closure����capture���ݵĿ���
     Closure class��closureʵ����Ӧ���ࡣ������Ϊÿ��lambda����closure class��
        lambda���������������ĳ�Ա������
     ���԰�lambda��丳ֵ��auto���������auto������Ϊ��lambda��Ӧ��closure
     ͬʱ���Ը�ֵ��������auto��������ö��������
   */

  //item31();
  //item32();
  //TODO item33();
  //TODO item34();
  
////////// Chapter Seven: The Concurrency API //////////

  //TODO item35();
  //TODO item36();
  //TODO item37();
  //TODO item38();
  //TODO item39();
  //TODO item40();
  
////////// Chapter Eight: Tweaks //////////

//TODO item41();
//TODO item42();

  cout << endl;

  return 0;
}

