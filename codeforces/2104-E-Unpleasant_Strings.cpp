#include <bits/stdc++.h>
using namespace std;

#define int int64_t

void solve() {
  int N, K, Q;
  string S;
  cin >> N >> K >> S >> Q;
  vector<vector<int>> nxt(N + 1, vector<int>(K, -1));
  vector<int> seen(K, -1);
  for (int i = N; ~i; --i) {
    for (int j = 0; j < K; ++j) {
      nxt[i][j] = seen[j];
    }
    if (i) seen[S[i - 1] - 'a'] = i;
  }
  vector<int> dp(N + 1);
  for (int i = N; ~i; --i) {
    int mn = 1e9;
    for (int j = 0; j < K; ++j) {
      if (~nxt[i][j]) mn = min(mn, dp[nxt[i][j]] + 1);
      else mn = 1;
    }
    dp[i] = mn;
  }
  while (Q--) {
    string s;
    cin >> s;
    int i = 0;
    for (char& c : s) {
      int x = c - 'a';
      if (i == -1) break;
      i = nxt[i][x];
    }
    if (i == -1) cout << 0 << '\n';
    else cout << dp[i] << '\n';
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