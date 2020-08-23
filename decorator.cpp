#include <string>
#include <typeinfo>
#include <iostream>
using namespace std;

struct Flower
{
  virtual string str() = 0;
};

struct Rose : Flower
{
  string str() override {
    return "A rose";
  }
};

struct RedFlower : Flower
{
    Flower& flower;
    RedFlower(Flower &flower) : flower(flower) {}
    string str() override 
    {
      string s = flower.str();
      size_t pos;
      pos = s.find("red");
      if (!(pos == string::npos)) return s;
      pos = s.find("blue");
      if (!(pos == string::npos)) {
        string toReplace = "blue";
        return s.replace(pos, toReplace.length(), "blue and red");
      }
      return s + " that is red";
    }
};

struct BlueFlower : Flower
{
    Flower& flower;
    BlueFlower(Flower &flower) : flower(flower) {}
    string str() override 
    {
      string s = flower.str();
      size_t pos;
      pos = s.find("blue");
      if (!(pos == string::npos)) return s;
      pos = s.find("red");
      if (!(pos == string::npos)) {
        string toReplace = "red";
        return s.replace(pos, toReplace.length(), "red and blue");
      }
      return s + " that is blue";
    }
};

int main()
{
  Rose rose;
  RedFlower red_rose{rose};
  RedFlower red_red_rose{red_rose};
  BlueFlower blue_red_rose{red_red_rose};
  cout << rose.str() << endl;
  cout << red_rose.str() << endl;
  cout << red_red_rose.str() << endl;
  cout << blue_red_rose.str() << endl;
}