#include <bits/stdc++.h>
using namespace std;

#define int int64_t
constexpr int MOD = 1e9 + 7;
constexpr int MAX = 5e5 + 5;

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

int fact[MAX], inv[MAX];

void init() {
  fact[0] = inv[0] = 1;
  for (int i = 1; i < MAX; ++i) {
    fact[i] = fact[i - 1] * i % MOD;
    inv[i] = fp(fact[i], MOD - 2);
  }
}

int comb(int a, int b) {
  return (fact[a] * inv[a - b] % MOD) * inv[b] % MOD;
}

void solve() {
  int N;
  cin >> N;
  vector<int> arr(N);
  map<int, int> mp;
  for (int& x : arr) {
    cin >> x;
    mp[x]++;
  }
  vector<int> a;
  vector<int> dp(N + 1);
  for (auto [x, y] : mp) {
    a.emplace_back(y);
    // for (int i = 1; i <= y; ++i) {
    //   dp[i] += comb(y, i);
    // }
  }
  map<int, int> memo;
  sort(a.begin(), a.end());
  vector<int> pref = a;
  for (int i = 1; i < a.size(); ++i) {
    pref[i] += pref[i - 1];
  }
  vector<vector<int>> binom(a.size());
  for (int i = 0; i < a.size(); ++i) {
    int t = 0;
    for (int k = 0; k <= a[i]; ++k) {
      t = (t + comb(a[i], k)) % MOD;
      binom[i].emplace_back(t);
    }
  }
  int ans = N * fp(2, N - 1);
  int rmv = 0;
  for (int i = 1; i <= N; ++i) {
    auto it = lower_bound(a.begin(), a.end(), i);
    if (it == a.end()) continue;
    auto idx = it - a.begin();
    int elc = idx ? pref[idx - 1] : 0;
    int aa = 1, bb = 1;
    for (int j = idx; j < a.size(); ++j) {
      aa = aa * binom[j][i - 1] % MOD;
      bb = bb * binom[j][i] % MOD;
    }
    int cc = (bb - aa + MOD) % MOD;
    cc = (cc * fp(2, elc)) % MOD;
    rmv = (rmv + cc * i) % MOD;
  }
  ans = (ans - rmv + MOD) % MOD;
  // 1 1 2
  cout << ans << '\n';
}

signed main () {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  cin >> t;
  init();
  while (t--) {
    solve();
  }
  return 0;
}