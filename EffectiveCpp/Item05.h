#pragma once

#include "ItemBase.h"


class Item05 : public ItemBase
{
public:
  Item05();
  ~Item05();

  void ItemEntry() override;
};

// ����һ���յ���
#if 0
class Item05Example {};
#endif

// �൱���ñ�����������Ҫ��������Ĭ�ϵĳ�Ա������
class Item05Example
{
public:
  Item05Example() {} // Ĭ�Ϲ��캯��������� Item05 item; ����
  Item05Example(const Item05Example& rhs) {} // Ĭ�Ͽ������캯��������� Item05 anoItem(item); ����
  ~Item05Example() {} // Ĭ����������������� Item05 item; ����
  Item05Example& operator=(const Item05Example& rhs) {} // ������ֵ������������ anoItem = item; ����
};

// Ĭ�ϵ�ʵ�ֵ��û���Ĺ��캯������������������������Ǿ�̬���ݳ�Ա
// ע�⣺Ĭ�ϵ�����������virtual�������������virtual����������
// Ĭ�ϵĿ������캯���Ϳ�����ֵ�����������򵥵ؿ����Ǿ�̬��Ա��

// һ���������Զ��幹�캯�����������Ͳ�������Ĭ�Ϲ��캯��
// ��ʹ�������Զ��幹�캯�����ڲ������������캯���Ϳ�����ֵ�����ʱ�����������ǻ᳢������Ĭ�ϰ汾��
// ����������޷�����Ĭ�ϰ汾�����޷�����const��Ա���޷��������ó�Ա����������������

