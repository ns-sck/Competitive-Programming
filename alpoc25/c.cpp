#include <bits/stdc++.h>
using namespace std;

#define int int64_t

void solve() {
  int Q;
  cin >> Q;
  vector<vector<int>> pre(21);
  for (int i = 0; i < (1 << 20); ++i) {
    pre[__builtin_popcount(i)].push_back(i);
  }
  vector<bool> vis(1 << 20);
  set<int> s;
  while (Q--) {
    int q, x;
    cin >> q >> x;
    if (q & 1) {
      s.insert(x);
      vis[x] = 1;
    } else {
      int ans = 20;
      if (s.size() > 1000) {
        for (int i = 0; i < 20 && i < ans; ++i) {
          for (int& y : pre[i]) {
            if (vis[x ^ y]) {
              ans = i;
              break;
            }
          }
        }
      } else {
        for (int y : s) {
          ans = min(ans, (int) __builtin_popcount(x ^ y));
        }
      }
      cout << ans << '\n';
    }
  }
}

signed main () {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  // cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}