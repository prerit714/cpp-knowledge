#include <iostream>
using namespace std;

int main() {
    char s[] {"prerit dayal"};
    for (char c: s) {
        cout << static_cast<int>(c) <<  ' ';
    }
    cout << '\n';
    return 0;
}