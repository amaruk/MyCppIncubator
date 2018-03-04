#include "stdafx.h"
#include "Chapter01.h"
#include "Chapter03.h"
#include "Chapter04.h"
#include "Chapter05.h"
#include "Chapter06.h"


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
  //Item01().ItemEntry();
  //Item02().ItemEntry();
  //Item03().ItemEntry();
  //TODO Item04().ItemEntry();
  
////////// Chapter Two: auto //////////
  //TODO Item05().ItemEntry();
  //TODO Item06().ItemEntry();

////////// Chapter Three: Moving to Modern C++ //////////
  //TODO Item07().ItemEntry();
  //TODO Item08().ItemEntry();
  //Item09().ItemEntry();
  //TODO Item10().ItemEntry();
  //TODO Item11().ItemEntry();
  //TODO Item12().ItemEntry();
  //TODO Item13().ItemEntry();
  //TODO Item14().ItemEntry();
  //TODO Item15().ItemEntry();
  //TODO Item16().ItemEntry();
  //TODO Item17().ItemEntry();

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
  //Item18().ItemEntry();
  //Item19().ItemEntry();
  //Item20().ItemEntry();
  //Item21().ItemEntry();
  //Item22().ItemEntry();

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
  //RuleOfFive();
  //Item23().ItemEntry();
  //Item24().ItemEntry();
  //Item25().ItemEntry();
  //TODO Item26().ItemEntry();
  //TODO Item27().ItemEntry();
  //TODO Item28().ItemEntry();
  //TODO Item29().ItemEntry();
  //TODO Item30().ItemEntry();


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

  //Item31().ItemEntry();
  //Item32().ItemEntry();
  //TODO Item33().ItemEntry();
  //TODO Item34().ItemEntry();
  
////////// Chapter Seven: The Concurrency API //////////

  //TODO Item35().ItemEntry();
  //TODO Item36().ItemEntry();
  //TODO Item37().ItemEntry();
  //TODO Item38().ItemEntry();
  //TODO Item39().ItemEntry();
  //TODO Item40().ItemEntry();
  
////////// Chapter Eight: Tweaks //////////

  //TODO Item41().ItemEntry();
  //TODO Item42().ItemEntry();

  return 0;
}

