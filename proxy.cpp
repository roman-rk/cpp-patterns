#include <string>
#include <iostream>

using namespace std;

class Person
{
  friend class ResponsiblePerson;
  int age;
public:
  Person(int age) : age(age) {}

  int get_age() const { return age; }
  void set_age(int age) { this->age=age; }

  string drink() const { return "drinking"; }
  string drive() const { return "driving"; }
  string drink_and_drive() const { return "driving while drunk"; }
};

class ResponsiblePerson
{
public:
  ResponsiblePerson(const Person &person) : person(person) {}
  int get_age() const { return person.age; }
  void set_age(int age) { person.age=age; }

  string drink() const { return person.age >= 18 ? "drinking" : "too young"; }
  string drive() const { return person.age >= 16 ? "driving" : "too young"; }
  string drink_and_drive() const { return "dead"; }

private:
    Person person;
};

int main()
{
  Person p{17};
  ResponsiblePerson rp{p};
  cout << rp.drink() << " " << rp.drive() << " " << rp.drink_and_drive();
}