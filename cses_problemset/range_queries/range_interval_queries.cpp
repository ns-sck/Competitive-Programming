#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "templates/debug.h"
#else
#define debug(...) 42
#endif

template <typename T>
struct BIT {
  std::vector<T> bit;
  int n;
  BIT(T size) {
    n = size;
    bit.assign(n + 1, 0);
  }

  void update(int idx, T delta) {
    assert(1 <= idx <= n);
    while (idx <= n) {
      bit[idx] += delta;
      idx += idx & -idx;
    }
  }

  T query(int idx) {
    assert(1 <= idx <= n);
    T sum = 0;
    while (idx > 0) {
      sum += bit[idx];
      idx -= idx & -idx;
    }
    return sum;
  }

  T range(int l, int r) {
    return query(r) - query(l - 1);
  }
};

void solve() {
  int N, Q;
  cin >> N >> Q;
  vector<int> arr(N);
  map<int, int> mp;
  for (int i = 0; i < N; ++i) {
    cin >> arr[i];
    mp[arr[i]] = 1;
  }
  int c = 2;
  for (auto& [x, y] : mp) {
    y = c++;
  }
  mp[1] = 1, mp[N + 2] = N + 2;
  vector<array<int, 5>> qrs(Q), rev(Q);
  for (int i = 0; i < Q; ++i) {
    cin >> qrs[i][2] >> qrs[i][3] >> qrs[i][0] >> qrs[i][1];
    qrs[i][4] = i;
    qrs[i][0] = mp.lower_bound(qrs[i][0])->first;
    qrs[i][1] = prev(mp.upper_bound(qrs[i][1]))->first;
    rev[i] = qrs[i];
    swap(rev[i][0], rev[i][1]);
  }
  BIT<int> bit(N + 3);
  vector<vector<int>> vals(N + 3);
  for (int i = 0; i < N; ++i) {
    arr[i] = mp[arr[i]];
    bit.update(i + 1, 1);
    vals[arr[i]].push_back(i + 1);
  }
  auto bit2 = bit;
  sort(qrs.begin(), qrs.end());
  sort(rev.rbegin(), rev.rend());
  vector<int> ans(Q);
  int v = 0;
  for (auto& [c, d, a, b, i] : qrs) {
    c = mp[c], d = mp[d];
    while (v < c) {
      for (int& x : vals[v]) {
        bit.update(x, -1);
      }
      v++;
    }
    ans[i] += bit.range(a, b);
  }
  v = N + 2;
  for (auto& [d, c, a, b, i] : rev) {
    c = mp[c], d = mp[d];
    while (v > d) {
      for (int& x : vals[v]) {
        bit2.update(x, -1);
      }
      v--;
    }
    ans[i] += bit2.range(a, b);
  }
  for (int i = 0; i < Q; ++i) {
    ans[qrs[i][4]] -= qrs[i][3] - qrs[i][2] + 1;
  }
  for (int i = 0; i < Q; ++i) {
    cout << ans[i] << '\n';
  }
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