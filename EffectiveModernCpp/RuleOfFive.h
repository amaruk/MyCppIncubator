#include <vector>
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::vector;
using std::string;

class Fox
{
public:
  Fox() { cout << "\tFox()" << endl; }
  Fox(string name) : m_Name(name) { cout << "\tFox(string)" << endl; }
  Fox(const Fox& anotherFox) : m_Name(anotherFox.m_Name) { cout << "\tFox(const Fox&)" << endl; }
  Fox(Fox&& anotherFox) : m_Name(std::move(anotherFox.m_Name)) { cout << "\tFox(Fox&&)" << endl; }
  Fox& operator=(Fox& anotherFox) { cout << "\t=(Fox&)" << endl; this->m_Name = anotherFox.m_Name; return *this; }
  Fox& operator=(Fox&& anotherFox) { cout << "\t=(Fox&&)" << endl; this->m_Name = std::move(anotherFox.m_Name); return *this; }

  void SetName(const string& newName) { this->m_Name = newName; }
  const string GetName() { return this->m_Name; }

private:
  string m_Name{ "DEFAULT" };
};

