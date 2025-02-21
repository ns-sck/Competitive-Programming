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
  int Q;
  cin >> Q;
  while (Q--) {
    int a;
    cin >> a;
    int ans = 1, c = 0;
    while (a > 1) {
      int p = spf[a];
      while (a % p == 0) {
        a /= p;
        ++c;
      }
      ans *= c + 1;
      c = 0;
    }
    cout << ans << '\n';
  }
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