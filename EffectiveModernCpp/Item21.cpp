#include "stdafx.h"
#include "Item21.h"
#include <vector>
#include <memory>
#include "ClassHierarchy.h"

using std::cout;
using std::endl;
using std::unique_ptr;
using std::make_unique;
using std::shared_ptr;
using std::make_shared;
using std::vector;

int prepSth(void)
{ return 0; }

void doSth(shared_ptr<ClassBase> pSrd, int prepSthResult)
{ }


Item21::Item21() :
  ItemBase("21")
{
}


Item21::~Item21()
{
}


void Item21::ItemEntry()
{
  //////// ������ʹ��make_xxx��3��ԭ��

  // 1. ʹ��make_xxxֻдһ��ClassBase���������ٴ����ڵ��ظ���
  auto pMakeUnq(make_unique<ClassBase>());
  unique_ptr<ClassBase> pNewUnq(new ClassBase);
  auto pMakeSrd(make_shared<ClassBase>());
  shared_ptr<ClassBase> pNewSrd(new ClassBase);

  // 2. Exception safety
  // ����������������������

  // ��newʱ����Ǳ�ڵ�й©����
  doSth(shared_ptr<ClassBase>(new ClassBase), prepSth());
  // �ڽ���doSth����֮ǰ��Ҫ��������£�
  // a. �ڶ��ϴ���ClassBaseʵ��
  // b. ����shared_ptr���캯����������ָ��ѵ�ԭʼָ��
  // c. ����prepSth�õ��ڶ���������ʵ��ֵ
  // �������������ɾ��������������ִ��˳�򣨵�Ȼnew������shared_ptr���캯��֮ǰִ�У�
  // ���ִ��˳��Ϊa->c->b������cִ��ʱ�����쳣��b�����޷���ִ�е���
  // ���¶��ϴ�����ʵ����û�б�����ָ�����������й©

  // �����make_xxx
  doSth(make_shared<ClassBase>(), prepSth());
  // ֮ǰ�Ĳ���1��2���ϲ�Ϊһ�����Ͳ��õ���prepSeh��������쳣����й©
  // ���������ǳ��󣬶�����weak_ptrָ��ʱ�������make_shared����shared_ptr��
  // ��ʹ����shared_ptr���������Ѿ���ᣬ������weak_ptr����ʱ��
  // ������ռ�Ŀռ�Ҳ���ᱻ�ͷš�
  // �����������new�ķ�ʽ��������shared_ptr�����ͷŶ���Ŀռ䣬ֻҪע��
  // ��Ҫ���������һ�����Ѵ�new���󴴽�shared_ptr�������������Ƹ����õ�����
  // �������õ�������䴴����shared_ptr���ٰѴ����õ�shared_ptr��Ϊ�������ݡ�

  // 3. Ч�ʸ���
  // ��make_xxx������£�make_xxx�ڲ�һ����Ϊ�����control block������Ͽռ�
  auto pHighEff = make_shared<ClassBase>();
  // ��newΪ����������£�new����ڶ��Ϸ������Ŀռ䣬
  // ��shared_ptr���캯����Ϊcontrol block����ռ䣬
  // �ܹ����οռ���䡣
  // ʹ��allocate_sharedЧ�ʺ�make_shared��ͬ��
  shared_ptr<ClassBase> pLowEff(new ClassBase);

  //////// ����ʹ��make_xxx�ĳ���
  // unique��2����shared��4��

  // 1. make_unique��make_shared��֧���Զ���deleter
  // 2. make_unique��make_sharedֻ֧��Բ���Ź������
  auto pConstParam = make_shared<vector<int>>(10, 20);
  // �൱�ڴ���10��Ԫ�ص�vector��Ԫ��ֵ��Ϊ20
  // �����Ǵ�������Ԫ�ص�vector����һ����10���ڶ�����20

  // ��������ֻ���shared_ptr
  // 3. �Զ�������new��deleteʱ�����ܺ�std::allocate_share��deleter�����䡣
  //    һ���Զ���new��deleteʱ��������ڴ�Ϊ����Ĵ�С�������Ƕ���+control block���ܴ�С
  // 4. ���������ߴ�������г��������ڵ�weak_ptrʱ����make_shared���ܼ�ʱ�ͷ�
  //    ����Ŀռ䡣Ҫ����new����������ע�����exception unsafe�������
}
