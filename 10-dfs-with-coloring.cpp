#include <algorithm>
#include <array>
#include <cmath>
#include <ctime>
#include <iostream>
#include <cstdio>
#include <map>
#include <set>
#include <string>
#include <utility>
#include <vector>
using namespace std;
#define FASTIO          ios_base::sync_with_stdio(0), cin.tie(0);
#define RANDOMIZE       srand(time(0));
#define SQ(x)           (x)*(x)
#define CU(x)           (x)*(x)*(x)
#define DEBUG(x)        printf(#x " = %d\n", x)
using ll                = long long;
using ull               = unsigned ll;
using vi                = vector<int>;
using vvi               = vector<vi>;
using vll               = vector<ll>;
using ii                = pair<int, int>;
using vii               = vector<ii>;
using vb                = vector<bool>;
using vc                = vector<char>;
constexpr char          nl {'\n'};

template <typename T> void out(const T& t) {
  for (const auto& x: t) {
    cout << x << ' ';
  }
  cout << '\n';
}

/*
  the entry and exit times are also calculated,
  for any vertex v: if color is 0 it is not visited,
  color 1 is when a visit is done, color is 2 when
  vertex is exited
*/

void dfs(int v, vvi& adj, vi& color, vi& time_in, vi& time_out, int& dfs_timer) {
  time_in[v] = dfs_timer++;
  color[v] = 1;
  for (int u: adj[v]) {
    if (color[u]==0) {
      dfs(u, adj, color, time_in, time_out, dfs_timer);
    }
  }
  color[v] = 2;
  time_out[v] = dfs_timer++;
}

int main() { FASTIO RANDOMIZE
  vvi adj {
    {1, 3, 8}, {0, 7}, {3, 5, 7}, {0, 2, 4}, {3, 8}, {2, 6}, {5}, {1, 2}, {0, 4}
  };
  int n{static_cast<int>(adj.size())};
  int dfs_timer{0};
  vi time_in(n, 0), time_out(n, 0), color(n, 0);
  dfs(0, adj, color, time_in, time_out, dfs_timer);
  out(time_in);
  out(time_out);
  out(color);
  return 0;
}
