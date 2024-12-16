#include <bits/stdc++.h>
using namespace std;

#define int int64_t
constexpr int MAX = 1e6 + 1;

vector<int> spf(MAX);
vector<int> prs;
int dp[MAX], num[MAX];

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
  int ans = 0;
  vector<int> arr(N);
  for (int i = 0; i < N; ++i) {
    cin >> arr[i];
    ++num[arr[i]];
  }
  for (int i = 0; i < N; ++i) {
    vector<int> divs;
    int a = arr[i];
    while (a > 1) {
      int p = spf[a];
      for (; a % p == 0; a /= p);
      divs.emplace_back(p);
    }
    int s = divs.size(), cnt = 0;
    for (int j = 1; j < (1 << s); ++j) {
      int prod = 1;
      for (int k = 0; k < s; ++k) {
        if ((j >> k) & 1) {
          prod *= divs[k];
        }
      }
      if (__builtin_popcount(j) & 1) {
        cnt += dp[prod]++;
      } else {
        cnt -= dp[prod]++;
      }
    }
    ans += i - cnt;
  }
  cout << ans << '\n';
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