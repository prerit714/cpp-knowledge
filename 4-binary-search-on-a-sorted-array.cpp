#include <iostream>
using namespace std;

int binary_search_recr(int* v, int low, int hi, int tgt) {
    if (low>hi) return -1;
    int mid{low+(hi-low)/2};
    if (v[mid]==tgt) return mid;
    else if (v[mid]>tgt) return binary_search_recr(v, low, mid-1, tgt);
    else return binary_search_recr(v, mid+1, hi, tgt);
}

int binary_search_iter(int* v, int n, int tgt) {
    int low{0}, hi{n-1};
    while (low<=hi) {
        int mid{low+(hi-low)/2};
        if (v[mid]==tgt) return mid;
        else if (v[mid]>tgt) hi = mid-1;
        else low = mid+1;
    }
    return -1;
}

int main() {
    int v[] {2, 3, 4, 5, 7, 19, 32, 38, 39, 45, 99};
    int n{sizeof(v)/sizeof(v[0])};
    int tgts[] {4, 19, 38, 99, 100, 200};
    for (int tgt: tgts) {
        int idx1{binary_search_recr(v, 0, n-1, tgt)};
        cout << idx1 << ' ' << v[idx1] << endl;
        int idx2{binary_search_iter(v, n, tgt)};
        cout << idx2 << ' ' << v[idx2] << endl;
    }
    return 0;
}