#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "templates/debug.h"
#else
#define debug(...) 42
#endif

#define int int64_t

int solve(string s, int K) {
  int ans = 0;
  int n = s.size();
  set<int> st;
  map<int, int> mp;
  for (int i = 0; i < n; ++i) {
    if (s[i] == '1') {
      st.insert(i);
      mp[i] = K;
    }
  }
  for (int i = 0; i < n; ++i) {
    if (s[i] == '1') continue;
    auto it = st.lower_bound(i - K);
    if (it == st.end() || *it > i + K) {
      continue;
    }
    s[i] = '1';
    if (--mp[*it] == 0) {
      st.erase(it);
    }
  }
  debug(s);
  return count(s.begin(), s.end(), '1');
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  // cin >> t;
  string s;
  int k;
  cin >> s >> k;
  while (t--) {
    cout << solve(s, k);
  }
  return 0;
}