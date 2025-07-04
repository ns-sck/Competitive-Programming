#include <bits/stdc++.h>
using namespace std;

#define int int64_t

void solve() {
  int N, M;
  cin >> N >> M;
  vector<string> grid(N);
  for (string& s : grid) cin >> s;
  bool vis[4] = {0, 0, 0, 0};
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      int c = grid[i][j] - 'A';
      if (i) vis[grid[i - 1][j] - 'A'] = 1;
      if (j) vis[grid[i][j - 1] - 'A'] = 1;
      vis[c] = 1;
      while (vis[c]) c = (c + 1) % 4;
      grid[i][j] = 'A' + c;
      memset(vis, 0, sizeof(vis));
      cout << grid[i][j];
    }
    cout << '\n';
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