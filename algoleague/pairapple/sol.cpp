#include <bits/stdc++.h>
using namespace std;

#define int int64_t

void solve() {
  int N, K;
  cin >> N >> K;
  assert(2 <= N <= 1e6);
  assert(2 <= K <= N && (K % 2 == 0));
  vector<bool> has(N);
  for (int i = 0; i < K; ++i) {
    int u;
    cin >> u;
    assert(1 <= u <= N);
    has[u - 1] = 1;
  }
  vector<vector<int>> adj(N);
  for (int i = 1; i < N; ++i) {
    int p;
    cin >> p;
    assert(1 <= p <= N);
    --p;
    assert(p != i);
    adj[p].push_back(i);
  } 
  bool bad = 0;
  vector<bool> vis(N);
  auto dfs = [&](auto&& self, int u) -> bool {
    vis[u] = 1;
    int need = has[u];
    for (int& v : adj[u]) {
      assert(!vis[v]);
      need += self(self, v);
    }
    bad |= u == 0 && need != 0 && need != 2;
    bad |= need > 2;
    return need == 1;
  };
  dfs(dfs, 0);
  for (int i = 0; i < N; ++i) {
    assert(vis[i]);
  }
  if (bad) {
    cout << "No\n";
  } else {
    cout << "Yes\n";
  }
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