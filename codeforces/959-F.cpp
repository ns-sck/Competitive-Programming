#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "templates/debug.h"
#else
#define debug(...) 42
#endif

#define int int64_t
constexpr int MOD = 1e9 + 7;

void solve() {
  int N, Q;
  cin >> N >> Q;
  vector<int> a(N);
  vector<int> pw(N + 1);
  pw[0] = 1;
  for (int i = 0; i < N; ++i) {
    cin >> a[i];
    if (i) pw[i] = pw[i - 1] * 2 % MOD;
  }
  pw[N] = pw[N - 1] * 2 % MOD;
  vector<int> basis(21);
  auto insert = [&](int x) {
    for (int i = 20; i >= 0; --i) {
      if ((x >> i) & 1) {
        if (!basis[i]) {
          basis[i] = x;
          return true;
        } else {
          x ^= basis[i];
        }
      }
    }
    return false;
  };
  auto check = [&](int x) {
    for (int i = 20; i >= 0; --i) {
      if ((x >> i) & 1) {
        if (!basis[i]) {
          return false;
        }
        x ^= basis[i];
      }
    }
    return true;
  };
  vector<array<int, 3>> qrs(Q);
  for (int i = 0; i < Q; ++i) {
    cin >> qrs[i][0] >> qrs[i][1];
    qrs[i][2] = i;
  }
  sort(qrs.begin(), qrs.end());
  int i = 0, c = 0;
  vector<int> ans(Q);
  for (auto [l, x, idx] : qrs) {
    while (i <= l - 1) {
      if (!insert(a[i])) ++c;
      ++i;
    }
    if (check(x)) {
      ans[idx] = pw[c];
    } else {
      ans[idx] = 0;
    }
  }
  for (int i = 0; i < Q; ++i) {
    cout << ans[i] << '\n';
  }
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  // cin >> t;
  while (t--) solve();
  return 0;
}