#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "templates/debug.h"
#else
#define debug(...) 42
#endif

// #define int int64_t

int cntWays(int n, vector<int>& large, int m, vector<int>& small) {
  const int MOD = 1e9 + 7;
  vector<pair<int, int>> srt;
  for (int i = 0; i < n; ++i) {
    srt.push_back({large[i], i});
  }
  sort(srt.begin(), srt.end());
  map<int, int> mp;
  for (int i = 0; i < n; ++i) {
    mp[srt[i].second] = i;
  }
  vector<int> st(2 * n);
  auto upd = [&](int i, int x) {
    i += n;
    st[i] = (st[i] + x) % MOD;
    i >>= 1;
    while (i >= 1) {
      st[i] = (st[2 * i] + st[2 * i + 1]) % MOD;
      i >>= 1;
    }
  };
  auto qry = [&](int l, int r) {
    l += n;
    r += n;
    int ans = 0;
    while (l <= r) {
      if (l & 1) {
        ans = (ans + st[l++]) % MOD;
      }
      if (~r & 1) {
        ans = (ans + st[r--]) % MOD;
      }
      l >>= 1;
      r >>= 1;
    }    
    return ans;
  };
  for (int i = 0; i < n; ++i) {
    upd(i, 1);
  }
  for (int j = 1; j < m; ++j) {
    vector<int> hold(2 * n);
    for (int i = j; i < n; ++i) {
      hold[mp[i]] = st[mp[i] + n];
      upd(mp[i], -st[mp[i] + n]);
    }
    vector<int> nst(2 * n);
    for (int i = j; i < n; ++i) {
      int diff = small[j] - small[j - 1];
      int need = large[i] + diff;
      int idx = upper_bound(srt.begin(), srt.end(), make_pair(need, 1 << 30)) - srt.begin();
      if (idx) {
        idx--;
        int has = qry(0, idx);
        nst[mp[i]] =  (nst[mp[i]] + has) % MOD;
      }
      upd(mp[i], hold[mp[i]]);
    }
    st = vector<int>(2 * n);
    for (int i = 0; i < n; ++i) {
      upd(i, nst[i]);
    }
  }
  return qry(0, n - 1);
}

void solve() {
  int N, M;
  cin >> N >> M;
  vector<int> a(N), b(M);
  for (int& x : a) cin >> x;
  for (int& x : b) cin >> x;
  cout << cntWays(N, a, M, b) << '\n';
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