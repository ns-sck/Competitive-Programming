#include <bits/stdc++.h>
using namespace std;

#define int int64_t

int MOD = 1e9 + 6;

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
  int Q;
  cin >> Q;
  while (Q--) {
    int a, b, c;
    cin >> a >> b >> c;
    int exp = fp(b, c);
    ++MOD;
    cout << fp(a, exp) << '\n';
    --MOD;
  }
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