#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n; cin >> n;
  vector<int> v(n);
  for (auto& i : v) cin >> i;
  vector<vector<int>> vp(n), vv(n);

  auto Find = [&](int l, int r) -> int {
    int i = lower_bound(vp[r].begin(), vp[r].end(), l) - vp[r].begin();
    return vv[r][i];
  };
  vector<int> cnt(n + 1), pos(n+1);
  cnt[v[0]]=1;
  pos[v[0]]=0;
  cnt[v[1]] = 1;
  pos[v[1]] = 1;
  vp[1].push_back(1 - 1);
  vv[1].push_back(abs(v[1] - v[i - 1]));
  for (int i = 2; i < n; i++) {
    cnt[v[i]]=1;
    pos[v[i]]=i;
    vp[i].push_back(i - 1);
    vv[i].push_back(abs(v[i] - v[i - 1]));
    int opt = vv[i].back();
    for (int j = i - 2; j >= 0 && opt > 100; j--) {
      int val = min(Find(j, i - 1), abs(v[j] - v[i]));
      if (val < vv[i].back()) {
        vp[i].push_back(j);
        vv[i].push_back(val);
        opt = val;
      }
    }
    vector<pair<int, int>> a;
    for (int i = opt; i >= 1; i--) {
      if ((v[i] - i > 0 && cnt[v[i] - i])) {
        while (a.size() && pos[v[i] - i] > a.back().first) a.pop_back();
        a.push_back({pos[v[i] - i], i});
      }
      else if ((v[i] + i <= n && cnt[v[i] + i])) {
        while (a.size() && pos[v[i] + i] > a.back().first) a.pop_back();
        a.push_back({pos[v[i] + i], i});
      }
    }
    for (auto& [l, r] : a) {
      vp[i].push_back(l);
      vv[i].push_back(r);
    }


    reverse(vp[i].begin(), vp[i].end());
    reverse(vv[i].begin(), vv[i].end());
  }

  int q; cin >> q;
  while (q--) {
    int l, r; cin >> l >> r;
    l--; r--;
    cout << Find(l, r) << '\n';
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