#include <bits/stdc++.h>
using namespace std;

#define int int64_t

void solve() {
  int N;
  cin >> N;
  vector<vector<vector<bool>>> seen(2, vector<vector<bool>>(N, vector<bool>(N * N)));
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      int k = 0;
      while ((seen[0][i][k] || seen[1][j][k]) && ++k); 
      cout << k << " \n"[j == N - 1];
      seen[0][i][k] = seen[1][j][k] = 1;
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