#include "stdafx.h"
#include "Item52.h"


Item52::Item52() :
  ItemBase("52")
{
}


Item52::~Item52()
{
}

void Item52::ItemEntry()
{
  //// Item 52: Write placement delete if you write placement new
  // ���ճ���size_t֮�������new����Ϊplacement version of new
  // newһ�����ʱ�����ȷ����ڴ�ռ䣬���ŵ�����Ĺ��캯����
  // Widget *pw = new Widget;
  // ��������캯���׳��쳣������ҪC++����ʱ�������񲢵���new��Ӧ��delete�������ڴ�й©��
  // ����ʱ�����ڴ���replacement of new�����ʱ������Ѱ�Һ�replacement of new����ͬ������replacement of delete.
  // ����Ҳ����򲻵����κ�delete����ʱ�����ڴ�й©��
  // ע��deleteʱ
  // delete pw; 
  // ����������ͨ��delete������replacement of delete�������ṩreplacement of newʱ��Ҫͬʱ�ṩ��ͨ��delete��replacement of delete.

  // �ڼ̳е�����£�ע���໥���ǵ�����
  // C++Ĭ����ȫ���ṩ��������new
  // void* operator new(std::size_t) throw(std::bad_alloc);      // normal new
  // void* operator new(std::size_t, void*) throw();             // placement new
  // void* operator new(std::size_t, const std::nothrow_t&) throw();  // nothrow new
  // �����ڲ������κ���ʽ��new���������������֡��������صĻ�Ҫ�����������ͬǩ���ĺ���������ȫ�ֵİ汾��
  // deleteͬ��






}