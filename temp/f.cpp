#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "templates/debug.h"
#else
#define debug(...) 42
#endif

#define int int64_t

void solve() {
  string S;
  int tt;
  cin >> S >> tt;
  if (S == "first") {
    while (tt--) {
      int N, M;
      cin >> N >> M;
      vector<vector<int>> adj(N);
      for (int i = 0; i < M; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
      }
      queue<int> q;
      vector<char> ans(N);
      vector<int> dis(N, 1ll << 61);
      q.push(0);
      int k = 0;
      ans[0] = 0;
      dis[0] = 0;
      char ch[3] = {'r', 'g', 'b'};
      while (q.size()) {
        int u = q.front();
        q.pop();
        for (int& v : adj[u]) {
          if (dis[v] > dis[u] + 1) {
            int nx = (ans[u] + 1) % 3;
            ans[v] = nx;
            dis[v] = dis[u] + 1;
            q.push(v);
          }
        }
      }
      for (int i = 0; i < N; ++i) {
        cout << ch[ans[i]];
      }
      cout << '\n';
    }
  } else {
    while (tt--) {
      int Q;
      cin >> Q;
      while (Q--) {
        int n;
        string s;
        cin >> n >> s;
        if (s.size() == 1) {
          cout << 1 << '\n';
        } else {
          int idx = 1;
          int r = count(s.begin(), s.end(), 'r');
          int g = count(s.begin(), s.end(), 'g');
          int b = count(s.begin(), s.end(), 'b');
          for (int i = 0; i < n; ++i) {
            if (!r && s[i] == 'b') idx = i + 1;
            if (!g && s[i] == 'r') idx = i + 1;
            if (!b && s[i] == 'g') idx = i + 1;
          }
          cout << idx << '\n';
        }
      }
    }
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