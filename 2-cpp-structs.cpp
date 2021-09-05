#include <iostream>
#include <string>
using namespace std;

struct Point {
    int x{}, y{}, z{};
    string name{};
};

int main() {
    Point p {1, 2, 3, "foo"};
    cout << p.x << ' ' << p.y << ' ' << p.z << endl;
    /*
        Below is the output: 
        1 2 3
    */
    return 0;
}