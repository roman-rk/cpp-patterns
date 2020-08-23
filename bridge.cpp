#include <string>
#include <iostream>
using namespace std;

struct Renderer
{
  virtual string what_to_render_as() const = 0;
};

struct VectorRenderer : Renderer
{
  string what_to_render_as() const override
  {
    return " as lines";
  }
};

struct RasterRenderer : Renderer
{
  string what_to_render_as() const override
  {
    return " as pixels";
  }
};

struct Shape
{
    string name;
    string render;
    Shape(const Renderer& r) 
    {
      render = r.what_to_render_as();
    }
    string str() const
    {
        return "Drawing " + name + render;
    }
};

struct Triangle : Shape
{
    Triangle(const Renderer& r) : Shape(r)
    {
      name = "Circle";
    }
};

struct Square : Shape
{
    Square(const Renderer& r) : Shape(r)
    {
      name = "Square";
    }
};

int main()
{
  VectorRenderer vr{};
  Square s{vr};
  cout << s.str();
}