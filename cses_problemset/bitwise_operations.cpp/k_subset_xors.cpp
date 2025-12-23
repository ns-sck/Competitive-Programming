#include <bits/stdc++.h>
using namespace std;
 
#ifdef LOCAL
#include "templates/debug.h"
#else
#define debug(...) 42
#endif
 
#define int int64_t
 
void solve() {
  int N, K;
  cin >> N >> K;
  vector<int> arr(N);
  for (int& x : arr) cin >> x;
  vector<int> base(31);
  for (int& x : arr) {
    while (x) {
      int bit = 63 - __builtin_clzll(x);
      if (!base[bit]) {
        base[bit] = x;
        for (int j = 0; j < 30; ++j) {
          if (j == bit) continue;
          if ((base[j] >> bit) & 1) {
            base[j] ^= x;
          }
        }
        break;
      } else {
        x ^= base[bit];
      }
    }
  }
  debug(base);
  vector<int> ans;
  for (int i = 0; i < 31; ++i) {
    if (base[i]) {
      ans.push_back(base[i]);
    }
  }
  int c = 1 << min((int) 30, (int) (N - ans.size()));
  int need = K / c + 1;
  int b = min((int) ans.size(), (int) (63ll - __builtin_clzll(need) + 1));
  vector<int> srt;
  for (int i = 0; i < (1 << b); ++i) {
    int a = 0;
    for (int j = 0; j < b; ++j) {
      if ((i >> j) & 1) {
        a ^= ans[j];
      }
    }
    srt.push_back(a);
  }
  sort(srt.begin(), srt.end());
  for (int i = 0; i < K; ++i) {
    cout << srt[i / c] << ' ';
  }
  debug(c);
}
 
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  // cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}