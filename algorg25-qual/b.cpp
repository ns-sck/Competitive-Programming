#include <bits/stdc++.h>
using namespace std;

#define int int64_t

void solve() {
  int N;
  cin >> N;
  vector<int> arr(2 * N);
  for (int& x : arr) cin >> x;
  int ans = 0;
  sort(arr.begin(), arr.end());
  for (int i = 0; i < 2 * N - 1; i += 2) {
    ans += arr[i + 1] - arr[i];
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