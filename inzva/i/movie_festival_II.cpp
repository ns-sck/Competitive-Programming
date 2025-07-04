#include <bits/stdc++.h>
using namespace std;

#define int int64_t

// https://cses.fi/problemset/task/1632

void solve() {
  int N, K;
  cin >> N >> K;
  vector<pair<int, int>> mv;
  for (int i = 0; i < N; ++i) {
    int l, r;
    cin >> l >> r;
    mv.emplace_back(r, l);
  }  
  // sort by ending times
  sort(mv.begin(), mv.end());
  int ans = 0, left = 0;
  multiset<int> s;
  for (int i = 0; i < N; ++i) {
    int start = mv[i].second;
    // to get an ending time <= start,
    // we first call upper_bound to find smallest ending time
    // which is > start, get one previous ending time
    auto it = s.upper_bound(start);
    if (it == s.begin()) {
      // if the result of the upper_bound operation is actually
      // the first element among current processing intervals
      // we can consider this interval only if there are some people not working
      if (s.size() < K) {
        s.insert(mv[i].first);
        ++ans;
      }
      continue;
    }
    // erase previous element of the result of upper_bound
    // this guarantees that it ends before current interval starts
    s.erase(--it);
    s.insert(mv[i].first);
    ++ans;
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