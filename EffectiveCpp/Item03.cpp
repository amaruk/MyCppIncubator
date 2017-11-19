#include "stdafx.h"
#include "Item03.h"
#include <vector>

Item03::Item03()
{
}


Item03::~Item03()
{
}


void ExampleItem03()
{
  // Item 3: Use const whenever possible 

  cout << "===== Example Item 03 =====" << endl;

  char greeting[] = "hello";

  ///// ����ָ�룬const���Ǻ���߱�ʾָ���Ϊconst�����Ǻ��ұ߱�ʾָ��������const
  // const char * �� char const *������ͬ
        char*       p  = greeting; // non-const data, non-const pointer
  const char*       p1 = greeting; //     const data, non-const pointer
        char* const p2 = greeting; // non-const data,     const pointer
  const char* const p3 = greeting; //     const data,     const pointer

  ///// Iterator����Ϊ������T*ָ�룬������const����ʽ���в�ͬ
  std::vector<int> intVec = { 1,2,3,4,5,6 };
  const std::vector<int>::iterator iter = intVec.begin(); // ע�⣬����const��λ�ú�ָ���const�÷���һ��
                                                          // �����൱��T* const����ʾiterator����Ϊ����
  *iter = 10;
  //++iter; // �����޸�iter����
  std::vector<int>::const_iterator cIter = intVec.begin(); // const_iterator��ʾiteratorָ���ֵΪconst
  //*cIter = 10; // �����޸�ָ���ֵ
  ++cIter;

  ///// const��Ա������ʾ��Щ�������ı�������ķ�static��Ա����Щ����������const�����ϱ�����
  // ��������ͬ�����
  // bitwise constness�����physical constness����const��Ա�������ı�ö���ķ�static��Ա��
  //    ��������������������Ա������ָ�룬��const��Ա�������غͳ�Ա������ص�ָ�룬����ϴ˸���������߿�������ָ���޸ĳ�Ա����
  // logical constness������������������ڵ������£�const��Ա����Ӧ��Ҳ����ı��Ա��ֵ���������ڲ��ܱ������߲��������¸ı䡣
  //    ʹ��mutable���γ�Ա������const��Ա����Ҳ���Ըı��Ա��ֵ��

  ///// ���const�汾��Ա������non-const�汾��Ա����������ͬ��Ϊ�˱���������࣬������non-const�汾�����const�汾
  // ����static_cast<const T&>(*this)��non-const��thisǿתΪconst��Ȼ������const_cast<T&>��const�汾����ֵ��const�޶�ȥ��
}
