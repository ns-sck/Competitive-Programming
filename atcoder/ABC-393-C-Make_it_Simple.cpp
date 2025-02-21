#include <bits/stdc++.h>
using namespace std;

#define int int64_t

void solve() {
  int N, M;
  cin >> N >> M;
  set<pair<int, int>> s;
  for (int i = 0; i < M; ++i) {
    int u, v;
    cin >> u >> v;
    if (u > v) swap(u, v);
    if (u != v) {
      s.emplace(u, v);
    }
  }
  cout << M - s.size() << '\n';
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