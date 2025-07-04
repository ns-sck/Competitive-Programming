#include <bits/stdc++.h>
using namespace std;

#define int int64_t
constexpr int MAX = 1e6 + 2337;
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
  int N, M;
  cin >> N >> M;
  sieve();
  int ans = 0;
  for (int i = 0; i < prs.size(); ++i) {
    if (prs[i] > N) break; 
    int j = lower_bound(prs.begin(), prs.end(), prs[i] - M) - prs.begin();
    while (j <= i) {
      int k = lower_bound(prs.begin(), prs.end(), min({N + 1, prs[i] + M + 1, prs[j] + prs[i]})) - prs.begin();
      --k;
      ans += max(0ll, k - i + 1);
      j++;
    }
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