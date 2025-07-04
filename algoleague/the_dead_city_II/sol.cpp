#include <bits/stdc++.h>
using namespace std;

#define int int64_t

constexpr int MOD = 1e9 + 7;
constexpr int X = 93623149;

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

int arr[X + 1], inv[X + 1];

void solve() {
  int K;
  cin >> K;
  arr[0] = arr[1] = 1;
  for (int i = 2; i <= X; ++i) {
    arr[i] = arr[i - 1] * i % MOD;
  }
  inv[X] = fp(arr[X], MOD - 2);
  for (int i = X - 1; i; --i) {
    inv[i] = inv[i + 1] * (i + 1) % MOD;
  }
  int ans = arr[K];
  for (int i = K + 1; i < X; ++i) {
    int a = arr[i] * inv[i - K] % MOD;
    ans = (ans + a) % MOD;
  }
  ans = ans * inv[K] % MOD;
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