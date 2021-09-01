#include <iostream>
#include <string>
using namespace std;

struct Point {
  int x{}, y{}, z{};
  string name{};
};

int main() {
  Point p {1, 2, 3, "foo"}; // this code works perfectly fine in c++20
  // the above throws an error if I compile it with c++11 flag
  return 0;
}