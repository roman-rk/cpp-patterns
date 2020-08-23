#include "composite.hpp"

int sum(const vector<ContainsIntegers*> items)
{
  int result{0};
  for (auto item : items)
  {
    result += item->int_sum();
  }
  return result;
}

int main()
{
  SingleValue sv{1};
  ManyValues mv;
  mv.add(2);
  mv.add(3);
  cout << sum({&sv, &mv});
}