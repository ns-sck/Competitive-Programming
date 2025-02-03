#include <bits/stdc++.h>
using namespace std;

#define int int64_t

void solve() {
  int N, X;
  cin >> N >> X;
  int a = N / 2, b = N - a;
  vector<int> arr(a), brr(b), sums;
  for (int& x : arr) cin >> x;
  for (int& x : brr) cin >> x;
  for (int i = 0; i < (1 << a); ++i) {
    int x = 0;
    for (int j = 0; j < a; ++j) {
      if ((1 << j) & i) {
        x += arr[j];
      }
    }
    sums.emplace_back(x);
  }
  sort(sums.begin(), sums.end());
  int ans = 0;
  for (int i = 0; i < (1 << b); ++i) {
    int x = 0;
    for (int j = 0; j < b; ++j) {
      if ((1 << j) & i) {
        x += brr[j];
      }
    }
    ans -= lower_bound(sums.begin(), sums.end(), X - x) - upper_bound(sums.begin(), sums.end(), X - x);
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