#include <bits/stdc++.h>
using namespace std;

#define int int64_t

void solve() {
  int N, K;
  cin >> N >> K;
  int ans = K;
  vector<int> arr(N);
  for (int i = 0; i < N; ++i) {
    string st;
    cin >> st;
    for (int j = 0; j < K; ++j) {
      if (st[j] == '1') {
        arr[i] |= 1 << j;
      }
    } 
    for (int j = 0; j < i; ++j) {
      ans = min(ans, (int)__builtin_popcount(arr[i] ^ arr[j]));
    }
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