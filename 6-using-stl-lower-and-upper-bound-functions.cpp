#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int v[] {2, 3, 4, 5, 7, 19, 19, 19, 19 , 32, 38, 39, 45, 99};
    int n{sizeof(v)/sizeof(v[0])};
    int vals[] {4, 19, 38, 99, 100, 200};
    // lower_bound 
    for (int x: vals) {
        auto k{lower_bound(v, v+n, x)-v};
        if (k<n&&v[k]==x) { // v[k]==x is done to ensure that x is not pointing to lower_bound of x, but the x itself
            // x is found at index k 
            cout << "x=" << x << " is found at k=" << k << endl;
        } else {
            // if x is not found, k will point to infinity (practically a very large number) which is assumed to be at nth index
            cout << "x=" << x << " was not found!, but k=" << k << endl;
        }
    }
    // upper_bound and lower_bound can be used together to find the number of occurences of an element in the sorted array
    int w{19};
    auto u{upper_bound(v, v+n, w)-lower_bound(v, v+n, w)};
    cout << u << " is the frequency of " << w << endl;
    // the above can be done in a single line using equal_range
    auto r{equal_range(v, v+n, w)};
    cout << r.second-r.first << " is the frequency of " << w << endl;
    /*
        Below is the output: 

        4 is found at k=2
        x=19 is found at k=5
        x=38 is found at k=10
        x=99 is found at k=13
        x=100 was not found!, but k=14
        x=200 was not found!, but k=14
        4 is the frequency of 19
        4 is the frequency of 19
        
    */ 
    return 0;
}
