#include "stdafx.h"
#include "Item29.h"


Item29::Item29() :
  ItemBase("29")
{
}


Item29::~Item29()
{
}

void Item29::ItemEntry()
{
  //// Item 29: Strive for exception-safe code.
  // �쳣�׳���ʱ��exception-safe�ĺ���Ӧ�ã�
  // 1. Leak no resources. ���������쳣�׳����޷�ִ��delete��������Դ����䡣
  // 2. Don't allow data structures to become corrupted. ���������׳��쳣���ǳ�Ա������ֵ���ڷǷ�״̬��
  // Exception-safe�����ṩ��������ı��ϣ�����������𶼲����ϣ��Ͳ���exception-safe��
  // 1. The basic guarantee�������ڲ�������Ȼ��ȷ��һ�£����û��޷������쳣���������Ϊ�˱�֤����һ��������ȡ����Ϊ������������Ĭ��ֵ������һ�ο��õ�ֵ��
  // 2. The strong guarantee���쳣�����ǳ����ڲ�״̬���䡣��ԭ�Ӳ����������쳣�����ɹ�ʱ���ı��κ�״̬��
  // 3. The nothrow guarantee����֤��ȷִ�в��������׳��쳣��
  // ʵ��strong guarantee�Ľ������ͨ��Ϊcopy and swap�����ȿ���һ����Ҫ�ı�Ķ��󣬸ı俽���õ��Ķ�������ɹ�����swap�ı��Ŀ��������ԭ����
  // ʵ����������pimpl idiom����ʵ�����ݵ�������һ�����Ҫ���޸ĵ�����ָ���Ա����ָ��ʵ�������ࡣ�޸Ķ����ʱ���ȿ���һ�����ݶ��󣬵õ���ָ�룬�޸���ֵ���ԭָ�뽻��ָ��ֵ��
  // ���copy�Ŀ����ܴ�ʱ��Ҫ��copy-and-swap����strong guarantee���ܲ���ʵ�ʡ�
}