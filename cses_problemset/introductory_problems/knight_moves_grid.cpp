#include <bits/stdc++.h>
using namespace std;

#define int int64_t

void solve() {
  int N;
  cin >> N;
  int dir[8][2] = {{-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}};
  vector<vector<int>> grid(N, vector<int>(N, 1ll << 61));
  vector<int> que = {0};
  for (int i = 0; i < que.size(); ++i) {
    int cost = que[i] % (1 << 31);
    que[i] >>= 32;
    int r = que[i] / N;
    int c = que[i] % N;
    if (grid[r][c] <= cost) continue;
    grid[r][c] = cost;
    for (auto [a, b] : dir) {
      int rr = r + a;
      int cc = c + b;
      if (rr >= 0 && rr < N && cc >= 0 && cc < N && cost + 1 < grid[rr][cc]) {
        que.push_back(((rr * N + cc) << 32) + (cost + 1));
      }
    }
  }
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      cout << grid[i][j] << " \n"[j == N - 1];
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