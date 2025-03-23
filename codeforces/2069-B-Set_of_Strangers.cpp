#include <bits/stdc++.h>
using namespace std;

#define int int64_t

void solve() {
  int N, M;
  cin >> N >> M;
  vector<vector<int>> arr(N, vector<int>(M));
  vector<bool> a(N * M + 1), b(N * M + 1);
  bool good = 0;
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      cin >> arr[i][j];
      if ((i + j) & 1) {
        a[arr[i][j]] = 1;
      } else {
        b[arr[i][j]] = 1;
      }
      good |= a[arr[i][j]] && b[arr[i][j]];
    }
  }
  int ans = 0;
  int r[4] = {-1, 0, 1, 0};
  int c[4] = {0, 1, 0, -1};
  vector<bool> bad(N * M + 1);
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      bool found = 0;
      for (int k = 0; k < 4; ++k) {
        int ii = i + r[k];
        int jj = j + c[k];
        if (~ii && ii < N && ~jj && jj < M && arr[i][j] == arr[ii][jj]) {
          found = 1;
        }
      }
      bad[arr[i][j]] = bad[arr[i][j]] | found;
    }
  }
  bool found = 0;
  for (int i = 1; i < N * M + 1; ++i) {
    if (!a[i] && !b[i]) continue;
    if (bad[i]) {
      ans += 2;
      found = 1;
    } else {
      ans++;
    }
  }
  ans -= found + 1;
  cout << ans << '\n';
}

signed main () {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}