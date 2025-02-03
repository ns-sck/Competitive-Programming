#include <bits/stdc++.h>
using namespace std;

#define int int64_t

void solve() {
  int N, K;
  cin >> N >> K;
  vector<int> arr(N);
  map<int, int> mp;
  for (int i = 0; i < N; ++i) {
    cin >> arr[i];
    mp[arr[i]]++;
  }
  int ans = 0;
  for (int i = 1; i <= N; ++i) {
    while (mp[i]-- > 0) {
      if (mp[K - i] > 0) {
        ++ans;
        mp[K - i]--;
      } else break;
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