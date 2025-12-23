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
  vector<int> arr(N);
  vector<int> pref1(N + 1), pref2(N + 1);
  for (int i = 0; i < N; ++i) {
    cin >> arr[i];
    pref1[i + 1] = (pref1[i] + arr[i]) % MOD;
    pref2[i + 1] = (pref2[i] + (arr[i] * arr[i])) % MOD;
  }
  while (Q--) {
    int l, r;
    cin >> l >> r;
    int s = (pref1[r] - pref1[l - 1] + MOD) % MOD;
    int x = (pref2[r] - pref2[l - 1] + MOD) % MOD;
    cout << (((s * s - x + MOD) % MOD) * 500000004) % MOD << '\n';
  }
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