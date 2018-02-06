#include "stdafx.h"
#include "Item54.h"


Item54::Item54() :
  ItemBase("54")
{
}


Item54::~Item54()
{
}

void Item54::ItemEntry()
{
  //// Item 54: Familiarize yourself with the standard library, including TR1
  // TR1 (Technical Report 1)����C++ library working group.
  // C++��׼ίԱ���ڰ�TR1�Ĺ��������׼֮ǰ���������޸ĵ�Ȩ����
  // ��һ���׼ISO/IEC 14882:1998��ͨ��C++98
  // �ڶ����׼ISO/IEC 14882:2003��ͨ��C++03
  // C++11����ǰ������C++0x����ISO/IEC 14882:2011

  // C++98��׼�����ɣ�
  // 1. STL (Standard Template Library)������container��vector��string��map�ȣ���
  //    iterator��algorithm��find��sort��Transform�ȣ���function obejct��less��greater���ȣ���
  //    container��function object adapter��stack��priority_queue��mem_fun��not1���ȣ�
  // 2. Iostreams��Ҳ֧���û��Զ����buffering��internationalized IO��Ԥ�����cin��cout��cerr��clog��
  // 3. Internationalization��֧�ֶ��active locales��unicode��wchar_t��wstring��
  // 4. Numeric processing��complex number��ģ�壨complex����pure value�����飨valarray����
  // 5. �쳣�̳н⹹��exception���࣬logic_error��runtime_error������ȡ�
  // 6. C89�ı�׼�⣺C++����C89��׼��

  // TR1������14��ܿ⣬λ��std::tr1��namespace�¡�
  // 1. Smart pointer
  // 2. function
  // 3. bind
  // 4. Hash table
  // 5. Regular expression
  // 6. Tuple
  // 7. array
  // 8. mem_fn
  // 9. reference_wrapper
  // 10. Random number generation
  // 11. Mathematical special functions
  // 12. C99 compatibility extensions
  // 13. Type trait
  // 14. result_of
}