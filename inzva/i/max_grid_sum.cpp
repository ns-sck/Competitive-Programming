#include <bits/stdc++.h>
using namespace std;

#define int int64_t

vector<int> dp;
vector<vector<int>> grid;

// problem: take only one element from each row and each column
// what is the maximum point?

// classic recursive solution
int rec(int i, int n, int mask) {
  if (i == n) {
    return 0;
  }
  // we come this state in the recursion tree and calculated it before
  // so no need to calculate it again
  // for example the mask is 101010, we came here before
  // by taking elements in 2'nd, 4'th and 6'th columns
  // the maximum point can be achieved using the elements in
  // 1'st, 3'rd and 5'th elements is calculated and stored in dp[101010] 
  if (dp[mask] != -1) {
    return dp[mask];
  }
  int ans = 0;
  for (int j = 0; j < n; ++j) {
    if ((mask >> j) & 1) {
      continue;
    }
    // by saying mask | (1 << j), we say that we pick an element
    // from j'th column and won't take from there again
    ans = max(ans, grid[i][j] + rec(i + 1, n, mask | (1 << j)));
  }
  dp[mask] = ans;
  return ans;
}

// the same as above, but instead of looking
// each j bit whether it is 0 or 1, this code gets
// the smallest bit which is 0, not sure if this optimizes much?
int rec2(int n, int mask) {
  int i = __builtin_popcount(mask);
  if (i == n) {
    return 0;
  }
  if (dp[mask] != -1) {
    return dp[mask];
  }
  int ans = 0;
  int available = ((1 << n) - 1) & ~(mask);
  // 1000100001001000 becomes
  // 0111011110110111
  while (available) {
    // gets the msb 1, which was actually the msb 0 in original mask
    int bit = available & -available;
    available -= bit;
    // 63 since i #define int int64_t, 31 should be used for int
    int bit_idx = 63 - __builtin_clzll(bit);
    ans = max(ans, grid[i][bit_idx] + rec2(n, mask | bit));
  }
  return dp[mask] = ans;
}

void solve() {
  int N;
  cin >> N;
  grid = vector<vector<int>>(N, vector<int>(N));
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      cin >> grid[i][j];
    }
  }
  dp.assign(1 << N, -1);
  // iterative solution
  vector<int> dp2(1 << N, 0);
  for (int i = 0; i < (1 << N); ++i) {
    int r = __builtin_popcount(i);
    // we are in a current state say it is 1000
    for (int j = 0; j < N; ++j) {
      // if j'th bit is set, don't take from there since we used it
      if ((i >> j) & 1) continue;
      // change dp[1001], dp[1100], dp[1010] from current state
      dp2[i | (1 << j)] = max(dp2[i | (1 << j)], dp2[i] + grid[r][j]);
    }
  }
  cout << dp2[(1 << N) - 1] << '\n';
  cout << rec2(N, 0) << '\n';
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