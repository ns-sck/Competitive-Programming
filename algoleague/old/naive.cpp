#include <bits/stdc++.h>
using namespace std;

#define int int64_t

constexpr int MAX = 2e5 + 1;

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
  int N;
  cin >> N;
  vector<int> arr{1};
  for (int i = 0; i < N; ++i) {
    int x;
    cin >> x;
    arr.emplace_back(x);
  }
  vector<int> dp(N + 1);
  for (int i = 1; i <= N; ++i) {
    dp[i] = dp[i - 1];
    for (int j = 1; j < i; ++j) {
      int x = __gcd(arr[i], arr[j]);
      int c = 0;
      while (x > 1) {
        int y = spf[x];
        while ((x % y) == 0) x /= y;
        ++c;
      }
      dp[i] = max(dp[i], dp[j - 1] + c);
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