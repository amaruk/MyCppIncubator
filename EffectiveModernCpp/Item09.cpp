#include "stdafx.h"
#include "Item09.h"
#include <memory>
#include <vector>
#include <list>
#include <functional>


Item09::Item09() :
  ItemBase("09")
{
}


Item09::~Item09()
{
}


// C++98���typedef
typedef std::unique_ptr<std::vector<std::string, std::string>> UPtrVecSS;
typedef void(*FuncPtr)(int, const std::string&);

// C++11���alias declaration
using UPtrVecSS = std::unique_ptr<std::vector<std::string, std::string>>;
using FuncPtr = void(*)(int, const std::string&);

// Alias���ŵ�Ϊ֧��ģ�壺alias template
template<typename T>
using MyAllocList = std::list<T>;


void Item09::ItemEntry()
{
  // Type trait: ��ͷ�ļ�<type_traits>�ﶨ���һ��ģ��
  // std::remove_const<T>::type           // ��const T����T
  // std::remove_reference<T>::type       // ��T&��T&&����T
  // std::add_lvalue_reference<T>::type   // ��T����T&
  // ��Щ��C++11��Ƕ�׵�typedef�����
  // C++14��alias template����ʵ��Ϊ��
  // std::remove_const_t<T>
  // std::remove_reference_t<T>
  // std::add_lvalue_reference_t<T>


}
