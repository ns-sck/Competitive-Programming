#include <bits/stdc++.h>
using namespace std;

#define int int64_t

void solve() {
  int N;
  string S;
  cin >> N >> S;
  int l = -1, r = -1;
  for (int i = 0; i < N; ++i) {
    if (S[i] == '1') {
      if (l == -1) l = i;
      r = i;
    } 
  }
  int ans = 0, left = 1, right = 1;
  while (l < r) {
    if (S[l + 1] == '1') {
      ++l, ++left;
    } else if (S[r - 1] == '1') {
      --r, ++right;
    } else {
      if (left <= right) {
        ans += left;
        ++l;
      } else {
        ans += right;
        --r;
      }
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