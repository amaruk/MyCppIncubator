#include "stdafx.h"
#include "Item49.h"


Item49::Item49() :
  ItemBase("49")
{
}


Item49::~Item49()
{
}



namespace ITEM49
{
  void OutOfMen()
  {
    cout << "new failed." << endl;
  }
}

void Item49::ItemEntry()
{
  //// Item 49: Understand the behavior of the new-handler
  // new�����ڴ�����ʧ��ʱ���׳��쳣�������Զ���new-handler������
  // new�ᷴ������new-handler�Գ��Ի�ȡ�ڴ档����new-handler����ѡ�����·�ʽ��һ�֣�
  // 1. �ҵ����õ��ڴ�
  // 2. �����ǰhandler�޷��ҵ����õ��ڴ棬���Գ���set_new_handler�ñ��handler�����ԡ�
  // 3. �������nullΪhandler����new���׳��쳣
  // 4. ��handler�׳��쳣����bad_alloc���������쳣�࣬new����catch�����������׳�
  // 5. �����أ�ֱ�ӵ���abort��exit
  // ��CRTP��curiously recurring template pattern)��Ϊ��ʵ���Զ����new��new-handler���๦�ܡ�

  // �����µ�new��ʹ�ò��׳��쳣���Ƿ���null��new��
  // Widget *pw2 =new (std::nothrow) Widget;
  // ��ע��ֻ��֤new�������׳��쳣��Widget�Ĺ��캯�����ܵ�����ͨ��new��ʧ�ܶ��׳��쳣

  std::set_new_handler(ITEM49::OutOfMen);
  int* pBigData = new int[0x7fffffff];
  int* pBigData1 = new int[0x7fffffff];
  int* pBigData2 = new int[0x7fffffff];
  int* pBigData3 = new int[0x7fffffff];
  int* pBigData4 = new int[0x7fffffff];
  int* pBigData5 = new int[0x7fffffff];
  delete pBigData;
  delete pBigData1;
  delete pBigData2;
  delete pBigData3;
  delete pBigData4;
  delete pBigData5;
}