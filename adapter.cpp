#include <iostream>

struct Square
{
  int side{ 0 };


  explicit Square(const int side)
    : side(side)
  {
  }
};

struct Rectangle
{
  virtual int width() const = 0;
  virtual int height() const = 0;

  int area() const
  {
    return width() * height();
  }
};

struct SquareToRectangleAdapter : Rectangle
{
  SquareToRectangleAdapter(const Square& square)
  {
      this->side = square.side;
  }
  int side;

  int width() const
  {
    return side;
  }

  int height() const
  {
    return side;
  }
};

int main()
{
  auto x = Square(4);
  SquareToRectangleAdapter ad {x};
  std::cout << ad.area();

}