#include <bits/stdc++.h>
using namespace std;

#define int int64_t

void solve() {
  int N, I;
  cin >> N >> I;
  vector<int> arr(N);
  for (int& x : arr) {
    cin >> x;
  }
  I <<= 3;
  int k = I / N;
  if (k > 20) k = 20;
  int K = 1 << k;
  map<int, int> mp;
  sort(arr.begin(), arr.end());
  int c = 0;
  for (int& x : arr) {
    if (!mp.count(x)) {
      mp[x] = c++;
    }
  }
  for (int& x : arr) {
    x = mp[x];
  }
  if (K >= N) {
    cout << 0 << '\n';
    return;
  }
  int ans = N;
  for (int i = 0; i < N; ++i) {
    int right = arr[i] + K - 1;
    auto it = upper_bound(arr.begin(), arr.end(), right);
    int r = it == arr.end() ? N : it - arr.begin();
    ans = min(ans, N - (r - i));
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