#include "stdafx.h"
#include "Item39.h"


Item39::Item39() :
  ItemBase("39")
{
}


Item39::~Item39()
{
}

void Item39::ItemEntry()
{
  //// Item 39: Use private inheritance judiciously
  // ˽�м̳�ʱ������������������ת��Ϊ������󣬲�������������������public������
  // ˽�м̳�ʱ���ӻ���̳еĳ�Ա��Ϊ�������˽�г�Ա��
  // ˽�м̳еĹ�ϵ��is-implemented-in-terms-of��������Ϊ�����ϵĹ�ϵ���̳У�������ʹ�û����ĳЩ���ܡ�
  // ���Ի������еĹ�����Ϊ�����ڲ��Ĺ��ܱ��̳У��ӿڱ����ԡ�
  // ˽�м̳���implementationʱ�����ģ�����designʱ��
  // ��ΪcompositionҲ������is-implemented-in-terms-of�����壬���Ծ�����composition��ʵ����Ҫ��˽�м̳�
  // 
}
