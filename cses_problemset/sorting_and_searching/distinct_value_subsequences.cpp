#include <bits/stdc++.h>
using namespace std;

#define int int64_t
constexpr int MOD = 1e9 + 7;

int fp(int a, int b) {
  int res = 1;
  while (b > 0) {
    if (b & 1) {
      res = res * a % MOD;
    }
    a = a * a % MOD;
    b >>= 1;
  }
  return res;
}

void solve() {
  int N;
  cin >> N;
  vector<int> arr(N);
  for (int& x : arr) cin >> x;
  map<int, int> mp;
  int mul = 1, ans = 0;
  for (int i = 0; i < N; ++i) {
    mul = mul * fp(mp[arr[i]] + 1, MOD - 2) % MOD;
    ans = (ans + mul) % MOD;
    mul = mul * (++mp[arr[i]] + 1) % MOD;
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