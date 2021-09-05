#include <iostream>
using namespace std;

int main() {
    char s[] {"prerit dayal"};
    for (char c: s) {
        cout << static_cast<int>(c) <<  ' ';
    }
    cout << '\n';
    // outputs: 112 114 101 114 105 116 32 100 97 121 97 108 0
    return 0;
}