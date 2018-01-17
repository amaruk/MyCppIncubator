#include "stdafx.h"
#include "Item19.h"


Item19::Item19() :
  ItemBase("19")
{
}


Item19::~Item19()
{
}

void Item19::ItemEntry()
{
  //// Item 19: Treat class design as type design
  // ����һ���µ�����Ƕ���һ�������ͣ�����������ʱ��
  // Ҫ����Ʊ�����ԵĿ���������ڽ�����һ��С�ġ�

  // ���һ����ʱ�������������⣺
  // 1. How should objects of your new type be created and destoyed?
  //    Ӱ�쵽���캯���������������ڴ������ͷ�(new, new[], delete, delete[])
  // 2. How should object initialization differ from object assignment?
  //    ���캯���͸�ֵ�������Ĳ�ͬʵ��
  // 3. What does it mean for objects of your new type to be passed by value?
  //    �������캯������������������pass-by-valueʱ����Ϊ
  // 4. What are the restrictions on legal values for your new type?
  //    ���Ա�Ϸ�ֵ������Ӱ�����ڲ��Ĳ�ͬ��֧�߼������캯������ֵ��������setter�����������׳����쳣��
  // 5. Does your new type fit into an inheritance graph?
  //    �����̳����е��࣬���ܻ�����麯���ͷ��麯�������ƣ�����������ͷ��鶨�壬��Ӱ�쵽��������
  // 6. What kind of type conversions are allowed for your new type?
  //    �Ƿ�������ʽ����ʽ����ת��
  // 7. What operators and functions make sense for the new type?
  //    �������������ڲ����ⲿ��
  // 8. What standard functions should be disallowed?
  //    �漰��Ӧ�ö�����private��ĺ���
  // 9. Who should have access to the members of your new type?
  //    Ӱ���Ա��public/protected/private����Ԫ�����Ԫ�������ڲ�Ƕ����
  //10. What is the "undeclared interface" of your new type?
  //    ������ܵ�Ӱ�죬�Ƿ��쳣��ȫ����Դ������
  //11. How general is your new type?
  //    �����Ҫ����ܶ��࣬�ǲ�������ģ��
  //12. Is a new type really what you need?
  //    �������������ֻ��Ϊ�˸��������һЩ���ܣ��ǲ��ǿ��Զ���һЩ�ǳ�Ա������ģ����ʵ��

}
