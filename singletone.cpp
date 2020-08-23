#include <functional>
#include <ostream>
#include <iostream>
#include <memory>

using namespace std;

struct SingletonTester
{
  template <typename T>
  bool is_singleton(function<T*()> factory)
  {
    auto test1 = factory();
    auto test2 = factory();
    return (test1 == test2);
  }
};

struct Person
{
  int id;
  string name;
  Person(int x, string y) : id(x), name(y) {}
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

  Person* create_person(const string& name)
  {
    return new Person(id++, name);
  }
};

int main()
{
  SingletonTester st;
  function<Person*()> x = [] () {
    PersonFactory pf; 
    return pf.create_person("test"); 
  };
  cout << st.is_singleton<Person>(x);
}