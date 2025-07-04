#include <bits/stdc++.h>
using namespace std;

#define int int64_t

void solve() {
  int N;
  cin >> N;
  vector<string> grid(N);
  for (string& s : grid) cin >> s;
  vector<int> dis(2 * N, 1ll << 61);
  queue<array<int, 4>> que;
  que.push({0, 0, 0, 0});
  vector<vector<bool>> vis(N, vector<bool>(N));
  vector<vector<int>> par(N, vector<int>(N));
  while (que.size()) {
    auto [d, r, c, p] = que.front();
    que.pop();
    if (r + c && dis[r + c - 1] < d) continue;
    if (dis[r + c] < grid[r][c] - 'A') continue;
    if (vis[r][c]) continue;
    par[r][c] = p;
    vis[r][c] = 1;
    if (c < N - 1 && dis[r + c + 1] >= grid[r][c + 1] - 'A') {
      que.push({grid[r][c] - 'A', r, c + 1, 0});
      dis[r + c + 1] = grid[r][c + 1] - 'A';
    }
    if (r < N - 1 && dis[r + c + 1] >= grid[r + 1][c] - 'A') {
      que.push({grid[r][c] - 'A', r + 1, c, 1});
      dis[r + c + 1] = grid[r + 1][c] - 'A';
    }
  }
  int i = N - 1, j = N - 1;
  string ans;
  while (i || j) {
    ans += grid[i][j];
    if (par[i][j]) i--;
    else j--;
  }
  ans += grid[0][0];
  reverse(ans.begin(), ans.end());
  cout << ans << '\n';
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