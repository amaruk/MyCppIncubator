#include "stdafx.h"
#include "Item05.h"

Item05::Item05() :
  ItemBase("05")
{
}


Item05::~Item05()
{
}

namespace ITEM05
{
  class MyInteger
  {
  public:
    // ͨ�����캯��֧����ʽ����ת��
    MyInteger(int intVal) : m_val(intVal) {};
    explicit MyInteger(string strVal) : m_val(65535) {};
    MyInteger(std::wstring wstrVal, int addition = 1) : m_val(32767 + addition) {};

    void Display() { cout << "MyInteger: " << m_val << endl; }

    int m_val{ 0 };
  };

  class MyNotInteger
  {
  public:
    MyNotInteger(int intVal) : m_val(intVal) {};

    // ��ʽ����ת���������� operator Ҫת��������() {}
    operator MyInteger()
    {
      MyInteger myInteger{0};
      myInteger.m_val = this->m_val;
      return myInteger;
    }

    int m_val{ 0 };
  };
}

using namespace ITEM05;

void Item05::ItemEntry()
{
  // Item05: Be wary of user-defined conversion functions.
  // �Զ���������Ҫ�ñ�����֧����ʽ����ת�������ַ�ʽ��
  // 1. ��������ֻ�ṩ�������������õĹ��캯��
  // 2. ������ʽ����ת��������

  MyInteger myIntegerCtorInt = 123 ;
  myIntegerCtorInt.Display();

  MyInteger myIntegerCtorDouble = 654.321;
  myIntegerCtorDouble.Display();

  // Explicit��ֹ��ʽ����ת��
  //MyInteger myIntegerCtorStringFail = string("anything");
  //MyInteger myIntegerCtorStringFail = "anything";
  // ����ʾ���ù��캯��ʱ����������ʽת��
  MyInteger myIntegerCtorStringOk{ "anything" };
  myIntegerCtorStringOk.Display();

  MyInteger myIntegerCtorWstring = std::wstring(L"ANYTHING");
  myIntegerCtorWstring.Display();

  MyNotInteger myNotInteger{ 135 };
  MyInteger myInteger = myNotInteger;
  myInteger.Display();

  // ���ڱ���������ƥ�����ʱ�᳢�Ը��ֿ��ܵ���ʽ����ת����
  // ����Զ�����ʽ����ת����û�����ر�Ҫ�Ĳ�����������������������ʵ���ʽ����ת����Ȼ��ִ�в�����������ֱ�ӱ���
  // ������Ҫʵ����ʽ����ת�������������ṩ��ʽ����ת�����������׼���stringתC���͵�char*����Ҫ��ʽ�ص���c_str������
  // ���⹹�캯����Ϊ��ʽ����ת����explicit�ؼ��֡�
}
