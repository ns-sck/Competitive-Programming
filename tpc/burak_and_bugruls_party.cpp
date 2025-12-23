#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "templates/debug.h"
#else
#define debug(...) 42
#endif

#define int int64_t
constexpr int MAX = 1e3;

void solve() {
  // n^2 soln
  int N;
  cin >> N;
  assert(1 <= N <= MAX);
  vector<int> a_cnt(MAX), b_cnt(MAX), cnt(MAX);
  for (int i = 0; i < N; ++i) {
    int x;
    cin >> x;
    assert(1 <= x <= MAX);
    a_cnt[x]++;
  }
  for (int i = 0; i < N; ++i) {
    int x;
    cin >> x;
    assert(1 <= x <= MAX);
    b_cnt[x]++;
  }
  for (int i = 0; i <= MAX; ++i) {
    cnt[i] = min(a_cnt[i], b_cnt[i]);
  }
  for (int i = 0; i <= MAX; ++i) {
    for (int j = 0; j <= MAX; ++j) {
      if (i == j) {
        continue;
      }
      if (cnt[i] && cnt[j]) {
        --cnt[i];
        --cnt[j];
      }
    }
  }
  int ans = N;
  for (int i = 0; i <= MAX; ++i) {
    ans -= cnt[i];
  }
  cout << ans << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  // cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}