#include <bits/stdc++.h>

#define int long long
#define endl '\n'

using namespace std;

const int MOD = 1e9 + 7;
const int INF = 1e18;

#ifdef LOCAL
#include "templates/debug.h"
#else
#define debug(...) 42
#endif


int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  
  int cnt = 0;
  for (int N = 1000; N < 2000; N += 1) {
    int n = 1900;
    int px = 0, py = 0;
    int val = 0, vmax = INF;
    int c1 = 0, c2 = 0;
    for (int t = 0; t < 1; t++) {
      vector<vector<int>> adj(n);
      for (int i = 1; i < 10; i++) {
        adj[0].push_back(i);
        adj[i].push_back(0);
      }

      mt19937_64 rng((unsigned int)chrono::steady_clock::now().time_since_epoch().count());
      for (int i = 10; i < n; i++) {
        int x = rng() % i, y = rng() % i; 
        adj[i].push_back(x);
        adj[x].push_back(i);
      }

      auto dfs = [&](auto&& self, int from, int parent) -> int {
        int sum = 0;
        for (auto& to : adj[from]) {
          if (to == parent) continue;
          sum += self(self, to, from);
        }
        return sum + 1;
      };
      
      int node = 0, mn = 100000;
      vector<int> bestv;
      for (int i = 0; i < n; ++i) {
        if (adj[i].size() >= 9) {
          vector<int> v;
          for (auto& ng : adj[i]) v.push_back(dfs(dfs, ng, i));
          sort(v.rbegin(), v.rend());
          if (v[0] < mn) {
            bestv = v;
            node = i;
            mn = v[0];
          }
        }
      }
      if (!bestv.size()) {
        continue;
      }
      double d = (double) (bestv[0] + bestv[1]) / (double) bestv[2];
      int mxc = bestv[0];
      int msc = bestv[0] + bestv[1];
      debug(d, mxc, msc);
      if (d <= 7) px++;
      if (msc <= n * 129 / 200) cnt++;
      // if (px > py) cnt++;
    }
  }
  cout << cnt << '\n';

  return 0;
}