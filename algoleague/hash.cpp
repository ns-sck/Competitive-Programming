#include <bits/stdc++.h>
using namespace std;

#define int int64_t
constexpr int MAX = 2e5 + 1;
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

int P = 37;
int P2 = 29;
int pw[MAX], inv[MAX];

void init() {
  pw[0] = 1, inv[0] = 1;
  for (int i = 1; i < MAX; ++i) {
      pw[i] = pw[i - 1] * P % MOD;
      inv[i] = fp(pw[i], MOD - 2);
  }
}

int hashlama(string& s) {
  int ans = 0;
  for (int i = 0; i < s.size(); ++i) {
      int c = s[i] - 'a' + 1;
      ans = (ans + c * pw[i]) % MOD;
  }
  return ans;
} 

int hash2(vector<int>& pref, int l, int r) {
  int val = (pref[r] - pref[l] + MOD) % MOD;
  val = val * inv[l - 1] % MOD;
}

void solve() {

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