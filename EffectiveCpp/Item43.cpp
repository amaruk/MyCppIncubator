#include "stdafx.h"
#include "Item43.h"


Item43::Item43() :
  ItemBase("43")
{
}


Item43::~Item43()
{
}

namespace ITEM43
{
  class Cat
  {
  public:
    void Say() const { cout << "Cat say Meow" << endl; }
  };

  class Dog
  {
  public:
    void Say() const { cout << "Dog say Woof" << endl; }
  };

  class Fox
  {
  public:
    void Say() const { cout << "What does the fox say..." << endl; }
  };

  template<typename Animal>
  class Keeper
  {
  public:
    void Feed(const Animal& animal)
    {
      cout << "Feeding: ";
      animal.Say();
    }
  };

  // Total template specialization
  template<>
  class Keeper<Fox>
  {
  public:
    void Feed(const Fox& animal) // ���������Feed��������Keeper��ģ��ʵ����ģ������ΪFoxʱ��û��Feed�������Ե��ã��޷����롣
    {
      cout << "Feeding: ";
      animal.Say();
    }
  };

  template<typename Animal>
  class KeeperAlice : public Keeper<Animal>
  {
  public:
    void FeedWithName(const Animal& animal)
    {
      cout << "[Alice] ";
      Feed(animal);
      this->Feed(animal);
      Keeper<Animal>::Feed(animal);
    }
  };

}

void Item43::ItemEntry()
{
  //// Item 43: Know how to access names in templatized base classes
  using ITEM43::Cat;
  using ITEM43::Dog;
  using ITEM43::Fox;
  using ITEM43::Keeper;
  using ITEM43::KeeperAlice;

  Cat cat{};
  Dog dog{};
  Fox fox{};

  Keeper<Dog> keeperGeneric{};
  keeperGeneric.Feed(dog);

  cout << endl;

  KeeperAlice<Cat> keeperAlice{};
  keeperAlice.FeedWithName(cat);

  cout << endl;

  KeeperAlice<Fox> keeperAliceFox{};
  keeperAliceFox.FeedWithName(fox);
}