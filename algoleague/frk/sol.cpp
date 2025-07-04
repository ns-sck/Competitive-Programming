#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "templates/debug.h"
#else
#define debug(...) 42
#endif

#define int int64_t

void solve() {
  int N;
  cin >> N;
  stack<int> st;
  for (int i = 0; i < N; ++i) {
    int x;
    cin >> x;
    if (st.size() && st.top() == x) {
      st.pop();
    } else {
      st.push(x);
    }
  }
  cout << st.size() << '\n';
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