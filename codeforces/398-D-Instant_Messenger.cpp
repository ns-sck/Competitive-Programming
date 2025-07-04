#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "templates/debug.h"
#else
#define debug(...) 42
#endif

#define int int64_t

void solve() {
  int N, M, Q, O;
  cin >> N >> M >> Q >> O;
  vector<bool> on(N);
  for (int i = 0; i < O; ++i) {
    int u;
    cin >> u;
    on[u - 1] = 1;
  }
  vector<set<int>> adj(N);
  for (int i = 0; i < M; ++i) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    adj[u].insert(v);
    adj[v].insert(u);
  }
  vector<array<int, 3>> qrs;
  vector<int> has(N);
  for (int i = 0; i < N; ++i) {
    has[i] = 0;
    for (int j : adj[i]) {
      has[i] += on[j];
    }
  }
  while (Q--) {
    char qt;
    int u, v;
    cin >> qt >> u;
    --u;
    if (qt == 'O') {
      qrs.push_back({0, u, 0});
    } else if (qt == 'F') {
      qrs.push_back({1, u, 0});
    } else if (qt == 'A') {
      cin >> v;
      qrs.push_back({2, u, v - 1});
    } else if (qt == 'D') {
      cin >> v;
      qrs.push_back({3, u, v - 1});
    } else {
      int ans = has[u];
      map<int, int> mp, on2;
      for (auto& [x, y, z] : qrs) {
        if (x == 0) {
          on2[y]++;
        } else if (x == 1) {
          on2[y]--;
        } else {
          if (y == u || z == u) {
            int v = u ^ y ^ z;
            if (x == 2) {
              mp[v]++;
            } else if (x == 3) {
              mp[v]--;
            }
          }
        }
      }
      for (auto& [a, b] : mp) {
        if (b == 1) {
          if (on2[a] + on[a] == 1) {
            ans++;
          }
        } else if (b == -1) {
          if (on[a]) {
            ans--;
          }
        }
      }
      for (auto& [x, y] : on2) {
        if (adj[u].find(x) != adj[u].end() && abs(mp[x]) != 1) {
          ans += on2[x];
        }
      }
      cout << ans << '\n';
    }
    if (qrs.size() >= sqrt(M)) {
      for (auto [x, y, z] : qrs) {
        if (x == 0) {
          on[y] = 1;
        } else if (x == 1) {
          on[y] = 0;
        } else if (x == 2) {
          adj[z].insert(y);
          adj[y].insert(z);
        } else if (x == 3) {
          adj[z].erase(y);
          adj[y].erase(z);
        }
      }
      for (int i = 0; i < N; ++i) {
        has[i] = 0;
        for (int j : adj[i]) {
          has[i] += on[j];
        }
      }
      qrs = {};
    }
  }
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