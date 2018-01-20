#include "stdafx.h"
#include "Item25.h"


Item25::Item25() :
  ItemBase("25")
{
}


Item25::~Item25()
{
}

///////////////////////////////////////

namespace TestDefaultSwap
{
  class SwapTester
  {
  public:
    SwapTester(int& val) : m_ptr(&val) {};
    // ֧�ֿ�������Ϳ�����ֵ���࣬std::swap�Ϳ��Զ�����в���

    SwapTester& operator=(const SwapTester& rhs)
    {
      cout << "CopyOper" << endl;
      *(this->m_ptr) = *(rhs.m_ptr);
      return *this;
    }

  private:
    int* m_ptr{ nullptr }; // ����Ϊָ��������ݽṹ��ָ��
  };
}

///////////////////////////////////////

namespace TestExtendSwap
{
  class SwapTester
  {
  public:
    SwapTester(int& val) : m_ptr(&val) {};

    SwapTester& operator=(const SwapTester& rhs)
    {
      cout << "CopyOper" << endl;
      *(this->m_ptr) = *(rhs.m_ptr);
      return *this;
    }

    void swap(SwapTester& another) // ����swap����ʵ��ֻ����ָ��ֵ��pimpl
    {
      using std::swap;
      swap(this->m_ptr, another.m_ptr);
    }

  private:
    int* m_ptr{ nullptr };
  };
}

// ���ܸı�std��swapģ�庯����������ָ���Զ����ģ�庯��ʵ��
namespace std
{
  template<> // ��ָ��T��ʾ����ģ�庯����ʵ��
  void swap<TestExtendSwap::SwapTester>(TestExtendSwap::SwapTester& lhs, TestExtendSwap::SwapTester& rhs)
  {
    cout << "std::swap<TestExtendSwap::SwapTester>" << endl;
    lhs.swap(rhs); // ����ֱ�ӷ���˽�г�Ա��ʹ�����ṩswap����
  }
}

///////////////////////////////////////

namespace TestExtendTemplateSwap
{
  template <typename T> // ��Ϊģ����
  class SwapTester
  {
  public:
    SwapTester(int& val) : m_ptr(&val) {};

    SwapTester& operator=(const SwapTester& rhs)
    {
      cout << "CopyOper" << endl;
      *(this->m_ptr) = *(rhs.m_ptr);
      return *this;
    }

    void swap(SwapTester& another)
    {
      using std::swap;
      swap(this->m_ptr, another.m_ptr);
    }

  private:
    int* m_ptr{ nullptr };
  };

  // �������ռ��ڶ���ǳ�Ա������swap
  template<typename T>
  void swap(TestExtendTemplateSwap::SwapTester<T>& lhs, TestExtendTemplateSwap::SwapTester<T>& rhs)
  {
    cout << "TestExtendTemplateSwap::swap" << endl;
    lhs.swap(rhs);
  }
}

namespace std
{

#if ILLEGAL
  // ����ʵ����ģ�庯���Ƿ�
  template<typename T>
  void swap<TestExtendTemplateSwap::SwapTester<T>>(TestExtendTemplateSwap::SwapTester<T>& lhs, TestExtendTemplateSwap::SwapTester<T>& rhs)
  {
    cout << "std::swap<TestExtendSwap::SwapTester>" << endl;
    lhs.swap(rhs);
  }
#endif

#if NOTSUGGESTED
  // ����swap��������ʵ�������У�����������std�����ռ�����³�Ա
  template<typename T>
  void swap(TestExtendTemplateSwap::SwapTester<T>& lhs, TestExtendTemplateSwap::SwapTester<T>& rhs)
  {
    cout << "std::swap<TestExtendSwap::SwapTester>" << endl;
    lhs.swap(rhs);
  }
#endif
}


void Item25::ItemEntry()
{
  //// Item 25: Consider support for a non-throwing swap
  // ��ֱ�۵Ľ�������ֵ�ķ�����ʹ���м�����������θ�ֵ��

  // �����ָ�룬����ֻ����ָ��ֵ�������ǿ���ָ��ָ��Ķ���
  // pimpl idiom (Pointer to implementation)
  // ��ʱ���Դ���swapģ���ʵ��,�籾�ļ��еĴ���

  int value1 = 1;
  int value2 = 2;

  // ʹ��std��Ĭ��swap�����ÿ������캯���򿽱���ֵ������
  cout << endl << "==========Test Default Swap" << endl;
  TestDefaultSwap::SwapTester defaultTester1{value1};
  TestDefaultSwap::SwapTester defaultTester2{value2};
  cout << "----Gonna Swap" << endl;
  std::swap(defaultTester1, defaultTester2);

  // �Զ���std��swap��ģ�庯��ʵ��������
  cout << endl << "==========Test Extend Swap" << endl;
  TestExtendSwap::SwapTester extendTester1{ value1 };
  TestExtendSwap::SwapTester extendTester2{ value2 };
  cout << "----Gonna Swap" << endl;
  std::swap(extendTester1, extendTester2);
  

}

