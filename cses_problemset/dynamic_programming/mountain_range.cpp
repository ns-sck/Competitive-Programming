#include <bits/stdc++.h>
using namespace std;

#define int int64_t

void solve() {
  int N;
  cin >> N;
  vector<int> arr(N);
  vector<vector<int>> adj(N,vector<int>());
  int mx = 0;
  for (int j = 0; j < 2; ++j) {
    multiset<pair<int, int>> ms;
    for (int i = 0; i < N; ++i) {
      mx = max(mx, arr[i]);
      if (!j) cin >> arr[i];
      auto it = ms.lower_bound({arr[i] + 1, 0});
      if (it != ms.end()) {
        if (j) {
          adj[N - 1 - it->second].push_back(N - 1 - i);
        } else {
          adj[it->second].push_back(i);
        }
      }
      it = ms.begin();
      vector<multiset<pair<int, int>>::iterator> del;
      while (it != ms.end() && it->first <= arr[i]) {
        del.push_back(it);
        it++;
      } 
      for (auto x : del) {
        ms.erase(x);
      }
      ms.insert({arr[i], i});
    }
    reverse(arr.begin(), arr.end());
  }
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
  for (int i = 0; i < N; ++i) {
    if (arr[i] == mx) {
      pq.push({1, i});
    }
  }
  vector<int> dis(N);
  while (pq.size()) {
    auto [d, i] = pq.top();
    pq.pop();
    if (dis[i] > d) continue;
    dis[d] = d;
    for (int& j : adj[i]) {
      if (d + 1 > dis[j]) {
        pq.push({d + 1, j});
        dis[j] = d + 1;
      }
    }
  }
  cout << *max_element(dis.begin(), dis.end()) << '\n';
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