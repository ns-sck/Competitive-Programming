#include <bits/stdc++.h>
using namespace std;

#define int int64_t

constexpr int MAX = 1e6 + 1;

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
  vector<int> last(MAX);
  for (int i = 1; i <= N; ++i) {
    int x = arr[i];
    vector<int> pdivs;
    vector<int> upd;
    while (x > 1) {
      int d = spf[x];
      while (x % d == 0) x /= d;
      pdivs.emplace_back(d);
    }
    int sz = pdivs.size();
    for (int j = 0; j < (1 << sz); ++j) {
      int mul = 1;
      for (int k = 0; k < sz; ++k) {
        if ((1 << k) & j) {
          mul *= pdivs[k];
        }
      }
      if (last[mul]) {
        dp[i] = max(dp[i], dp[last[mul] - 1] + __builtin_popcount(j));
      }
      upd.emplace_back(mul);
    }
    for (int& x : upd) last[x] = i;
    if (i) dp[i] = max(dp[i], dp[i - 1]);
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