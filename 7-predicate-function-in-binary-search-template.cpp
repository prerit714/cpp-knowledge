#include <iostream>
using namespace std;

int bin_search_template(int* v, bool* p, int n) {
    int low{0}, hi{n-1};
    while (low<hi) {
        int mid{low+(hi-low)/2}; // is done instead of (low+hi)/2 to avoid integer overflow
        if (p[mid]) hi = mid;
        else low = mid+1;
    }
    return low;
}

int main() {
    int v[] {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; // actual values
    bool p[] { // is my predicate function
        false, false, false, false,
        true, true, true, true, true, true
    };
    int n{sizeof(v)/sizeof(v[0])};
    int u{bin_search_template(v, p, n)};
    cout << u << endl; // outputs: 4
    return 0;
}