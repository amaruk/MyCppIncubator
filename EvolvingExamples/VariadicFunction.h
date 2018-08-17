#pragma once
#include <initializer_list>
#include <string>

void VariFuncCImp(int mandatoryArg, ...);
void VariFuncInitList(std::initializer_list<std::string> args, int extVal);

template <typename T>
void printarg(T t)
{
  std::cout << "- Arg:" << t << std::endl;
}

// Types是模板参数包template parameter packet，是类型的集合
// args是函数参数包function parameter packet，是参数的集合
template <typename T, typename... Types>
void VariFuncTemplate(const T &t, Types&&... args)
{
  size_t typeSize = sizeof...(Types);
  size_t argsSize = sizeof...(args);
  std::cout << "----- Variadic Function: Variadic Template -----" << std::endl;
  std::cout << "- Args contains " << argsSize << " values." << std::endl
    << "- rest contains " << argsSize << " values." << std::endl;
  // 利用数组的可变参数初始化来对每个参数调用打印函数，由于逗号表达式，数组最后成员都为0
  int arr[] = { (printarg(std::forward<Types>(args)), 0)... };
}

