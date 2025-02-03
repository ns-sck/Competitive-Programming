#include <bits/stdc++.h>
using namespace std;

#define int int64_t

void solve() {
  int N, M;
  cin >> N >> M;
  vector<vector<int>> g(N, vector<int>(M));
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      cin >> g[i][j];
    }
    g[i].emplace_back(1e9 + i);
  }
  for (auto& v : g) {
    sort(v.begin(), v.end());
  }
  sort(g.begin(), g.end());
  int a = 0;
  for (int j = 0; j < M; ++j) {
    for (int i = 0; i < N; ++i) {
      if (i && g[i][j] < max(a, g[i - 1][j])) {
        cout << -1 << '\n';
        return;
      } else if (i == 0 && g[i][j] < a) {
        cout << -1 << '\n';
        return;
      }
      a = max(g[i][j], a);
    }
  }
  for (auto v : g) {
    cout << v.back() + 1 - 1e9 << ' ';
  }
  cout << '\n';
}

signed main () {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}