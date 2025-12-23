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
  vector<bool> vis(1 << N);
  vector<int> ans;
  ans.push_back((1 << N) - 1);
  ans.push_back(ans[0] >> 1);
  int b = N - 2;
  int y = 2;
  vis[ans[0]] = vis[ans[1]] = 1;
  while (b >= 1) {
    int x = (1 << b) - 1;
    for (int i = 0; i < y; ++i) {
      int z = x | (i << (b + 1));
      ans.push_back(z);
      vis[z] = 1;
    }
    b--;
    y <<= 1;
  }
  for (int i = 0; i < (1 << N); ++i) {
    if (!vis[i]) ans.push_back(i);
  }
  for (int& x : ans) {
    cout << x << " \n"[x == ans.back()];
  }
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}