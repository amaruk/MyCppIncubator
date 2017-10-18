#include "stdafx.h"
#include "Item31.h"
#include <memory>
#include <vector>
#include <functional>

using std::cout;
using std::endl;
using std::make_unique;
using std::vector;
using std::bind;

void Item32()
{
  cout << endl << "----- Item 32 -----" << endl;
  cout << ">> ..." << endl;

  // C++11��֧�ְѶ���move��closure��C++14�ṩinit capture��֧��move�������¹��ܣ�
  // Ҳ����generalized lambda capture����ΪC++11��capture��generalizedģʽ��
  // ʹ��init capture����ָ����
  // * The name of a data member in the closure class generated from the lambda and
  // * an expression initializing that data member.

  auto pUnqInt = make_unique<int>(123);
  auto lambdaInitCap = [pUnqInt = std::move(pUnqInt)]{ return *pUnqInt; };
  // �Ⱥ���ߵ�pUnqInt������Ϊclosure���ڲ����Ⱥ��ұߵ�pUnqInt������Ϊ����lambda���ʽ���������������
  // �Ⱥ���ߵ�pUnqInt��Ϊclosure class��data member

  // Ҳ����ֱ����make_unique����Ϊan expression initializing that data member
  auto lambdaInitCap2 = [pUnqInt = std::make_unique<int>(321)]{ return *pUnqInt; };

  // C++11������Լ�ʵ�ֺ�lambda��closure classԭ��һ�����ࣨ������飩��
  // ����bindģ��
  vector<int> data{ 1,2,3 };
  // C++14
  auto lambdaInitCapVec = [data = std::move(data)]{};
  // C++11
  auto bindVec = bind(
    [](const std::vector<int>& data){},
    std::move(data)
  );  

  // C++11��ģ��make_unique



}
