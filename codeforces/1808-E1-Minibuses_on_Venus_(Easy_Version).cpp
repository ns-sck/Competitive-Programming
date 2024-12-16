#include <bits/stdc++.h>
using namespace std;

#define int int64_t
void solve() {
  int N, K, M;
  cin >> N >> K >> M;
  int ans = 1;
  for (int i = 0; i < N; ++i) {
    ans = ans * K % M;
  }
  for (int j = 0; j < K; ++j) {
    vector<vector<int>> dp(N + 1, vector<int>(K));
    dp[0][0] = 1;
    for (int i = 1; i <= N; ++i) {
      vector<int> add(K);
      for (int md = 0; md < K; ++md) {
        for (int k = 0; k < K; ++k) {
          if (2 * k % K == j) continue;
          add[md] = (add[md] + dp[i - 1][(md - k + K) % K]) % M;
        }
      
      }
      for (int k = 0; k < K; ++k) {
        dp[i][k] = (dp[i][k] + add[k]) % M;
      }
    }
    ans = (ans - dp[N][j] + M) % M;
  }
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