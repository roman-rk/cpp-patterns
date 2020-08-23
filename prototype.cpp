#include <ostream>
#include <iostream>
#include <memory>

using namespace std;

struct Point
{
  int x{ 0 }, y{ 0 };

  Point(){}
  
  Point(const int x, const int y)
    : x{x}, y{y}
  {}

  Point(const Point& other)
    : x{other.x}, y{other.y}
  {}
};

struct Line
{
  Point *start, *end;
  
  Line(Point* const start, Point* const end)
    : start(start), end(end)
  {
  }

  Line(const Line& other)
    : start(new Point(*other.start))
    , end(new Point(*other.end))
   {}

  ~Line()
  {
    delete start;
    delete end;
  }

  Line deep_copy() const
  {
    return {*this};
  }

  friend ostream& operator<<(ostream& os, const Line& obj)
  {
    os << "Start: " << obj.start->x << " " << obj.start->y << ", End: " << obj.end->x << " " << obj.end->y << endl;
    return os;
  }
};

int main()
{
  Line l {new Point(1, 1), new Point(2, 2)};
  auto backup = l.deep_copy();
  cout << l << backup;
  return 0;

}