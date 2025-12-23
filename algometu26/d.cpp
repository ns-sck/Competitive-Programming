#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "templates/debug.h"
#else
#define debug(...) 42
#endif

#define int int64_t
int N;

void solve() {
  vector<vector<int>> adj(N);
  for (int i = 0; i < N; ++i) {
    int p;
    cin >> p;
    if (~p) {
      p--;
      adj[i].push_back(p);
      adj[p].push_back(i);
    }
  }
  double r = 0;
  int cur = 0;
  vector<int> sz;
  auto dfs = [&](auto&& self, int from, int parent) -> int {
    int sum = 0;
    for (auto& to : adj[from]) {
      if (to == parent) continue;
      sum += self(self, to, from);
    }
    return sum + 1;
  };
  vector<int> bestv;
  int mn = 10000;
  for (int i = 0; i < N; ++i) {
    if (adj[i].size() >= 9) {
      vector<int> v;
      for (auto& ng : adj[i]) v.push_back(dfs(dfs, ng, i));
        sort(v.rbegin(), v.rend());
        if (v[0] < mn) {
          bestv = v; 
          mn = v[0];
        }
      }
    }
    int cnt = bestv.size() ? bestv[0] + bestv[1] : 0;
    debug(bestv);
    bool pp = bestv.size() && cnt <= N * 129 / 200;
    if (pp) cout << "Blueberry\n";
    else cout << "Strawberry\n";
  }

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  cin >> t;
  cin >> N;
  while (t--) solve();
  return 0;
}