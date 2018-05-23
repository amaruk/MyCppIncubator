// EvolvingExamples.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "VariadicFunction.h"
#include <iostream>

using std::cout;
using std::endl;

int main()
{
  cout << "===== Evolving Examples =====" << endl;
  
  // 不同的可变参数函数实现方式
  VariFuncCImp(0, 123, std::string("Hello"));
  VariFuncInitList(std::initializer_list<std::string>{"one", "two", "three"}, 123456);
  VariFuncTemplate("StringForT", 1, 123.456, 'c', std::string("hello"));

  return 0;
}

