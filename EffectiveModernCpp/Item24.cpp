#include "stdafx.h"
#include "Chapter5.h"

using std::cout;
using std::endl;

void item24()
{
  cout << endl << "----- Item 24 -----" << endl;
  cout << ">> ..." << endl;

  // T&&不一定是右值引用，例如：
  // void f(Widget&& param)         // 右值引用
  // Widget&& var1 Widget();        // 右值引用
  // auto&& var2 = var1;            // auto声明，universal reference
  // template<typename T>
  // void f(std::vector<T>&& param);// 右值引用
  // template<typename T>
  // void f(T&& param);             // 作为函数的模板参数，universal reference

  // T&&可以绑定到右值（同右值引用），
  // 可以作为左值引用，
  // 可以绑定到const或non-const
  // 可以绑定到volatile或non-volatile
  // 几乎可以绑定所有对象。可以成为universal reference或forwarding reference
  // 两种情况下T&&为universal reference：auto声明或作为函数的模板参数
  // 原因是type deduction
}
