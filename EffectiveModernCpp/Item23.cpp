#include "stdafx.h"
#include "Chapter5.h"
#include <memory>
#include <vector>
#include <functional>

using std::cout;
using std::endl;
using std::make_unique;
using std::vector;
using std::bind;

void item23()
{
  cout << endl << "----- Item 23 -----" << endl;
  cout << ">> ..." << endl;

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
