#include "stdafx.h"
#include "Chapter5.h"
#include <vector>
#include <string>

using std::cout;
using std::endl;
using std::vector;
using std::string;

void item25()
{
  cout << endl << "----- Item 25 -----" << endl;
  cout << ">> ..." << endl;

  // ��ת����������ʹ��֮ǰ��
  // ���Ҫ����ֵ���ã���move��������תΪ��ֵ��ʵ���ƶ�
  // ���Ҫ��universial reference����Ϊ��һ��Ϊ��ֵ���û�����ֵ���ã���forward�����ݳ�ʼ���������ת��ֵ����ֵ��ʹ��

  // ����RVO��Return Value Optimization���Ĵ��ڣ���Ҫmove��forward������RVO�ľֲ�����
  // RVO����Ҫ���ؾֲ�����������£�Ϊ���⿽������������Ҫ���صı���ֱ�����ɵ����ڷ��ص��ڴ�λ��
  // NRVO (Named Return Value Optimization) ����δ�����ľֲ�����

}