#include <bits/stdc++.h>
using namespace std;

#define int int64_t

void solve() {
  int Q;
  vector<int> has(3e5 + 3), cost(3e5 + 3);
  vector<vector<int>> par(3e5 + 3, vector<int>(30, -1)); 
  cin >> Q >> has[0] >> cost[0];
  par[0][0] = 0;
  for (int i = 1; i <= Q; ++i) {
    int q;
    cin >> q;
    if (q & 1) {
      int p;
      cin >> p >> has[i] >> cost[i];
      par[i][0] = p;
      for (int j = 1; j < 30; ++j) {
        if (par[i][j - 1] == -1) break;
        par[i][j] = par[par[i][j - 1]][j - 1];
      }
    } else {
      int v, w, c = 0;
      cin >> v >> w;
      int a = w;
      bool found = 1;
      while (w && found) {
        int lo = 0, hi = 29, ans = v;
        while (lo <= hi) {
          int mi = (lo + hi) >> 1, m = mi, p = v;
          while (m && ~p) {
            int x = 63 - __builtin_clzll(m);
            p = par[p][x];
            m &= ~(1ll << x);
          }
          if (~p && has[p]) {
            lo = mi + 1;
            ans = p;
          } else {
            hi = mi - 1;
          }
        }
        if (has[ans] == 0) {
          found = 0;
          break;
        }
        found = 1;
        if (has[ans] >= w) {
          has[ans] -= w;
          c += w * cost[ans];
          w = 0;
        } else {
          w -= has[ans];
          c += has[ans] * cost[ans];
          has[ans] = 0;
        }
      }
      cout << a - w << ' ' << c << '\n';
      cout.flush();
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