#include "stdafx.h"
#include "Item47.h"


Item47::Item47() :
  ItemBase("47")
{
}


Item47::~Item47()
{
}

namespace ITEM47
{
  template<typename Obj>
  struct MyTrait // ͨ����structʵ�֣���Ϊtrait class
  {};
}

void Item47::ItemEntry()
{
  //// Item 47: Use traits classes for information about types
  // Iterator���������ͣ�
  // - Input iterator��ֻ����ǰ�ƶ���ÿ���ƶ�һ����ֻ�ܶ�ȡָ������ݣ�ֻ�ܶ�һ�Ρ����ȡ�����istream_iterator��
  // - Output iterator������input�����������
  // - Forward iterator������input��output�Ĺ��ܣ������Զ���д��Ρ���hash����
  // - Bidirectional iterator������˫���ƶ�����list��set��map
  // - Random access iterator������������ʱ���������ʱ���һ�ζಽ��Ծ�����ڽ�ָ��ʵ�֡���vector��deque��string

  // trait���ڱ�������ȡ����������Ϣ�ļ���
  // ��ΪҪ�����������ͣ����Բ���������ע����Ϣ��ֻ����ģ��ʵ��
  // �����صĺ������滻����ʱ��if else�жϣ����б���ʱ���������͵Ĳ�ͬ����

}
