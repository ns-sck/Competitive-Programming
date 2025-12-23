#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

#ifdef LOCAL
#include "templates/debug.h"
#else
#define debug(...) 42
#endif

const int MOD = 1e9 + 7;
const int INF = 1e18;


int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n, k;
  cin >> n >> k;
  vector<int> v(n);
  for (auto& i : v) cin >> i;
  vector<vector<int>> adj(n);
  for (int i = 1; i < n; i++) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  int ans = 0;
  int val = -1;
  vector<bool> vis(n);
  
  auto Dfs = [&](auto&& self, int from, int parent) -> int {
    int sum = 1;
    for (auto& to : adj[from]) {
      if (to == parent || vis[to]) continue;
      if (v[to] > val || v[to] < val - k) continue;
      sum = sum * (1 + self(self, to, from)) % MOD;
    }
    return sum;
  };

  vector<int> ind(n);
  iota(ind.begin(), ind.end(), 0);
  sort(ind.begin(), ind.end(), [&](int a, int b){return v[a] > v[b];});

  for (auto& i : ind) {
    val = v[i];
    int sum = Dfs(Dfs, i, -1);
    if (k == 0) {
      ans = (ans + sum) % MOD;
      vis[i] = 1;
      continue;
    }
    k--;
    sum -= Dfs(Dfs, i, -1);
    k++;
    ans = (ans + sum + MOD) % MOD;
    vis[i] = 1;
  }
  cout << ans;

  return 0;
}