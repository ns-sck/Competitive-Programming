#include <bits/stdc++.h>
using namespace std;

#define int int64_t

constexpr int MAX = 1e5 + 1;
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
  int dec[MAX];
  dec[0] = 1;
  for (int i = 1; i <= MAX; ++i) {
    dec[i] = dec[i - 1] * 10 % MOD;
  } 
  string S;
  cin >> S;
  int N = S.size();
  vector<int> arr(N);
  for (int i = 0; i < N; ++i) {
    arr[i] = S[i] - '0';
  } 
  int ans = 0, k = N, inv = fp(2, MOD - 2);
  reverse(arr.begin(), arr.end());
  for (int i = 0; i < N - 1; ++i) {
    int a = k * (k - 1) % MOD;
    a = a * inv % MOD;
    int z = arr[i] * dec[i] % MOD;
    ans = (ans + z * a) % MOD;
    --k;
  }
  int s = 1, j = 2;
  for (int i = 1; i < N; ++i) {
    ans = (ans + s * arr[i]) % MOD;
    s = (s + dec[j - 1] * (i + 1)) % MOD;
    j++;
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