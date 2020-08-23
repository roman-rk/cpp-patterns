#include <string>
#include <ostream>
#include <iostream>

using namespace std;

struct Person
{
  int id;
  string name;

  friend ostream& operator<<(ostream& os, const Person& obj)
  {
    os << "Name: " << obj.name << ", ID: " << obj.id << endl;
    return os;
  }
};

class PersonFactory
{
  int id;
public:
  PersonFactory() : id(0) {}

  Person create_person(const string& name)
  {
    return {id++, name};
  }
};

int main()
{
  PersonFactory pf{};
  auto j = pf.create_person("John");
  auto p = pf.create_person("Peter");
  cout << j << p;
  return 0;
}