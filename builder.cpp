#include <string>
#include <ostream>
#include <vector>
#include <utility>
#include <iostream>

using namespace std;

class CodeBuilder
{
  string name;
  vector<pair<string, string>> fields; 
public:
  CodeBuilder(const string& class_name)
  {
    name = class_name;
  }

  CodeBuilder& add_field(const string& name, const string& type)
  {
    fields.push_back({type, name});
    return *this;
  }

  friend ostream& operator<<(ostream& os, const CodeBuilder& obj)
  {
    os << "class " << obj.name << endl;
    os << "{" << endl;
    for (auto field : obj.fields)
    {
      os << "  " << field.first << " " << field.second << ";" << endl;
    }
    os << "};";
    return os;
  }
};

int main()
{
  auto cb = CodeBuilder{"Person"}.add_field("name", "string").add_field("age", "int");
  cout << cb;
  return 0;
}