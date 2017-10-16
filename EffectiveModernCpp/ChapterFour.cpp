#include "stdafx.h"
#include <iostream>
#include "Item18.h"
#include "Item19.h"
#include "Item20.h"
#include "Item21.h"
#include "Item22.h"
#include "MemLeakCheck.h"

using std::cout;
using std::endl;

void ChapterFour(void)
{
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
  cout << "##### Chapter Four #####" << endl;
  
  //item18();
  //item19();
  //item20();
  //item21();
  item22();

  // Example of using weak_ptr to do memory leaking checking.
  //memLeakTest();
}

