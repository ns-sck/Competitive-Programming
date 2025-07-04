#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "templates/debug.h"
#else
#define debug(...) 42
#endif

#define int int64_t

void solve() {
  int K;
  cin >> K;
  assert(3 <= K <= 10);
  string S, T;
  cin >> S >> T;
  assert(S.size() == K);
  assert(T.size() == K);
  int N;
  cin >> N;
  assert(1 <= N <= 5e4);
  vector<vector<int>> adj(N + 2);
  map<string, int> mp;
  vector<int> dis(N + 2, 1 << 30);
  mp[S] = 0, mp[T] = N + 1;
  while (N--) {
    string s;
    cin >> s;
    assert(s.size() == K);
    mp[s] = N + 1;
    string x = s;
    for (int i = 0; i < K; ++i) {
      x[i] = '$';
      if (mp.count(x)) {
        adj[mp[x]].push_back(N + 1);
        adj[N + 1].push_back(mp[x]);
      }
    }
  }
  queue<pair<int, int>> que;
  que.push({0, 0});
  debug(mp);
  debug(adj);
  while (que.size()) {
    auto [s, d] = que.front();
    debug(s, d);
    que.pop();
    if (dis[s] <= d) continue;
    dis[s] = d;
    for (auto& x : adj[s]) {
      if (dis[x] > d + 1) {
        que.push({x, d + 1});
      }
    }
  }
  if (dis[mp[T]] == 1 << 30) dis[mp[T]] = -1;
  cout << dis[mp[T]] << '\n'; 
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