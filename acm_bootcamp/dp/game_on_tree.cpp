#include <bits/stdc++.h>
using namespace std;

#define int int64_t

vector<vector<int>> adj;
vector<int> win;

// https://codeforces.com/contest/1970/problem/C2

bool dfs(int u, int p) {
  if (adj[u].size() == 1 && adj[u][0] == p) {
    // adj[u].size() can be 1 only if it is the root or a leaf
    // if adj[u][0] == p, the only neighbor is the parent so u is not the root
    // if we place a stone here, we simply win
    return true;
  }
  bool lose = 0;
  for (int& v : adj[u]) {
    if (v == p) continue;
    // even if there is only one child leading to 
    // winning state, it is enough for us to lose 
    lose |= dfs(v, u);
  }
  // if no winning child, we win
  if (!lose) win[u] = 1;
  // otherwise we lose
  return win[u];
}

void solve() {
  int N, T;
  cin >> N >> T;
  adj = vector<vector<int>>(N);
  win = vector<int>(N);
  for (int i = 0; i < N - 1; ++i) {
    int u, v;
    cin >> u >> v;
    // 1 indexed input, 0 indexed solution, so --
    --u, --v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  int root;
  cin >> root;
  // 1 indexed input, 0 indexed solution, so --
  --root;
  dfs(root, -1);
  if (!win[root]) {
    cout << "Ron\n";
  } else {
    cout << "Hermione\n";
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