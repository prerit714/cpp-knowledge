#include <iostream>
#include <string>
using namespace std;

struct Point {
    int x{}, y{}, z{};
    string name{};
};

int main() {
    Point p {1, 2, 3, "foo"};
    return 0;
}