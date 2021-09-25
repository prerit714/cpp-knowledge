#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

void out(vector<int>& v) {
  for (int x: v) {
    cout << x << ' ';
  }
  cout << endl;
}

int main() {
  vector<int> v {10, 20, 30, 40, 50, 50, 60};
  // sort(v.rbegin(), v.rend());
  sort(v.begin(), v.end());
  out(v);
  random_shuffle(v.begin(), v.end());
  map<int, int> cache{};
  for (int x: v) {
    ++cache[x];
  }
  for (auto it{cache.rbegin()}; it!=cache.rend(); ++it) {
    cout << it->first << ' ' << it->second << endl;
  }
  return 0;
}