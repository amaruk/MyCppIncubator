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

  // std::move无条件把参数转换为rvalue
  // std::forward的参数如果是用rvalue初始化的，则把参数转换为rvalue：

  // 注意std::move只负责转换为rvalue，并不保证move
  // 如对const的对象调用std::move，虽然调用后确实得到rvalue，
  // 但由于const依然存在，对rvalue执行的move操作会默默地转为copy操作。
  // 把std::move返回的const rvalue传递给构造函数，期望调用移动构造函数，
  // 但移动构造函数并不接受const的rvalue，最终会调用拷贝构造函数。

  // forward主要用于：获取当前函数的实参的rvalue/lvalue类型，
  // 保持类型传给在当前函数中要调用的函数
}
