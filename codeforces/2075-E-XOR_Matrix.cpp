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
  int N, M, A, B;
  cin >> N >> M >> A >> B;
  A++, B++;
  int ans = (A * B) % MOD;
  int pick = A * (A - 1) / 2;
  pick = pick * fp(2, N) % MOD;
  pick = pick * M % MOD;
  ans = (ans + pick) % MOD;
  pick = B * (B - 1) / 2;
  pick = pick * fp(2, M) % MOD;
  pick = pick * N % MOD;
  ans = (ans + pick) % MOD;
  
  cout << ans << '\n';
}

signed main () {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}