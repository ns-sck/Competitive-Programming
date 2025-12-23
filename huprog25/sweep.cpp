#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "templates/debug.h"
#else
#define debug(...) 42
#endif

// #define int int64_t

vector<int> satelliteCoverage(vector<vector<int>>& arr, vector<vector<int>>& query) {
  map<int, int> mp;
  int cnt = 0;
  for (auto v : arr) {
    mp[v[0]] = 1;
    mp[v[1]] = 1;
  }
  vector<int> points;
  for (auto& [x, y] : mp) {
    points.push_back(x);
    y = cnt++;
  }
  vector<int> str(cnt), end(cnt);
  auto qq = query;
  sort(arr.begin(), arr.end());
  priority_queue<int, vector<int>, greater<>> pq;
  vector<int> cvr(cnt);
  int q = 0, has = 0, mx = 0;
  for (int i = 0; i < cnt; ++i) {
    while (q < arr.size() && mp[arr[q][0]] <= i) {
      has++;
      str[i]++;
      pq.push(arr[q][1]);
      q++;
    }
    cvr[i] = has;
    while (pq.size() && mp[pq.top()] <= i) {
      pq.pop();
      has--;
      end[i]++;
    }
  }
  for (int i = 0; i < qq.size(); ++i) {
    mx = max(qq[i][1], mx);
  }
  vector<int> st(arr.size() * 2 + 2);
  int n = arr.size();
  auto upd = [&](int i, int x) {
    i += n;
    st[i] = (st[i] + x);
    i >>= 1;
    while (i >= 1) {
      st[i] = max(st[2 * i], st[2 * i + 1]);
      i >>= 1;
    }
  };
  auto qry = [&](int l, int r) {
    l += n;
    r += n;
    int ans = 0;
    while (l <= r) {
      if (l & 1) {
        ans = max(ans, st[l++]);
      }
      if (~r & 1) {
        ans = max(ans, st[r--]);
      }
      l >>= 1;
      r >>= 1;
    }    
    return ans;
  };
  upd(str[0], 1);
  for (int i = 1; i < cnt; ++i) {
    int x = cvr[i] - str[i];
    upd(x, max(0, points[i] - points[i - 1] - 1));
    upd(cvr[i], 1);
  }
  vector<int> ans;
  for (auto v : query) {
    ans.push_back(qry(v[0], v[1]));
  }
  return ans;
}
// 18 5 9 9 2 18 5 18

void solve() {
  int N, M;
  cin >> N >> M;
  vector<vector<int>> arr(N, vector<int>(2)), qry(M, vector<int>(2));
  for (int i = 0; i < N; ++i) {
    cin >> arr[i][0] >> arr[i][1];
  }
  for (int i = 0; i < M; ++i) {
    cin >> qry[i][0] >> qry[i][1];
  }
  for (int& x : satelliteCoverage(arr, qry)) {
    cout << x << ' ';
  }
}

// 3  
// 3 4
// 2 3
// 5 7
// 2  
// 1 3
// 3 3

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