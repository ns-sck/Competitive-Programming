#include <bits/stdc++.h>
using namespace std;

#define int int64_t
const int MAX = 5e4 + 1;

void solve() {
  int N, M;
  cin >> N >> M;
  vector<bitset<MAX>> go(N);
  vector<vector<int>> adj(N);
  vector<int> in(N);
  for (int i = 0; i < M; ++i) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    in[u]++;
    adj[v].push_back(u);
  }
  vector<int> que;
  for (int i = 0; i < N; ++i) {
    if (!in[i]) {
      que.push_back(i);
    }
  }
  int j = 0;
  while (j < que.size()) {
    int u = que[j++];
    go[u].set(u);
    for (int& v : adj[u]) {
      go[v] |= go[u];
      if (--in[v] == 0) {
        que.push_back(v);
      }
    }
  }
  for (int i = 0; i < N; ++i) {
    cout << go[i].count() << " \n"[i == N - 1];
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