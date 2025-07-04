#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "templates/debug.h"
#else
#define debug(...) 42
#endif

#define int int64_t

void solve() {
  int N;
  cin >> N;
  vector<int> ans(N);
  vector<int> vis(1 << N);
  int mask = (1 << N) - 1;
  auto f = [&](auto&& self, int i, int cur) -> void {
    int x = mask & cur;
    // debug(i, x, vis[x]);
    if (vis[x]) return;
    vis[x] = 1;
    if (i == mask + N) {
      for (int& x : ans) cout << x;
      cout << '\n';
      exit(0);
    }
    cur <<= 1;
    ans.push_back(0);
    self(self, i + 1, cur);
    ans.pop_back();
    cur |= 1;
    ans.push_back(1);
    self(self, i + 1, cur);
    ans.pop_back();
    vis[x] = 0;
  };
  f(f, N, 0);
  // f(f, N - 1, 1);
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  // cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}

// 001
// 000
// 00101