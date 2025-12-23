#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "templates/debug.h"
#else
#define debug(...) 42
#endif

#define int int64_t
constexpr int MAX = 1e5 + 1;

vector<int> spf(MAX);
vector<int> prs;

void sieve() {
  for (int i = 2; i < MAX; ++i) {
    if (spf[i] == 0) {
      spf[i] = i;
      prs.push_back(i);
    }
    for (int j = 0; i * prs[j] < MAX; ++j) {
      spf[i * prs[j]] = prs[j];
      if (prs[j] == spf[i]) {
        break;
      }
    }
  }
}

void solve() {
  int N;
  cin >> N;
  int sum = N * (N + 1) / 2;
  vector<int> ans(N);
  set<int> s
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  sieve();
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}