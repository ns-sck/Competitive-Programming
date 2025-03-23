#include <bits/stdc++.h>
using namespace std;

#define int int64_t

void solve() {
  int N;
  cin >> N;
  vector<int> arr(N);
  for (int& x : arr) cin >> x;
  int l = 0;
  int ans = 0;
  // the chosen subarray is [l, i]
  for (int i = 0; i < N; ++i) {
    while (l < i && arr[i] <= (i - l)) {
      ++l;
    }
    ans += (i - l + 1);
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