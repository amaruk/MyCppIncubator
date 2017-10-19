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

  // 在转给其他函数使用之前，
  // 如果要传右值引用，用move来无条件转为右值以实现移动
  // 如果要传universial reference，因为不一定为左值引用还是右值引用，用forward来根据初始化的情况来转右值或左值再使用

  // 由于RVO（Return Value Optimization）的存在，不要move或forward会用作RVO的局部变量

}