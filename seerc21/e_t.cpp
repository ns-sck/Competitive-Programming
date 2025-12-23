#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "templates/debug.h"
#else
#define debug(...) 42
#endif

#define int int64_t
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve() {
  auto get = [&](int l, int r) {
    return l + (rng() % (r - l + 1));
  };
  int N = get(200, 300);
  int M = get(100, 500);
  cout << N << ' ' << M << '\n';
  set<int> s;
  while (s.size() < N + M) {
    int x = get(1, 1000);
    if (s.find(x) == s.end()) cout << x << ' ';
    s.insert(x);
  }
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  // cin >> t;
  while (t--) solve();
  return 0;
}