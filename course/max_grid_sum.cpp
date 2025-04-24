#include <bits/stdc++.h>
using namespace std;

#define int int64_t

int N;
vector<vector<int>> grid(1000, vector<int>(1000));
vector<int> dp;

// __builtin_popcount(n) -> 1 olan bit sayisi
// __builtin_clz(n) -> soldaki 0 sayisi
// __builtin_ctz(n) -> sagdaki 0 sayisi

int rec(int row, int mask) {
  if (row == N) {
    return 0;
  }
  if (dp[mask] != -1) {
    return dp[mask];
  }
  int ans = 0;
  for (int i = 0; i < N; ++i) {
    if ((mask >> i) & 1) {
      continue;
    }
    ans = max(ans, rec(row + 1, mask | (1 << i)) + grid[row][i]);
  }
  return dp[mask] = ans;
}

void solve() {
  cin >> N;
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      cin >> grid[i][j];
    }
  }
  dp.assign(1 << N, -1);
  cout << rec(0, 0) << '\n';
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