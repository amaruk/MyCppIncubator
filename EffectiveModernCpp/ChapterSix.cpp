#include "stdafx.h"
#include "Item31.h"
#include "Item32.h"


void ChapterSix(void)
{
  // Lambda Expression:
  // [capture list](parameter list) mutable -> return type {function body}

  // �ʺ���lambda�ĳ�����
  // * STL��_if�㷨����find_if/remove_if/count_if
  // * STL�ıȽϺ������㷨����sort/nth_element/lower_bound
  // * STL֮�⣬ʹ��lambda����ʵ��unique_ptr��shared_ptr��deleter

  // Closure��lambda����������ʱ����closure����capture���ݵĿ���
  // Closure class��closureʵ����Ӧ���ࡣ������Ϊÿ��lambda����closure class��
  //    lambda���������������ĳ�Ա������
  // ���԰�lambda��丳ֵ��auto���������auto������Ϊ��lambda��Ӧ��closure
  // ͬʱ���Ը�ֵ��������auto��������ö��������

  //Item31();
  Item32();
}