#include "stdafx.h"
#include "Item23.h"
#include <memory>
#include <functional>

using std::make_unique;
using std::bind;

Item23::Item23() :
  ItemBase("23")
{
}


Item23::~Item23()
{
}


void Item23::ItemEntry()
{
  // std::move�������Ѳ���ת��Ϊrvalue
  // std::forward�Ĳ����������rvalue��ʼ���ģ���Ѳ���ת��Ϊrvalue��

  // ע��std::moveֻ����ת��Ϊrvalue��������֤move
  // ���const�Ķ������std::move����Ȼ���ú�ȷʵ�õ�rvalue��
  // ������const��Ȼ���ڣ���rvalueִ�е�move������ĬĬ��תΪcopy������
  // ��std::move���ص�const rvalue���ݸ����캯�������������ƶ����캯����
  // ���ƶ����캯����������const��rvalue�����ջ���ÿ������캯����

  // forward��Ҫ���ڣ���ȡ��ǰ������ʵ�ε�rvalue/lvalue���ͣ�
  // �������ʹ����ڵ�ǰ������Ҫ���õĺ���
}
