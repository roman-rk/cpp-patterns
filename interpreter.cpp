#include <map>
#include <string>
#include <sstream>
#include <iostream>

using namespace std;

struct ExpressionProcessor
{
  map<char,int> variables;

  int calculate(const string& expression)
  {
    return 0;
  }
};

int main()
{
  string test = "11+12+13-13";
  stringstream ss;
  ss << test;
  string temp;
  int found;
  while(!ss.eof())
  {
    ss >> temp;
    if (stringstream(temp) >> found)
    {
      cout << found << endl;
    }
  }
}