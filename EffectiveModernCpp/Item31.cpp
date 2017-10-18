#include "stdafx.h"
#include "Item31.h"

using std::cout;
using std::endl;

void item31()
{
  cout << endl << "----- Item 31 -----" << endl;
  cout << ">> ..." << endl;

  // LambdaĬ�ϲ���ģʽΪ���ò���(by-reference)��ֵ����(by-value)

  {
    int i = 123;
    int j = 456;
    int divisor = i / j;

    // ʹ��Ĭ�ϵ����ò��񣬲���ֲ�����divisor�������lambda���󱻱��浽��ǰ����������
    // �ı����У��ٴ������������ʱ��divisor��Ϊdangle������
    auto lambdaMayDangle = [&](int value) { return value % divisor == 0; };

    // �Ժ�һЩ��д������ʾָ��divisor�ֲ����������ò���ģ���һ������������
    // ���ڿ�������lambda����ʹ��ʱ����Ȼ��dangle������
    auto lambdaStillMayDangle = [&divisor](int value) { return value % divisor == 0; };

    // ֵ��������һ������
    // �����ֵ�������ָ�룬ָ��ָ������ݿ�����ĳ�����ͷţ�����lambda���ָ��dangle
    auto lambdaAgainDangle = [=](int value) { return value % divisor == 0; };

    // ֵ�����Ա����ʱ�ǲ����this->��Ա����������thisҲ����������lambda
    // ���this��Ӧ�Ķ��������ˣ�lambda���this��Ϊdangle
    // �����������ʾ�ش����ֲ�������������Ա������Ȼ�����ô˾ֲ���������ֵ����
    // C++14�ṩ��generalized lambda capture�����£���֤�ѳ�Ա����ֵ�����lambda������this
    // ����ο�Item32
    auto lambdaCpp14 = [divisor = divisor](int value) { return value % divisor == 0; };

    // ע�����divisor������������static�ģ���ô��ʵ��û��ֵ����divisor��
    // ���������÷�ʽ���������ò��񣡣���ʹ��static��divisor��
    // ��������µ�lambda������self-contained�ġ�
  }
}
