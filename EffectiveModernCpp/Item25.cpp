#include "stdafx.h"
#include "Item25.h"

Item25::Item25() :
  ItemBase("25")
{
}


Item25::~Item25()
{
}


void Item25::ItemEntry()
{
  // ��ת����������ʹ��֮ǰ��
  // ���Ҫ����ֵ���ã���move��������תΪ��ֵ��ʵ���ƶ�
  // ���Ҫ��universial reference����Ϊ��һ��Ϊ��ֵ���û�����ֵ���ã���forward�����ݳ�ʼ���������ת��ֵ����ֵ��ʹ��

  // ����RVO��Return Value Optimization���Ĵ��ڣ���Ҫmove��forward������RVO�ľֲ�����
  // RVO����Ҫ���ؾֲ�����������£�Ϊ���⿽������������Ҫ���صı���ֱ�����ɵ����ڷ��ص��ڴ�λ��
  // NRVO (Named Return Value Optimization) ����δ�����ľֲ�����

}
