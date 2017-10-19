#include "stdafx.h"
#include "RuleOfFive.h"

void RuleOfFive()
{
  cout << "### Should be default constructor" << endl;
  Fox foxConstFoo{};
  Fox foxConstBar{};
  cout << "foxConstFoo.name: " << foxConstFoo.GetName() << endl;
  cout << "foxConstBar.name: " << foxConstBar.GetName() << endl;

  cout << endl;

  cout << "### Should be customer constructor" << endl;
  Fox foxCustConstFoo{ "Foo" };
  Fox foxCustConstBar{ "Bar" };
  cout << "foxCustConstFoo.name: " << foxCustConstFoo.GetName() << endl;
  cout << "foxCustConstBar.name: " << foxCustConstBar.GetName() << endl;

  cout << endl;

  cout << "### Copy constructor" << endl;
  Fox foxCopyConstFoo(foxCustConstFoo);
  cout << "### Copy operator" << endl;
  foxConstFoo = foxCustConstFoo;

  cout << endl;

  cout << "### Before changing names" << endl;
  cout << "foxCustConstFoo.name: " << foxCustConstFoo.GetName() << endl;
  cout << "foxCopyConstFoo.name: " << foxCopyConstFoo.GetName() << endl;
  cout << "foxConstFoo.name: " << foxConstFoo.GetName() << endl;
  cout << "### After changing names" << endl;
  foxCopyConstFoo.SetName("foxCopyConstFoo");
  foxConstFoo.SetName("foxConstFoo");
  cout << "foxCustConstFoo.name: " << foxCustConstFoo.GetName() << endl;
  cout << "foxCopyConstFoo.name: " << foxCopyConstFoo.GetName() << endl;
  cout << "foxConstFoo.name: " << foxConstFoo.GetName() << endl;

  cout << endl;

  cout << "### Move constructor" << endl;
  Fox foxMoveConstBar(std::move(foxCustConstBar));
  cout << "### Move operator" << endl;
  foxConstBar = std::move(foxCustConstBar);

  cout << endl;

  cout << "### Before changing names" << endl;
  cout << "foxCustConstBar.name: " << foxCustConstBar.GetName() << endl;
  cout << "foxMoveConstBar.name: " << foxMoveConstBar.GetName() << endl;
  cout << "foxConstBar.name: " << foxConstBar.GetName() << endl;
  cout << "### After changing names" << endl;
  foxMoveConstBar.SetName("foxMoveConstBar");
  foxConstBar.SetName("foxConstBar");
  cout << "foxCustConstBar.name: " << foxCustConstBar.GetName() << endl;
  cout << "foxMoveConstBar.name: " << foxMoveConstBar.GetName() << endl;
  cout << "foxConstBar.name: " << foxConstBar.GetName() << endl;
}