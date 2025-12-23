#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "templates/debug.h"
#else
#define debug(...) 42
#endif

#define int int64_t
int longestPrefix(vector<int>& arr, int k) {
  map<int, int> mp;
  int n = arr.size();
  for (int i = 0; i < n; ++i) {
    mp[arr[i]] = 1;
  }
  int count = 0;
  for (auto& [x, y] : mp) {
    y = count++;
  }
  vector<int> st(2 * count);
  auto upd = [&](int i, int x) {
    i += count;
    st[i] += x;
    i >>= 1;
    while (i >= 1) {
      st[i] = min(st[2 * i], st[2 * i + 1]);
      i >>= 1;
    }
  };
  auto qry = [&](int l, int r) {
    l += count;
    r += count;
    int ans = 1ll << 30;
    while (l <= r) {
      if (l & 1) {
        ans = min(ans, st[l++]);
      }
      if (~r & 1) {
        ans = min(ans, st[r--]);
      }
      l >>= 1;
      r >>= 1;
    }    
    return ans;
  };
  for (int i = 0; i < n; ++i) {
    upd(mp[arr[i]], 1);
    if (mp[arr[i]] != 0) {
      int mn = qry(0, mp[arr[i]] - 1);
      int ths = qry(mp[arr[i]], mp[arr[i]]);
      if (ths - mn > k) {
        return i;
      }
    }
  }
  return n;
}

void solve() {
  int N, K;
  cin >> N >> K;
  vector<int> arr(N);
  for (int& x : arr) cin >> x;
  cout << longestPrefix(arr, K) << '\n';
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