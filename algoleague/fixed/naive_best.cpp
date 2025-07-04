#include <bits/stdc++.h>
using namespace std;

#define int int64_t

constexpr int MAX = 5e4 + 1;

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
  vector<int> dp(N + 1), dp2(N + 1, -1);
  for (int i = 1; i <= N; ++i) {
    int x;
    cin >> x;
    arr.emplace_back(x);
  }
  for (int i = 1; i <= N; ++i) {
    for (int j = i - K + 1; j; --j) {
      int z = __gcd(arr[i], arr[j]), cnt = 0;
      while (z > 1 && dp2[z] == -1) {
        for (int& p : prs) {
        if (p * p > z) break;
        if (z % p) continue;
        while (z % p == 0) z /= p;
        ++cnt;
       }
      }
      if (z > 1) ++cnt;
      if (dp2[z] == -1) dp2[z] = cnt;
      dp[i] = max(dp[i], dp2[z] + dp[j - 1]);
    }
  }
  cout << dp[N] << '\n';
}

signed main () {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  sieve();
  int t = 1;
  // cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}