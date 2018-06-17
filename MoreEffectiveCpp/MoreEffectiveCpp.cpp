#include "stdafx.h"
#include "Chapter01.h"
#include "Chapter02.h"


int main()
{
  ////////// Chapter One: Basics //////////
  //Item01().ItemEntry();
  //Item02().ItemEntry();
  //Item03().ItemEntry();
  //Item04().ItemEntry();

  ////////// Chapter Two: Operators //////////
  //// 可以重载的操作符
  // operator new         operator delete
  // operator new[]       operator delete[]
  // +    -     *     /     %     ^       &       |       ~
  // !    =     <     >     +=    -=      *=      /=      %=
  // ^=   &=    |=    <<    >>    <<=     >>=     ==      !=
  // <=   >=    &&    ||    ++    --      ,       ->*     ->
  // ()   []
  //// 不可以重载的操作符
  // .            .*              ::            ?:
  // new operator delete operator sizeof        typeid
  // static_cast  dynamic_cast    const_cast    reinterpret_cast
  // （关于new operator和operator new的区别见Item08）

  //Item05().ItemEntry();
  //Item06().ItemEntry();
  //Item07().ItemEntry();
  Item08().ItemEntry();



  return 0;
}

