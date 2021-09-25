#include <iostream>
#include <vector>
using namespace std;
using vi = vector<int>;

int lower_bound(vi v, int k) {
  int n{static_cast<int>(v.size())};
  int a{0}, b{n-1};
  while (a<=b) {
    int mid{a+(b-a)/2};
    if (v[mid]>=k) {
      b = mid;
    } else {
      a = mid+1;
    }
  }
  return a;
}

int main() {
  vi v{7, 3, 9, 5, 2, 4, 20, 10, 99, 90};
  int k{10};
  return 0;
}