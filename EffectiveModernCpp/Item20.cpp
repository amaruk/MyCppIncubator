#include "stdafx.h"
#include "Item20.h"
#include <memory>

using std::cout;
using std::endl;
using std::shared_ptr;
using std::weak_ptr;
using std::make_shared;


Item20::Item20() :
  ItemBase("20")
{
}


Item20::~Item20()
{
}


void Item20::ItemEntry()
{
  cout << ">> Test weak_ptr expire" << endl;

  shared_ptr<int> sptr = make_shared<int>(123); // Reference countΪ1
  cout << "*sptr: " << *sptr << endl;
  weak_ptr<int> wptr(sptr); // wptrָ��sptr��ָ��Ķ���
  cout << "When reference count is 1: " << wptr.expired() << endl; // �Ƿ�����dangle

  // weak_ptr���ܽ����ã������޷��õ���ָ���ֵ
  // ��ʹ�ܽ����ã�����expire����ٽ����ã�����������Ĳ���ᵼ��race condition
  // Ҫ����shared_ptr��������
  {
    shared_ptr<int> sptrFromWptr = wptr.lock(); // ���wptr�Ѿ�expire�ˣ�sptrFromWptrΪnull
    cout << "sptrFromWptr: " << *sptrFromWptr << endl;
    auto autoFromWptr = wptr.lock(); // autoͬshared_ptr
    cout << "autoFromWptr: " << *autoFromWptr << endl;
    shared_ptr<int> aptrByWptr(wptr); //���wptr�Ѿ�expire���׳��쳣
    cout << "aptrByWptr: " << *aptrByWptr << endl;
  }


  sptr = nullptr; // Reference countΪ0
  cout << "When reference count is 0: " << wptr.expired() << endl; // �Ƿ�����dangle

  {
    shared_ptr<int> sptrFromWptr = wptr.lock();
    // sptrFromWptrӦ��Ϊnull
    if (sptrFromWptr == nullptr)
    {
      cout << "sptrFromWptr is null." << endl;
    }
    else
    {
      cout << "!!!!!sptrFromWptr should be null!!!!!" << endl;
    }

    auto autoFromWptr = wptr.lock();
    // sptrFromWptrӦ��Ϊnull
    if (autoFromWptr == nullptr)
    {
      cout << "autoFromWptr is null." << endl;
    }
    else
    {
      cout << "!!!!!autoFromWptr should be null!!!!!" << endl;
    }

    // Ӧ���׳��쳣
    try
    {
      shared_ptr<int> aptrByWptr(wptr);
      cout << "!!!!!Should throw exception!!!!!" << endl;
    }
    catch (const std::bad_weak_ptr&)
    {
      cout << "autoFromWptr generates exception." << endl;
    }

    // weak_ptr��control block��Ҳ��weak count
    // ���������Ż���ԭ�򣬲������ǵ���weak_ptr�ĸ�����
    // ����weak_ptr���ڵĻ�����ʹû��shared_ptrָ���ˣ�
    // ��ָ��Ķ����control block�Ŀռ�Ҳ���ᱻ�ͷš�
    
  }
}
