#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "templates/debug.h"
#else
#define debug(...) 42
#endif

#define int int64_t

void solve() {
  int N, Q;
  cin >> N >> Q;
  assert(1 <= N <= 1e5);
  assert(1 <= Q <= 1e5);
  vector<int> arr(N);
  map<int, vector<int>> mp;
  for (int i = 0; i < N; ++i) {
    cin >> arr[i];
    assert(1 <= arr[i] <= 1e9);
    mp[arr[i]].push_back(i);
  }
  vector<int> sin(N + 1), dou(N + 1), sub(N + 1);
  for (auto& [x, v] : mp) {
    for (int i = 0; i < v.size(); ++i) {
      if (i == v.size() - 1) {
        sin[1]++;
        sin[N - v[i]]--;
      }
      if (i == 0) {
        sin[1]++;
        sin[v[i] + 1]--;
      } else {
        int d = v[i] - v[i - 1];
        dou[1]++;
        dou[d / 2 + 1]--;
        if (~d & 1) sub[d / 2]++;
      }
      debug(sin);
      debug(dou);
      debug(sub);
    }
  }
  vector<int> ans(N + 1);
  int s = 0, sc = 0, d = 0, dc = 0;
  for (int i = 0; i <= N; ++i) {
    sc += sin[i];
    dc += dou[i];
    s += sc;
    d += dc * 2;
    if (i) sub[i] += sub[i - 1];
    ans[i] = s + d - sub[i]; 
  }
  while (Q--) {
    int x;
    cin >> x;
    x = min(x, N);
    // int nv = 0;
    // for (int i = 0; i < N; ++i) {
    //   set<int> s = {arr[i]};
    //   for (int j = 1; j <= x; ++j) {
    //     if (i - j >= 0) s.emplace(arr[i - j]);
    //     if (i + j < N) s.emplace(arr[i + j]);
    //   }
    //   nv += s.size();
    // }
    // cout << nv << '\n';
    cout << N + ans[x] << '\n';
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