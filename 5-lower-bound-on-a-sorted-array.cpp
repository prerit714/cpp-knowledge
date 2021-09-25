#include <iostream>
using namespace std;

int lower_bound_recr(int* v, int low, int hi, int tgt) {
    if (hi==low) return low;
    int mid{low+(hi-low)/2};
    if (v[mid]>=tgt) return lower_bound_recr(v, low, mid, tgt);
    else return lower_bound_recr(v, mid+1, hi, tgt);
}

int lower_bound_iter(int* v, int n, int tgt) {
    int low{0}, hi{n-1};
    while (low<hi) {
        int mid{low+(hi-low)/2};
        if (v[mid]>=tgt) hi = mid; // v[mid]>tgt just becomes the upper_bound_iter
        else low = mid+1;
    }
    return low;
}

int main() {
    int v[] {2, 3, 4, 5, 7, 19, 32, 38, 39, 45, 99};
    int n{sizeof(v)/sizeof(v[0])};
    int tgts[] {4, 19, 38, 99, 100, 200};
    for (int tgt: tgts) {
        int idx1{lower_bound_recr(v, 0, n-1, tgt)};
        cout << idx1 << ' ' << v[idx1] << endl;
        int idx2{lower_bound_iter(v, n, tgt)};
        cout << idx2 << ' ' << v[idx2] << endl;
    }
    return 0;
}