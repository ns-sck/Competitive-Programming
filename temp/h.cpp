#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "templates/debug.h"
#else
#define debug(...) 42
#endif

#define int int64_t

void solve() {
  int N, Q;
  cin >> N >> Q;
  vector<vector<int>> lf;
  vector<int> st;
  while (Q--) {
    int l, r;
    cin >> l >> r;
    --l, --r;
    st[l]++;
    lf[r].push_back(l);
  }
  vector<int> ans(N);
  for (int i = 1; i < 17; ++i) {
    int k = 1 << i;
    vector<int> md(k);
    vector<int> cnt(k);
    vector<int> ans2(N);
    int c = 0;
    for (int j = 0; j < N; ++j) {
      int go = c - cnt[j % k];
      ans2[j] = st[j] + cnt[j % k] * k;
      c += st[j];
      cnt[j % k] = c;
      md[j % k]
    }
  }
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}