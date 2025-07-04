#include <bits/stdc++.h>
using namespace std;

#define int int64_t

void solve() {
  int N;
  cin >> N;
  vector<int> arr(N);
  for (int& x : arr) cin >> x;
  map<int, int> mp;
  int ans = 0;
  for (int i = 0, j = 0; i < N; ++i) {
    while (j < N && !mp[arr[j]]) {
      mp[arr[j++]] = 1;
    }
    ans += j - i;
    mp[arr[i]] = 0;
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