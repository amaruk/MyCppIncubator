#include "stdafx.h"
#include "Item04.h"


Item04::Item04()
{
}


Item04::~Item04()
{
}

void ExampleItem04()
{
  // Item 4: Make sure that objects are initialized before they're used
  cout << "===== Example Item 04 =====" << endl;

  // ����Ĺ��캯��member initialization list���ʼ����Ա��
  // �ڹ��캯���ڲ��Գ�Ա�����Ǹ�ֵ���ڳ�ʼ���б����ǳ�ʼ����
  // ��ʼ���б�Ч�ʸߡ�
  // const�����ó�Ա�����ڳ�ʼ���б����ʼ������Ϊ�䲻���ڹ��캯���ڲ���ֵ
  // �������������ʼ������Ա�����������Ⱥ�˳���ʼ������ʹ�ڹ��캯���ĳ�ʼ���б���˳��ͬ��

  // ע�⣺the relative order of initialization of non-local static objects defined in different translation units is undefined.
  // �⼴�Ǿֲ���static�����ڲ�ͬ���ļ������뵥Ԫ����֣����ʼ���ں�ʱ�����δ����ġ�
  // �������Ϊʹ�õ���ģʽ
}
