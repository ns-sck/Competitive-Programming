#include <bits/stdc++.h>
using namespace std;

#define int int64_t

constexpr int MAX = 4e4 + 1;

vector<int> spf(MAX);
vector<int> prs;

void sieve() {
  for (int i = 2; i < MAX; ++i) {
    if (spf[i]) {
      continue;
    }
    spf[i] = i;
    prs.emplace_back(i);
    for (int j = i * i; j < MAX; j += i) {
      if (!spf[j]) {
        spf[j] = i;
      }
    }
  }
}

void solve() {
  int N, K;
  cin >> N >> K;
  vector<int> arr{1};
  vector<int> prev(N + 1);
  vector<vector<int>> prfs(N + 1);
  for (int i = 1, one = 0; i <= N; ++i) {
    int x;
    cin >> x;
    arr.emplace_back(x);
    if (x == 1) one = i;
    prev[i] = one;
    for (int& p : prs) {
      if (p * p > x) break;
      if (x % p) continue;
      while (x % p == 0) x /= p;
      prfs[i].emplace_back(p);
    }
    if (x > 1) prfs[i].emplace_back(x);
  }
  vector<int> dp(N + 1);
  map<int, int> last;
  vector<vector<int>> upd(N + 1);
  for (int i = 1; i <= N; ++i) {
    if (i >= K) {
      int j = i - K + 1;
      for (int& y : upd[j]) {
        last[y] = j;
      }
    }
    int x = arr[i];
    dp[i] = dp[i - 1];
    int sz = prfs[i].size();
    for (int j = 1; j < (1 << sz); ++j) {
      int mul = 1;
      for (int k = 0; k < sz; ++k) {
        if ((1 << k) & j) {
          mul *= prfs[i][k];
        }
      }
      if (i >= K && last[mul] > prev[i]) {
        dp[i] = max(dp[i], dp[last[mul] - 1] + __builtin_popcount(j));
      }
      upd[i].emplace_back(mul);
    }
  }
  cout << dp[N] << '\n';
}


signed main () {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  sieve();
  // cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}