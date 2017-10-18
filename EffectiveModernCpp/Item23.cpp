#include "stdafx.h"
#include "Item23.h"
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
  // std::forward有条件把参数转换为rvalue
}
