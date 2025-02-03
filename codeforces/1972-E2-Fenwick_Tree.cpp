#include <bits/stdc++.h>
using namespace std;

#define int int64_t

constexpr int MOD = 998244353;

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

int comb[100];

void init(int n, int k) {
  comb[0] = 1;
  for (int i = 1; i <= 100; ++i) {
    comb[i] = comb[i - 1] * (k++ * fp(i, MOD - 2) % MOD) % MOD;
  }
}

void solve() {
  int N, K;
  cin >> N >> K;
  init(N, K);
  vector<int> arr(N + 1), ans(N + 1);
  vector<vector<pair<int, int>>> child(N + 1);
  for (int i = 1; i <= N; ++i) {
    cin >> arr[i];
    if (i & 1) ans[i] = arr[i];
    int x = i + (i & -i), j = 1;
    while (x <= N) {
      child[x].emplace_back(i, j++);
      x += x & -x;
    }
  }
  for (int i = 2; i <= N; i += 2) {
    int sum = 0;
    for (auto& [x, y] : child[i]) {
      sum = (sum + ans[x] * comb[y]) % MOD;
    }
    ans[i] = (arr[i] - sum + MOD) % MOD;
  }
  for (int i = 1; i <= N; ++i) {
    cout << ans[i] << " \n"[i == N];
  }
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