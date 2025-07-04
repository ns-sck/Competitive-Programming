#include <bits/stdc++.h>
using namespace std;

#define int int64_t

void solve() {
  int N;
  cin >> N;
  vector<int> a(N + 10), b(N + 10);
  for (int i = 0; i < N; ++i) cin >> a[i];
  for (int j = 0; j < N; ++j) cin >> b[j];
  int i = 0, j = 0;
  vector<int> dp(N);
  int ans = 0;
  while (i < N && j < N) {
    if (a[i] < b[j]) {
      ++i;
    } else if (b[j] < a[i]) {
      ++j;
    } else {
      ans += (i + 1) * (j + 1);
      if (a[i + 1] == a[i] && b[j + 1] == b[j]) {
        if (i <= j) ++i;
        else ++j;
      } else if (a[i + 1] == a[i]) {
        ++i;
      } else if (b[j + 1] == b[j]) {
        ++j;
      } else {
        if (i <= j) ++i;
        else ++j;
      }
    }
  }
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