#include <iostream>
#include <string>
template <typename T, typename U>

T foo(T x, U y) {
  return {x + y};
}

int main() {
  std::cout << "Hello world!" << std::endl;
  std::cout << foo<int, int>(2, 3) << std::endl;
  std::cout << foo<std::string, std::string>("hello", "world") << std::endl;
  return 0;
}
